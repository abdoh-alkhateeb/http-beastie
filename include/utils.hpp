#pragma once
#include <string>
#include <boost/beast/http.hpp>
std::string getContents(const std::string& path);
boost::beast::http::response<boost::beast::http::string_body> handle_request(const boost::beast::http::request<boost::beast::http::string_body>& req);
