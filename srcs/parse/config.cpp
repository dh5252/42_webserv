#include "config.hpp"

config::config(std::string path)
{
	std::ifstream	conf(path);

	if (!conf.is_open())
		throw	"configuration file does not open.";
	this->rawContent((std::istreambuf_iterator<char>(conf)),
						std::istreambuf_iterator<char>());
	
	parseConf();
}

config::skipSpace()
{
}

config::parseConf()
{
	skipSpace();
	if (rawContent.substr(0, 4) == "http")
	{

		skipSpace();
		if (== "server")
			;
		if (== "location")
			;
	}
}
