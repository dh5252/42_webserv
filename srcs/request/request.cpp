#include "request.hpp"

request::request()
{
}

void	request::parseReq(std::string raw) //raw contents가 있다 치고
{
	//start line (method path versionOfProtocol)
	{
	std::istringstream	is(raw);
	std::string	startLine;
	std::getline(is, startLine);
	parseStartLine(startLine);
	//getline 돌면서 헤더 파싱
	}
	{
	size_t	newLine = raw.fine('\n');
	parseStartLine(raw.substr(0, newLine));
	raw.erase(0, newLine);
	//통째로 넘겨서 헤더 파싱
	}

	//Headers
	parseHeaders(raw);

	//Body
	if (is_body)
		this->body = ;
}

void	request::parseStartLine(std::string	startLine)
{	
	std::stringstream	ss(startLine);

	ss >> this->method >> this->path >> this->version;
	if (this->method != "GET" && this->method != "POST" && this->method != "DELETE")
		error;
	//예외?
}

void	request::parseHeaders(std::string raw)
{
	std::istringstream	is(raw);
	std::string			header;
	std::string			key;
	size_t				pos;

	//빈줄이 나오면 헤더 끝
	while (std::getline(is, header) && header != '\n')
	{
		//여기서 콜론 뒤 공백은 선택적 공백
		if (pos = header.find(':') != std::string::npos)
		{	
			key = header.substr(0, pos);
			if (key.find_first_of(" \t\n\r") != std::string::npos)
				error 400;
			if (header[pos+1] == ' ')
				this->headers[key] = header.substr(pos + 2);
			else
				this->headers[key] = header.substr(pos + 1);
		}
		else if (pos = header.find_first_not_of(" \t") != std::string::npos) //헤더가 여러줄로 나뉘어 있으면
		{
			this->headers[key] += header.substr(pos);
		}
		else
			//error?
	}
}
