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

	for (int i = 0; i < 3; ++i)
	{
		if (i == 0)
			ss >> this->method; //is_body 설정을 내가 해야 되면 여기서
		if (i == 1)
			ss >> this->path;
		if (i == 2)
			ss >> this->version;
	}
	//예외?
}

void	request::parseHeaders(std::string raw)
{
	std::istringstream	is(raw);
	std::string			header;
	std::string			key;
	size_t				pos;

	while (std::getline(is, header))
	{
		if ((pos = header.find(": ")) != std::string::npos)
		{
			key = header.substr(0, pos);
			this->map[key] = header.substr(pos + 2);
		}
		else
			//error?
	}
}
