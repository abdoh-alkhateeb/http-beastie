#include "utils.hpp"


namespace beast = boost::beast;
namespace http = beast::http;

std::string FileTOString(std::string Path){
  std::ifstream File;
  File.open(Path);
  if(!File.is_open()){
    return "File not found.";
  }
  std::string Line;
  std::string Result;
  while(std::getline(File, Line)){
    Result += Line + "\n";  
  }
  File.close();
  return Result;
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
      res.body() = FileTOString("static/index.html");
    } else if(req.target() == "/Sameh") {
      res.result(http::status::ok);
      res.body() = FileTOString("static/Sameh.html");
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
