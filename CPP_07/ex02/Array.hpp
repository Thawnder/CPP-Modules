#pragma once

template<typename T> class Array {
	private:
		unsigned int _size;
		T* _array;
	public:
		Array(): _size(0), _array(new T[0]){};
		Array(unsigned int n): _size(n), _array(new T[n]){};
		Array(Array const & base): _array(NULL) {*this = base;};
		~Array() {delete[] _array;};

		Array & operator=(Array const & base) {
			if (this != &base)
			{
				if (this->_array)
					delete[] this->_array;
				this->_array = new T[base._size];
				for (unsigned int i = 0; i < base._size ; i++)
					this->_array[i] = base._array[i];
				this->_size = base._size;
			}
			return *this;
		};
		T & operator[](unsigned int i) {
			if (i < this->_size)
				return this->_array[i];
			throw OutOfBounds();
		};

		class OutOfBounds: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Error: Out of bounds";
				}
		};

		unsigned int size() {
			int i;
			for (i = 0; this->_array[i]; i++);
			return i;
		};
};