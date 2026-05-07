#include "utils.hpp"

#include <boost/beast/http.hpp>

#include <fstream>
#include <sstream>

namespace beast = boost::beast;
namespace http = beast::http;

std::string read_file(const std::string& path) {

    std::ifstream file(path);

    std::ostringstream buffer;

    buffer << file.rdbuf();

    return buffer.str();
}

http::response<http::string_body>
handle_request(
    const http::request<http::string_body>& req) {

    http::response<http::string_body> res;

    res.version(req.version());

    res.keep_alive(false);

    res.set(http::field::server, "http-beastie");

    if (req.method() == http::verb::get) {

        if (req.target() == "/") {

            res.result(http::status::ok);

            res.set(
                http::field::content_type,
                "text/html");

            res.body() =
                read_file("static/index.html");

        } else if (req.target() == "/maghoula") {

            res.result(http::status::ok);

            res.set(
                http::field::content_type,
                "text/html");

            res.body() =
                read_file("static/maghoula.html");

        } else {

            res.result(http::status::not_found);

            res.set(
                http::field::content_type,
                "text/html");

            res.body() =
                "<h1>404 Not Found</h1>";
        }

    } else {

        res.result(
            http::status::method_not_allowed);

        res.body() =
            "<h1>405 Method Not Allowed</h1>";
    }

    res.prepare_payload();

    return res;
}
