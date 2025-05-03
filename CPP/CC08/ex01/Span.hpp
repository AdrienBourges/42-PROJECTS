#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
public:
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);
	template<typename InputIt>
	void addNumber(InputIt first, InputIt last)
	{
		if (_numbers.size() + std::distance(first, last) > _N)
			throw std::runtime_error("Span is full");
		_numbers.insert(_numbers.end(), first, last);
	}

	int shortestSpan() const;
	int longestSpan() const;

private:
	unsigned int	_N;
	std::vector<int>	_numbers;
};

#endif

