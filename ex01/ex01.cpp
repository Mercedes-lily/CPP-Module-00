#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
    std::string entry;
    PhoneBook   repertory(0);

    std::cout << "\033[0;35mWelcome in your awesome PhoneBook" << std::endl;
    while(!std::cin.eof())
    {
        std::cout << " >   " && getline(std::cin, entry);
        if (entry.compare("ADD") == 0)
            repertory.add();
        else if (entry.compare("SEARCH") == 0)
            repertory.search();
        else if (entry.compare("EXIT") == 0)
            break ;
    }
    std::cout << "See you next time :)" << std::endl;
    return (0);
}