#ifndef REQUEST_HPP
# define REQUEST_HPP

#include <string>
#include <unordered_map>

class	request : public cahn {
	private:
		int												status;
		std::string										method;
		std::string										path;
		std::unordered_map<std::string, std::string>	query;
		std::string										version;
		std::unordered_map<std::string, std::string>	headers;
		int												isBody;
		std::string										body;

	public:
		request();
		void	parseReq();
		void	parseStartLine();
		void	parseURI();
		void	parseHeaders();
};

#endif
