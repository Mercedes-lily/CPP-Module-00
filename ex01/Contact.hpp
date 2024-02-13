#ifndef CONTACT_H
# define CONTACT_H

# include <string>

//Represent the repertory
class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNickname(void);
        std::string getPhoneNumber(void);
        std::string getDarkestSecret(void);
        void        put_infos(void);

    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
};

#endif