#include "utils.hpp"

#include <fstream>
#include <string>

namespace beast = boost::beast;
namespace http = beast::http;

std::string read_file(std::string file_name) {
  std::string output = "";
  std::ifstream file(file_name);
  if (file.is_open()) {
    std::string line = "";
    while (getline(file, line)) {
      output += line + "\n";
    }
    file.close();
  }

  return output;
}

http::response<http::string_body> handle_request(const http::request<http::string_body>& req) {
  http::response<http::string_body> res;

  res.version(req.version());
  res.keep_alive(false);

  res.set(http::field::server, "http-beastie");
  res.set(http::field::content_type, "text/html");

  if (req.method() == http::verb::get) {
    if (req.target() == "/") {
      res.result(http::status::ok);
      res.body() = read_file("static/index.html");
    } else if (req.target() == "/dawoud") {
      res.result(http::status::ok);
      res.body() = read_file("static/dawoud.html");
    } else if (req.target().starts_with("/static/")) {
      // the html I'm using loads images so I needed to make the server actually send them
      std::string path = "." + std::string(req.target());

      if (path.ends_with(".jpeg") || path.ends_with(".jpg")) {
        res.set(http::field::content_type, "image/jpeg");
      }

      res.result(http::status::ok);
      res.body() = read_file(path);
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
