#pragma once

#include <list>
#include <ranges>
#include <iostream>
#include <algorithm>

class Span
{
	private:
		unsigned int _N;
		std::list<int> _list;
		Span();

	public:
		Span(unsigned int max);
		Span(Span const & base);
		~Span();

		Span & operator=(Span const & base);

		class TooManyNumbers : public std::exception {
			public:
				virtual const char* what() const throw() { return "There are too many numbers in the span."; };	
		};

		class TooFewNumbers : public std::exception {
			public:
				virtual const char* what() const throw() { return "There aren't enough numbers in the span."; };	
		};


		void addNumber(int nb);
		void addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end);
		int shortestSpan() const;
		int longestSpan() const;

		std::list<int>& getList();
};