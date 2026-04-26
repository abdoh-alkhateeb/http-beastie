#include <boost/beast/http.hpp>
#include <fstream>
#include <sstream>
#include <string>

namespace http = boost::beast::http;

std::string read_file(const std::string& path) {
    std::ifstream file(path);
    std::stringstream buffer;

    if (!file.is_open()) {
        return "<h1>404 Not Found</h1>";
    }

    buffer << file.rdbuf();
    return buffer.str();
}

http::response<http::string_body> handle_request(
    const http::request<http::string_body>& req)
{
    http::response<http::string_body> res;

    res.version(req.version());
    res.set(http::field::server, "Beast");
    res.set(http::field::content_type, "text/html");
    res.keep_alive(req.keep_alive());

    if (req.method() == http::verb::get && req.target() == "/") {
        res.result(http::status::ok);
        res.body() = read_file("static/index.html");
    } 
    else if (req.method() == http::verb::get && req.target() == "/elreedy") {
        res.result(http::status::ok);
        res.body() = read_file("static/elreedy.html");
    } 
    else {
        res.result(http::status::not_found);
        res.body() = "<h1>404 Not Found</h1>";
    }

    res.prepare_payload();
    return res;
}
