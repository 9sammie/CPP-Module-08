#include <iostream>
#include <list>
#include <string>
#include "MutantStack.hpp"

#define STD 		"\033[0m"
#define GREYBG 		"\033[48;5;237m\033[1m"
#define GREEN 		"\033[38;5;34m\033[48;5;193m"
#define PINK 		"\033[38;5;199m\033[48;5;225m"
#define BLUE 		"\033[38;5;44m\033[48;5;159m"
#define YELLOW		"\033[38;5;214m\033[48;5;229m"
#define VIOLET		"\033[38;5;92m\033[48;5;183m"

// the contener "stack" normally allow only 3 methods, but here we are creating
// a class wich inherit from stack, and then allow us to use the iteration
// methods since we have access to the private member "this->c".

int main()
{
    std::cout << GREYBG << "          --- Sujet test (int) ---           " << STD << std::endl << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    MutantStack<int>::iterator firstIt = mstack.begin();
	std::cout << YELLOW << *firstIt << " " << *++firstIt << STD << std::endl;

    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << YELLOW << *it << " ";
        ++it;
    }
    std::cout << STD << std::endl;
    std::cout << std::endl;

    std::cout << GREYBG << " --- Comparaison with test 1 (std::list) --- " << STD << std::endl << std::endl;
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::list<int>::iterator itl = mlist.begin();
    while (itl != mlist.end()) {
        std::cout << YELLOW << *itl << " ";
        ++itl;
    }
    std::cout << STD << std::endl;
    std::cout << std::endl;

    std::cout << GREYBG << "   --- Reverse Iterators test (Strings) ---  " << STD << std::endl << std::endl;
    MutantStack<std::string> sstack;
    sstack.push("Mutant");
    sstack.push("is");
    sstack.push("taking");
    sstack.push("over");
    sstack.push("the");
    sstack.push("World");
    sstack.push("!");

    std::cout << VIOLET << "Ordre normal:  ";
    for (MutantStack<std::string>::iterator it_s = sstack.begin(); it_s != sstack.end(); ++it_s)
        std::cout << *it_s << " ";
    std::cout << STD << std::endl;

    std::cout << BLUE << "Ordre inverse: ";
    MutantStack<std::string>::reverse_iterator rit = sstack.rbegin();
    MutantStack<std::string>::reverse_iterator rite = sstack.rend();
    while (rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << STD << std::endl;
    std::cout << std::endl;

    std::cout << GREYBG << "          --- Casting to stack ---           " << STD << std::endl << std::endl;
    std::stack<int> s(mstack);
    std::cout << GREEN << "Copie dans std::stack reussie, size: " << s.size() << STD << std::endl;

    return 0;
}