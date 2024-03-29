#ifndef REQUEST_HPP
# define REQUEST_HPP

class	request {
	private:
		std::string							method;
		std::string							path;
		std::string							version;
		std::map<std::string, std::string>	headers;
		int									is_body;
		std::string							body;

	public:
		request();
};

#endif
