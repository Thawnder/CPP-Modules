#pragma once

#include <iostream>
#include <algorithm>

template<typename T> int easyfind(T& list, int nb) {
	if (std::find(list.begin(), list.end(), nb) != list.end())
	{
		std::cout << nb << " is in the container" << std::endl;
		return 1;
	}
	else
		std::cout << nb << " is not in the container" << std::endl;
	return 0;
}