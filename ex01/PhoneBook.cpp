#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

//TODO ctrl + D, contacts vides et tout tester

PhoneBook::PhoneBook(int i) : _nextContact(i)
{
    std::cout << "PhoneBook Constructor called" << std::endl;
}
PhoneBook::~PhoneBook(void)
{
    std::cout << "PhoneBook Destructor called" << std::endl;
}

void    PhoneBook::add()
{
    this->contacts[this->_nextContact % 8].put_infos();
    this->_nextContact++;
}

void PhoneBook::_print_tab(std:: string str, std::string ending)
{
    int length;
    length = str.length();
    if (length == 10)
        std::cout << str << ending;
    else if(length < 10)
    {
        for(int i = 0; i < 10 - length; i++)
            std::cout << " ";
        std::cout << str << ending;
    }
    else
    {
        for(int i = 0; i < 9; i++)
            std::cout << str[i];
        std::cout << "." << ending;
    }
}

void    PhoneBook::search(void)
{
    std::string str;
	int			i;
    std::string index;
    if (this->_nextContact == 0)
    {
        std::cout << "0 contact in the Awesome PhoneBook" << std::endl;
        return ;
    }
    std::cout << std::setw(10) << "index" << "|" << std::setw(10) << std::setw(10) << "firstname" << "|";
    std::cout << std::setw(10) << "lastname" << "|" << std::setw(10) << "nickname" << std::endl;
    for (int i = 0; i < 8; i ++)
    {
        if( i >= this->_nextContact)
            continue;
        std::cout << "         " << i << "|";
        str = this->contacts[i].getFirstName();
        this->_print_tab(str, "|");
        str = this->contacts[i].getLastName();
        this->_print_tab(str, "|");
        str = this->contacts[i].getNickname();
        this->_print_tab(str, "");
        std::cout << std::endl;
    }
    std::cout << "Enter the index of the desired contact : ";
    while(!std::cin.eof())
	{
        getline(std::cin, index);
		i = index[0] - 48;
        if (i >= this->_nextContact)
            std::cout << "Enter a valid index" << std::endl << "Enter the index of the desired contact : ";
        else if (!isdigit(index[0]) || index[1] || index[0] == '9' || index[0] == '8')
            std::cout << "Enter a valid index" << std::endl << "Enter the index of the desired contact : ";
        else
        {
			std::cout << this->contacts[i].getFirstName() << std::endl;
			std::cout << this->contacts[i].getLastName() << std::endl;
			std::cout << this->contacts[i].getNickname() << std::endl;
			std::cout << this->contacts[i].getPhoneNumber() << std::endl;
			std::cout << this->contacts[i].getDarkestSecret() << std::endl;
			return ;
        }
	}
}
