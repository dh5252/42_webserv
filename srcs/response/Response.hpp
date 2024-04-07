
#ifndef RESPONSE_HPP
# define RESPONSE_HPP

#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>

class Response
{
    private:
        std::unordered_multimap<std::string, std::string> header;
        std::string body;
    public:
        void setBody(std::string bd);
        void appendBody(std::string add);
        std::string getBody() const;
        void addHeader(std::string key, std::string value);
        void removeHeaderAll(std::string key);
        std::string makeResponse() const;

        // header value search
        //std::list<std::string> &findHeaderValueByKey(std::string key);

        //exception 추가필요

        //각종 header에 대한 response 처리 필요.

        // kqueue 사용하여 쓰기.
};


#endif