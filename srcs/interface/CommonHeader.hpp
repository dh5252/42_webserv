
#ifndef COMMONHEADER_HPP
# define COMMONHEADER_HPP

#include <iostream>
#include "enum.h"

class CommonHeader
{
    private:
        std::string connection;
        std::string date;
        std::string pragma;
        std::string trailer;
        std::string tranferEncoding;
        std::string upgrade;
        std::string via;
        std::string warning;
        std::string allow;
        std::string contentEncoding;
        std::string contentLanguage;
        std::string contentLength;
        std::string contentLocation;
        std::string contentMD5;
        std::string contentRange;
        std::string contentType;
        std::string expires;
        std::string lastModified;
    public:
        void    setConnection(std::string obj);
        void    setDate(std::string obj);
        void    setPragma(std::string obj);
        void    setTrailer(std::string obj);
        void    setTransferEncoding(std::string obj);
        void    setUpgrade(std::string obj);
        void    setVia(std::string obj);
        void    setWarning(std::string obj);
        void    setAllow(std::string obj);
        void    setContentEncoding(std::string obj);
        void    setContentLanguage(std::string obj);
        void    setContentLength(std::string obj);
        void    setContentLocation(std::string obj);
        void    setContentMD5(std::string obj);
        void    setContentType(std::string obj);
        void    setExpires(std::string obj);
        void    setLastModified(std::string obj);
};


#endif