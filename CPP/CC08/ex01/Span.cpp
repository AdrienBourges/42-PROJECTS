#include "Span.hpp"
#include <algorithm>
#include <iterator>

Span::Span(unsigned int N)
: _N(N)
{}

Span::Span(const Span &other)
: _N(other._N), _numbers(other._numbers)
{}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _N)
		throw std::runtime_error("Span is full");
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");
	std::vector<int> tmp(_numbers);
	std::sort(tmp.begin(), tmp.end());
	int minDiff = tmp[1] - tmp[0];
	for (size_t i = 2; i < tmp.size(); ++i)
	{
		int diff = tmp[i] - tmp[i - 1];
		if (diff < minDiff)
			minDiff = diff;
	}
	return minDiff;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers");
	std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
	return *maxIt - *minIt;
}

