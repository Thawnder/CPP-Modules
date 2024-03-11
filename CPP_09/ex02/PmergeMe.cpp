#include "PmergeMe.hpp"

template<typename T>
PmergeMe<T>::PmergeMe() { setName(); }

template<typename T>
PmergeMe<T>::PmergeMe(char **argv) {
	setName();
	setCtn(argv);
}

template<typename T>
PmergeMe<T>::PmergeMe(PmergeMe<T> const & base) { *this = base; }

template<typename T>
PmergeMe<T>::~PmergeMe() {}

template<typename T>
PmergeMe<T> & PmergeMe<T>::operator=(PmergeMe<T> const & base) {
	if (this != &base)
	{
		_ctn.clear();
		_ctn = base._ctn;
		_name = base._name;
	}
	return *this;
}

template<typename T>
void PmergeMe<T>::setCtn(char **argv) {
	for (int i = 1; argv[i]; i++)
		_ctn.push_back(atoi(argv[i]));
}

template<>
void PmergeMe< std::vector<int> >::setName() { _name = "vector"; }

template<>
void PmergeMe< std::deque<int> >::setName() { _name = "deque"; }

template<typename T>
std::string const & PmergeMe<T>::getName() const { return _name; }

template<typename T>
void PmergeMe<T>::merge(size_t left, size_t mid, size_t right) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    T L(n1), R(n2);

    for (size_t i = 0; i < n1; ++i)
        L[i] = _ctn[left + i];
    for (size_t j = 0; j < n2; ++j)
        R[j] = _ctn[mid + 1 + j];

    size_t i = 0;
    size_t j = 0;
    size_t k = left;
    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j]) {
            _ctn[k] = L[i];
            ++i;
        } else {
            _ctn[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        _ctn[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        _ctn[k] = R[j];
        ++j;
        ++k;
    }
}

template<typename T>
void PmergeMe<T>::mergeInsertSort(size_t left, size_t right) {
	if (left < right) {
        size_t mid = left + (right - left) / 2;

        mergeInsertSort(left, mid);
        mergeInsertSort(mid + 1, right);

        merge(left, mid, right);
    }
}

template<typename T>
void PmergeMe<T>::sort() {
	if (_ctn.empty())
	{
		std::cout << "Empty container." << std::endl;
		return ;
	}

	std::clock_t	start = std::clock();

	mergeInsertSort(0, _ctn.size() - 1);

	_time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

template<typename T>
void	PmergeMe<T>::displayResult() const {

	std::cout << "After:	";
	for (size_t i = 0; i < this->_ctn.size() - 1; i++)
		std::cout << _ctn[i] << " ";
	std::cout << _ctn[_ctn.size() - 1] << std::endl;
}

template<typename T>
void PmergeMe<T>::displayTime() const {
	std::cout << "Time to process a range of " << _ctn.size();
	std::cout << " elements with std::" << getName();
	std::cout << " : " << std::fixed << std::setprecision(5) << _time << " us" << std::endl;
}

template class PmergeMe< std::vector<int> >;
template class PmergeMe< std::deque<int> >;