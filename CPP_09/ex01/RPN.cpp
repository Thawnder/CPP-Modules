#include "RPN.hpp"

RPN::RPN(): _exp("") {}

RPN::RPN(std::string exp): _exp(exp) {}

RPN::RPN(RPN const & base) { *this = base; }

RPN::~RPN() {}

RPN & RPN::operator=(RPN const & base) {
	if (this != &base)
		_exp = base._exp;
	return *this;
}

void RPN::setExp(std::string exp) {
	_exp = exp;
}

int RPN::checkExp() {
	if (_exp.empty())
	{
		std::cout << "Empty expression." << std::endl;
		return 1;
	}
	for (unsigned int i = 0; _exp[i]; i++)
	{
		if (!isdigit(_exp[i]) && !isspace(_exp[i]) && _exp[i] != '+' && _exp[i] != '-' && _exp[i] != '/' && _exp[i] != '*')
		{
			std::cout << "Invalid character in expression." << std::endl;
			return 1;
		}

		if (i < _exp.size() - 1 && isdigit(_exp[i]) && isdigit(_exp[i + 1]))
		{
			std::cout << "Error: too large a number; it must be between 0 and 9." << std::endl;
			return 1;
		}

		if (i < _exp.size() - 1 && _exp[i] == '-' && isdigit(_exp[i + 1]))
		{
			std::cout << "Error: not a positive number." << std::endl;
			return 1;
		}

		if (i < _exp.size() - 1 && !isspace(_exp[i]) && !isspace(_exp[i + 1]))
		{
			std::cout << "Error: bad input; missing space" << std::endl;
			return 1;
		}
	}
	return 0;
}

void RPN::calc() {
	if (checkExp())
		return;

	int res;
	
	for (unsigned int i = 0; _exp[i]; i++)
	{
		if (isspace(_exp[i]))
			continue;
		if (isdigit(_exp[i]))
		{
			_stack.push(_exp[i] - 48);
			continue;
		}

		switch (_exp[i])
		{
			case '*':
				res = _stack.top();
				_stack.pop();
				res = _stack.top() * res;
				_stack.pop();
				_stack.push(res);
				break;
			case '/':
				res = _stack.top();
				_stack.pop();
				res = _stack.top() / res;
				_stack.pop();
				_stack.push(res);
				break;
			case '+':
				res = _stack.top();
				_stack.pop();
				res = _stack.top() + res;
				_stack.pop();
				_stack.push(res);
				break;
			case '-':
				res = _stack.top();
				_stack.pop();
				res = _stack.top() - res;
				_stack.pop();
				_stack.push(res);
				break;
			default:
				break;
		}
	}
	std::cout << res << std::endl;
}