#pragma once

#include <boost/beast/http.hpp>

boost::beast::http::response<boost::beast::http::string_body> handle_request(const boost::beast::http::request<boost::beast::http::string_body>& req);
std::string file_to_string(const std::string& path);
