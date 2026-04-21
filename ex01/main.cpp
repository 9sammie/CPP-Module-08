#include "Span.hpp"
#include <iostream>
#include <vector>
#include <ctime>

#define STD 		"\033[0m"
#define GREYBG 		"\033[48;5;237m\033[1m"
#define GREEN 		"\033[38;5;34m\033[48;5;193m"
#define PINK 		"\033[38;5;199m\033[48;5;225m"
// #define BLUE 		"\033[38;5;44m\033[48;5;159m"
// #define YELLOW		"\033[38;5;214m\033[48;5;229m"
// #define VIOLET		"\033[38;5;92m\033[48;5;183m"

// a class that takes an array of int and can find the smallest diff between two
// numbers, or the biggest one.

int main()
{
    std::cout << GREYBG << "       --- Sujet test ---        " << STD << std::endl << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << GREEN << "Shortest: " << sp.shortestSpan() << STD << std::endl;
        std::cout << GREEN << "Longest: "  << sp.longestSpan() << STD << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << GREYBG << " ---Performance(20 000) test --- " << STD << std::endl << std::endl;
    try {
		std::srand(std::time(0));
		unsigned int size = 20000;
        Span spBig = Span(size);
		
		for (unsigned int i = 0; i < size; ++i)
			spBig.addNumber(std::rand());

        std::cout << PINK << "Shortest: " << spBig.shortestSpan() << STD << std::endl;
        std::cout << PINK << "Longest: "  << spBig.longestSpan() << STD << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Erreur Performance: " << e.what() << std::endl;
    }

    std::cout << std::endl << GREYBG << "     --- exceptions test ---     " << STD << std::endl << std::endl;
    try {
        Span small = Span(1);
        small.addNumber(42);
        std::cout << small.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception attendue (TooFew): " << e.what() << std::endl;
    }
    try {
        Span full = Span(2);
        full.addNumber(1);
        full.addNumber(2);
        full.addNumber(3);
    } catch (std::exception &e) {
        std::cout << "Exception attendue (Full): " << e.what() << std::endl;
    }

    return 0;
}
