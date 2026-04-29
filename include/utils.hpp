#pragma once

#include <boost/beast/http.hpp>
#include <fstream>

boost::beast::http::response<boost::beast::http::string_body> handle_request(const boost::beast::http::request<boost::beast::http::string_body>& req);

std::string FileTOString(std::string Path);