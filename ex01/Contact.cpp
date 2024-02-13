#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact(void)
{
    std::cout << "Contact Constructor called" << std::endl;
}

Contact::~Contact(void)
{
    std::cout << "Contact Destructor called" << std::endl;
}

std::string Contact::getFirstName(void)
{
    return(this->firstName);
}

std::string Contact::getLastName(void)
{
    return(this->lastName);
}

std::string Contact::getNickname(void)
{
    return(this->nickname);
}

std::string Contact::getPhoneNumber(void)
{
    return(this->phoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
    return(this->darkestSecret);
}

void    Contact::put_infos(void)
{
    std::cout << "Please enter the infos for the contact" << std::endl;
    std::cout << "First Name : ";
    getline(std::cin, this->firstName);
    std::cout << "Last Name : ";
    getline(std::cin, this->lastName);
    std::cout << "Nickname : ";
    getline(std::cin, this->nickname);
    std::cout << "Phone Number : ";
    getline(std::cin, this->phoneNumber);
    std::cout << "Darkest Secret : ";
    getline(std::cin, this->darkestSecret);
    std::cout << "Contact infos completed!" << std::endl;
}
