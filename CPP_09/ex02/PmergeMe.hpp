#pragma once

#include <iostream>
#include <iomanip>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

template<typename T>
class PmergeMe
{
	private:
		std::string _name;
		T _ctn;
		double _time;

	public:
		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(PmergeMe const & base);
		~PmergeMe();

		PmergeMe & operator=(PmergeMe const & base);
		void setCtn(char **argv);

		void setName();

		std::string const & getName() const;

		void sort();
		void mergeInsertSort(size_t left, size_t right);
		void merge(size_t left, size_t mid, size_t right);
		void displayResult() const;
		void displayTime() const;
};
