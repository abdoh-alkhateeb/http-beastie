#include "utils.hpp"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

namespace beast = boost::beast;
namespace http = beast::http;

string read_file(const string& file_path) {
    ifstream file(file_path);

    if (!file.is_open()) {
        return "";
    }

    stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

http::response<http::string_body> handle_request(const http::request<http::string_body>& req) {
  http::response<http::string_body> res;

  res.version(req.version());
  res.keep_alive(false);

  res.set(http::field::server, "http-beastie");
  res.set(http::field::content_type, "text/html");

  if (req.method() == http::verb::get) {


   if (req.target() == "/hashem") {
    string body = read_file("../static/hashem.html");

    if (body.empty()) {
      res.result(http::status::not_found);
      res.body() = "<h1>404 Not Found</h1>";
    } else {
      res.result(http::status::ok);
      res.body() = body;
    }
 } 

 else if (req.target() == "/") {
  string body = read_file("../static/index.html");

    if (body.empty()) {
      res.result(http::status::not_found);
      res.body() = "<h1>404 Not Found</h1>";
    } else {
      res.result(http::status::ok);
      res.body() = body;
    }
 } 

 else {
      res.result(http::status::not_found);
      res.body() = "<h1 style=\"text-align: center;\">404 Not Found</h1>";
    }
  } else {
    res.result(http::status::method_not_allowed);
    res.set(http::field::allow, "GET");
    res.body() = "<h1 style=\"text-align: center;\">405 Method Not Allowed</h1>";
  }

  res.prepare_payload();
  return res;
}
