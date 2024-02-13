#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

//Represent the repertory
class PhoneBook
{
    public:
        PhoneBook(int i);
        ~PhoneBook(void);
        int _nextContact;
        void add(void);
        void search(void);

    private:
        void _print_tab(std:: string str, std::string ending);
        Contact contacts[8];
};

#endif