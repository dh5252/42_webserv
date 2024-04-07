#ifndef REQUEST_HPP
# define REQUEST_HPP

#include <string>
#include <unordered_map>

class	request : public cahn {
	private:
		std::string							method;
		std::string							path;
		std::string							version;
		std::unordered_map<std::string, std::string>	headers;
		int									isBody;
		std::string							body;

	public:
		request();
		void	parseReq();
		void	parseStartLine();
		void	parseHeaders();
};

#endif
