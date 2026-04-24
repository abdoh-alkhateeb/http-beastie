#include "utils.hpp"

namespace beast = boost::beast;
namespace http = beast::http;

http::response<http::string_body> handle_request(const http::request<http::string_body>& req) {
  http::response<http::string_body> res;

  res.version(req.version());
  res.set(http::field::server, "http-beastie");
  res.set(http::field::content_type, "text/html");

  if (req.method() == http::verb::get && req.target() == "/") {
    res.result(http::status::ok);
    res.body() = "<h1 style=\"text-align: center;\">CSCE 1102</h1>";
  } else {
    res.result(http::status::not_found);
    res.body() = "<h1 style=\"text-align: center;\">404 Not Found</h1>";
  }

  res.prepare_payload();
  return res;
}
