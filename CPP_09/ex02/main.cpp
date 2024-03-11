#include "PmergeMe.hpp"

void    displayList(int argc, char **argv) {

    std::cout << "Before: ";
    for (int i = 0; argv[i + 1]; i++)
        std::cout << argv[i] << " ";
    std::cout << argv[argc - 1] << std::endl;
        std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Parameter error. The execution format is: ./PmergeMe [expression]" << std::endl;
		return -1 ;
	}

	for (int i = 1; argv[i]; i++)
	{
		if (((std::string)argv[i]).size() > 10)
			return (std::cout << "Error: int overflow." << std::endl, -1);
		for (int j = 0; argv[i][j]; j++)
			if (!isdigit(argv[i][j]))
				return (std::cout << "Error: invalid character." << std::endl, -1);
	}

	std::cout << "--------------TEST 1: Default Constructor--------------" << std::endl << std::endl;

	PmergeMe< std::vector<int> > test1v = PmergeMe< std::vector<int> >();

	test1v.sort();
	test1v.setCtn(argv);

	PmergeMe< std::deque<int> > test1d = PmergeMe< std::deque<int> >();

	test1d.sort();
	test1d.setCtn(argv);

	std::cout << std::endl;

	displayList(argc, argv);
	test1v.sort();
	test1d.sort();
	
	test1d.displayResult();

	test1v.displayTime();
	test1d.displayTime();

	std::cout << std::endl << "--------------TEST 2: String Constructor--------------" << std::endl << std::endl;

	PmergeMe< std::vector<int> > test2v = PmergeMe< std::vector<int> >(argv);
	PmergeMe< std::deque<int> > test2d = PmergeMe< std::deque<int> >(argv);

	test2v.sort();
	test2d.sort();

	test2v.displayResult();

	test2v.displayTime();
	test2d.displayTime();

	std::cout << std::endl << "--------------TEST 3: Copy Constructor--------------" << std::endl << std::endl;

	PmergeMe< std::vector<int> > test3v = test2v;
	PmergeMe< std::deque<int> > test3d = test2d; 

	test3v.sort();
	test3d.sort();

	test3v.displayResult();

	test3v.displayTime();
	test3d.displayTime();
	
	return 0;
}