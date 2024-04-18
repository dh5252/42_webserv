#ifndef HTTPBLOCK_HPP
# define HTTPBLOCK_HPP

# include <unsorted_map>

class	httpBlock {
	protected:
		std::string							root;
		std::string							serverName
		std::unsorted_map<int, std::string>	errorPage;
		unsigned int						cliendMaxBodySize;

	public:
};

#endif
