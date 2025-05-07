#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>

int RPN::compute(const std::string& expr) 
{
	std::istringstream iss(expr);
	std::string token;
	std::stack<int> st;

	while (iss >> token) 
	{
		if (token.size() == 1 && std::isdigit(token[0])) 
		{
			st.push(token[0] - '0');
		} 
		else if (token == "+" || token == "-" || token == "*" || token == "/") 
		{
			if (st.size() < 2) 
				throw std::runtime_error("Error");
			int rhs = st.top(); st.pop();
			int lhs = st.top(); st.pop();
			int result;
			if (token == "+") 
				result = lhs + rhs;
			else if (token == "-") 
				result = lhs - rhs;
			else if (token == "*") 
				result = lhs * rhs;
			else 
			{
				if (rhs == 0) throw std::runtime_error("Error");
				result = lhs / rhs;
			}
			st.push(result);
		} 
		else 
		{
			throw std::runtime_error("Error");
		}
	}

	if (st.size() != 1) 
		throw std::runtime_error("Error");
	return st.top();
}
