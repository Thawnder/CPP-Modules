#include "Span.hpp"

Span::Span() {}
Span::Span(unsigned int max): _N(max) {}
Span::Span(Span const & base) { *this = base; }
Span::~Span() {}

Span & Span::operator=(Span const & base) {
	if (this != &base)
	{
		_N = base._N;
		_list.clear();
		std::copy(base._list.begin(), base._list.end(), std::back_inserter(_list));
	}
	return *this;
}

void Span::addNumber(int nb) {
	if (_list.size() >= _N)
		throw TooManyNumbers();
	_list.push_back(nb);
}

void Span::addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end) {
	if (_list.size() >= _N)
		throw TooManyNumbers();
	std::copy(begin, end, std::back_inserter(_list));
}

int Span::shortestSpan() const {
	if (_list.size() <= 1)
		throw TooFewNumbers();
	
	int min = *std::max_element(this->_list.begin(), this->_list.end());
	std::list<int>::const_iterator it1;
	std::list<int>::const_iterator it2;

	for (it1 = _list.begin(); it1 != _list.end(); it1++)
	{
		for (it2 = _list.begin(); it2 != _list.end(); it2++)
		{
			if (it1 == it2)
				continue;
			if (std::abs(*it1 - *it2) < min)
				min = std::abs(*it1 - *it2);
		}
	}
	return min;
}

int Span::longestSpan() const {
	if (_list.size() <= 1)
		throw TooFewNumbers();
	return (*std::max_element(_list.begin(), _list.end()) - *std::min_element(_list.begin(), _list.end()));
}

std::list<int>& Span::getList() { return _list; }