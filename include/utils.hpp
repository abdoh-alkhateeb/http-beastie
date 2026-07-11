#pragma once
#include <boost/beast/http.hpp>
#include <string>

//  the minimal function to read files
std::string read_file(const std::string& file_path);

boost::beast::http::response<boost::beast::http::string_body> handle_request(
    const boost::beast::http::request<boost::beast::http::string_body>& req);
