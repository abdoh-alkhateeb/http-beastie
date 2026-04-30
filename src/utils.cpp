#include "utils.hpp"
#include <fstream>
namespace beast = boost::beast;
namespace http = beast::http;

std::string read_file(const std::string& path){
	std::ifstream file(path);
	std::string line;
	std::string content;

	while(std::getline(file, line)){
	content+=line + "\n";}
	return content;}

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
