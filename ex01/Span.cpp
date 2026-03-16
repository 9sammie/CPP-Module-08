#include "Span.hpp"

Span::Span(): _maxSize(0) {}

Span::Span(unsigned int N): _maxSize(N) {}

Span::Span(const Span& other): _maxSize(other._maxSize), tab(other.tab) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		tab = other.tab;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int nbr)
{
	if (tab.size() >= _maxSize)
		throw outOfRangeException();
	tab.push_back(nbr);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (tab.size() + std::distance(begin, end) > _maxSize)
		throw outOfRangeException();
	tab.insert(tab.end(), begin, end);
}

int Span::shortestSpan()
{
	if (tab.size() < 2)
		throw tooFewException();

	std::vector<int> sorted = tab;
	std::sort(sorted.begin(), sorted.end());
	
	std::vector<int> result(sorted.size());
	
	std::adjacent_difference(sorted.begin(), sorted.end(), result.begin());

	std::vector<int>::iterator minIt = min_element(result.begin() + 1, result.end());

	return *minIt;
}

int Span::longestSpan()
{
	if (tab.size() < 2)
		throw tooFewException();

	std::vector<int>::iterator minIt = min_element(tab.begin(), tab.end());
	std::vector<int>::iterator maxIt = max_element(tab.begin(), tab.end());
	return (*maxIt - *minIt);
}