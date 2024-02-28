#include "easyfind.hpp"
#include <list>
#include <vector>

int main(void)
{
	std::vector<int> test;
    std::list<int> test2;

    test.push_back(5);
    test.push_back(8);
    test.push_back(94);
    test.push_back(7);

    test2.push_back(900);
    test2.push_back(8);
    test2.push_back(94);
    test2.push_back(7);

	easyfind(test, 5);
	easyfind(test, 2);

	easyfind(test2, 8);
	easyfind(test2, 1);

}