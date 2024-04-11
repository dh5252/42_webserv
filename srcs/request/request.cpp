#include "request.hpp"

request::request()
{
	status = 200;
}

void	request::parseReq(std::string raw) //raw contents가 있다 치고
{
	//start line (method path versionOfProtocol)
	std::istringstream	is(raw);
	std::string	startLine;
	std::getline(is, startLine);
	parseStartLine(startLine);

	//Headers start-line과 첫번째 헤더 필드 사이에 공백이 있을 경우 에러 처리 혹은 공백 건너뛰고 계속?
	parseHeaders(is);

	//Body
	//없어야 하는데 있으면 무시하고 진행
	std::string	body;
	while (std::getline(is, body))
		this->body += body;
	//body가 있어야 하고 있는데 content-length가 없으면
	if (this->isBody && !this->body.empty() && this->headers.count("Content-Length") == 0)
		status = 411;//(Length Reuired)
	//body 있어야 하는데 없으면
	if (this->isBody && this->body.empty())
		status = 400;//Bad Request
}

void	request::parseStartLine(std::string	startLine)
{	
	std::stringstream	ss(startLine);

	if (startLineIsTooLong) //그런데 스트링은 그냥 다 받아주는 것 아닌가? octets 8000길이 지원 권
		status = 501;//Not Implemented
	if (invalid)//invalid한 경우는? 빈칸이거나 경로가 아니거나 버전이 아니거나. 메소드는 아래서 한번에 처리?
		status = 400; // or 301(Moved Permanently) redirect
	ss >> this->method >> this->path >> this->version;
	if (this->method != "GET" && this->method != "POST" && this->method != "DELETE")
		status = 501;
	if (this->method == "POST")
		this->isBody = 1;
	if (pathTooLong)
		status = 414;//URI Too Long
	//예외?
}

void	request::parseHeaders(std::istringstream is)
{
	std::string			header;
	std::string			key, value;
	size_t				pos;

	//빈줄이 나오면 헤더 끝
	while (std::getline(is, header) && header != "\r\n\r\n")
	{
		//여기서 콜론 뒤 공백은 선택적 공백
		if (pos = header.find(':') != std::string::npos)
		{	
			key = header.substr(0, pos);
			//field_name에 공백 있으면 에러
			if (key.find_first_of(" \t\n\r") != std::string::npos)
				status = 400;
			//field_name 너무 크
			if (keyTooLong)
				status = 400;//4xx(client error)
			//선택적 공백 고려해서 value 뽑기
			if (header[pos+1] == ' ')
				value = header.substr(pos + 2);
			else
				value = header.substr(pos + 1);
			//Content-Length가 여러개인지
			if (key == "Content-Length" && this->headers.find("Content-Length") && 
					this->headers[key] != value)
				status = 400;
		}
		else if (pos = header.find_first_not_of(" \t") != std::string::npos) //헤더가 여러줄로 나뉘어 있으면
		{
			this->headers[key] += header.substr(pos);
		}
		else
			//error?
	}
	//헤더 중간에 CRLF
	while (std::getline(is, header) && header == "\r\n\r\n")
		;
	if (pos = header.find(':') != std::string::npos)
		status = 400;
	 //둘 다 있으면  content-length 지우
	if (this->headers.count("Transfer-Encoding") && this->headers.count("Content-Length"))
		this->headers.erase("Content-Length");
}
