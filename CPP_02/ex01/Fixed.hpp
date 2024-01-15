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
		Fixed & operator=(Fixed const & point);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& output, Fixed const & point);

#endif 