#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Element not found in container";
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int toFind)
{
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);

	if (it == container.end())
	{
		throw NotFoundException();
	}
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int toFind)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), toFind);

	if (it == container.end())
	{
		throw NotFoundException();
	}
	return it;
}

#endif