#pragma once

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack(): std::stack<T>() {}
		MutantStack(MutantStack const & base) { *this = base; }
		~MutantStack() {}

		MutantStack & operator=(MutantStack const & base) {
			if (this != &base)
				std::stack<T>::operator=(base);
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
};