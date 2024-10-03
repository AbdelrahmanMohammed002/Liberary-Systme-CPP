#ifndef USERLIST_HEADER
#define USERLIST_HEADER

#include <iostream>
#include "User.h"

class UserList
{
private:
    User* users;
    int capacity;
    int usersCount;
public:
    UserList();
    UserList(int);
    void addUser(const User&);
    User* searchUser(string);
    User* searchUser(int);
    void deleteUser(int);
    friend ostream& operator<<(ostream&, const UserList&);
    ~UserList();
};

#endif // !USERLIST_HEADER

