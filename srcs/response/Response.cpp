
#include "Response.hpp"

void Response::setBody(std::string bd) {
    this->body = bd;
}

void Response::appendBody(std::string add) {
    this->body += add;
}

std::string Response::getBody() const {
    return this->body;
}

void Response::addHeader(std::string key, std::string value) {
    header.emplace(std::make_pair(key, value));
}

void Response::removeHeaderAll(std::string key) {
    std::pair<std::unordered_multimap<std::string, std::string>::iterator, std::unordered_multimap<std::string, std::string>::iterator> range = header.equal_range(key);
    header.erase(range.first, range.second);
}

std::string Response::makeResponse() const {
    // header + body 만들기
    return "";
}