#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

//Represent the repertory
class PhoneBook
{
    public:
        PhoneBook(int i);
        ~PhoneBook(void);
        void add(void);
        void search(void);

    private:
        int _nextContact;
        void _print_tab(std:: string str, std::string ending);
        Contact contacts[8];
};

#endif