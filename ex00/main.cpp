#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

#define STD 		"\033[0m"
#define GREYBG 		"\033[48;5;237m\033[1m"
// #define GREEN 		"\033[38;5;34m\033[48;5;193m"
// #define PINK 		"\033[38;5;199m\033[48;5;225m"
// #define PINK 		"\033[38;5;199m\033[48;5;225m"
// #define BLUE 		"\033[38;5;44m\033[48;5;159m"
#define YELLOW		"\033[38;5;214m\033[48;5;229m"
#define VIOLET		"\033[38;5;92m\033[48;5;183m"


int main()
{
	std::cout << GREYBG << " --- Normal test --- " << STD << std::endl << std::endl;

	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(777);
	
	try
	{
		std::vector<int>::iterator it = easyfind(v, 20);
		std::cout << YELLOW << "Trouvé : " << *it << STD << std::endl;	
		easyfind(v, 42);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl << std::endl;
	}

	std::cout << GREYBG << " --- const test ---  " << STD << std::endl << std::endl;

	const std::vector<int> c = v;
	
	try
	{
		std::vector<int>::const_iterator it = easyfind(c, 777);
		std::cout << VIOLET << "Trouvé : " << *it << STD << std::endl;	
		easyfind(c, 42);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	return 0;
}
