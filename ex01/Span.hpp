#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <list>
#include <algorithm>
#include <exception>
#include <numeric>

class tooFewException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Not enough elements";
		}	
};

class outOfRangeException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Span is full";
		}	
};

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int nbr);
		int shortestSpan();
		int longestSpan();

	private:
		Span();
		unsigned int _maxSize;
		std::vector<int> tab;
};

#endif