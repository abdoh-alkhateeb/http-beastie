#include "utils.hpp"

#include <fstream>
#include <sstream>

namespace beast = boost::beast;
namespace http = beast::http;

// Step d: Utility function to read file content into a string
std::string read_file(const std::string& file_path) {
  std::ifstream file(file_path);
  if (!file.is_open()) return "<h1>404 Not Found</h1>";
  std::stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}

http::response<http::string_body> handle_request(
    const http::request<http::string_body>& req) {
  http::response<http::string_body> res;
  res.version(req.version());
  res.set(http::field::server, "http-beastie");
  res.set(http::field::content_type, "text/html");

  // Step e
  if (req.method() == http::verb::get && req.target() == "/") {
    res.result(http::status::ok);
    res.body() = read_file("static/index.html");

    // Step f
  } else if (req.method() == http::verb::get && req.target() == "/Abuelalla") {
    res.result(http::status::ok);
    res.body() = read_file("static/Abuelalla.html");

    // Catch fallback for unrecognized URLs
  } else {
    res.result(http::status::not_found);
    res.body() = "<h1 style=\"text-align: center;\">404 Not Found</h1>";
  }

  res.prepare_payload();
  return res;
}
