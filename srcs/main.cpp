#include ""

int	main(int argc, char **argv)
{
	if (ac > 2)
		return 1;
	try {
		signal();
		if (ac == 2)
			parseConf	parseConf(argv[1]);
		else
			parseConf	parseConf("default.conf");
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
