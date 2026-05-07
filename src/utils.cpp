#include "utils.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
using namespace std;

namespace beast = boost::beast;
namespace http = beast::http;

string utility (const string& filepath) {
  ifstream file(filepath);
  if (!file.is_open()) {
    cerr << "Error: Could not open file " << filepath << endl;
    return "";
  }
  string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
  return content;
}

http::response<http::string_body> handle_request(const http::request<http::string_body>& req) {
  http::response<http::string_body> res;

  res.version(req.version());
  res.keep_alive(false);

  res.set(http::field::server, "http-beastie");
  res.set(http::field::content_type, "text/html");

  if (req.method() == http::verb::get) {
    if (req.target() == "/") {
      string file_content = utility("static/index.html");
      res.result(http::status::ok);
      res.body() = file_content;
    } else if (req.target() == "/abdelaal") {
      string file_content = utility("static/abdelaal.html");
      res.result(http::status::ok);
      res.body() = file_content;
    } else {
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
