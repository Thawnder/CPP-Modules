#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int _pt;
		static const int _exp = 8;
	public:
		Fixed();
		Fixed(Fixed const & point);
		Fixed(int const val);
		Fixed(float const val);
		~Fixed();

		Fixed & operator=(Fixed const & point);
		Fixed operator+(Fixed const & point) const;
		Fixed operator-(Fixed const & point) const;
		Fixed operator*(Fixed const & point) const;
		Fixed operator/(Fixed const & point) const;

		Fixed & operator++();
		Fixed operator++(int);
		Fixed & operator--();
		Fixed operator--(int);

		bool operator<(Fixed const & point) const;
		bool operator>(Fixed const & point) const;
		bool operator<=(Fixed const & point) const;
		bool operator>=(Fixed const & point) const;
		bool operator==(Fixed const & point) const;
		bool operator!=(Fixed const & point) const;

		static Fixed & min(Fixed & a, Fixed & b);
		static const Fixed & min(Fixed const & a, Fixed const & b);
		static Fixed & max(Fixed & a, Fixed & b);
		static const Fixed & max(Fixed const & a, Fixed const & b);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& output, Fixed const & point);

#endif 