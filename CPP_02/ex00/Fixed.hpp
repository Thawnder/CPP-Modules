#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int _pt;
		static const int _exp = 8;
	public:
		Fixed();
		Fixed(Fixed const & point);
		Fixed const & operator=(Fixed const & point);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif 