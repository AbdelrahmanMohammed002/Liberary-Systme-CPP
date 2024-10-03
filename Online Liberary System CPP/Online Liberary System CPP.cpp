#include <iostream>
#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"

using namespace std;

// Function declarations for menus
void mainMenu();
void userMenu(UserList* U);
void bookMenu(BookList* B, UserList* U);
void searchUserMenu(UserList* U);
void searchBookMenu(BookList* B, UserList* U);
void modifyBookMenu(Book* book, BookList* B, UserList* U);
void deleteUserMenu(User* user, UserList* U);
void handleBookCreation(BookList* B, UserList* U);

// Main Menu Logic
void mainMenu() {
    cout << "Select one of the following choices : " << endl;
    cout << "1- Books Menu" << endl;
    cout << "2- Users Menu" << endl;
    cout << "3- Exit " << endl;
}

// User Menu Logic
void userMenu(UserList* U) {
    bool continueUserMenu = true;
    int choice;
    while (continueUserMenu) {
        cout << "USERS MENU" << endl;
        cout << "1- Create a USER and add it to the list " << endl;
        cout << "2- Search for a user " << endl;
        cout << "3- Display all users " << endl;
        cout << "4- Back to main menu" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            User user;
            cin >> user;
            U->addUser(user);
            break;
        }
        case 2:
            searchUserMenu(U);
            break;
        case 3:
            cout << *U;
            break;
        case 4:
            continueUserMenu = false;
            break;
        default:
            continueUserMenu = false;
        }
    }
}

// Search for User Menu Logic
void searchUserMenu(UserList* U) {
    bool continueSearchMenu = true;
    int choice;
    while (continueSearchMenu) {
        cout << "SEARCH FOR A USER" << endl;
        cout << "1- Search by name" << endl;
        cout << "2- Search by id" << endl;
        cout << "3- Return to users menu" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            cout << "Enter Name: ";
            cin >> name;
            User* user = U->searchUser(name);
            if (user) {
                cout << *user;
                deleteUserMenu(user, U);
            }
            else {
                cout << "Name Not Found" << endl;
            }
            break;
        }
        case 2: {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            User* user = U->searchUser(id);
            if (user) {
                cout << *user;
                deleteUserMenu(user, U);
            }
            else {
                cout << "ID Not Found" << endl;
            }
            break;
        }
        case 3:
            continueSearchMenu = false;
            break;
        default:
            continueSearchMenu = false;
        }
    }
}

// Delete User Menu Logic
void deleteUserMenu(User* user, UserList* U) {
    int choice;
    cout << "1- Delete user" << endl;
    cout << "2- Return to users menu" << endl;
    cin >> choice;

    if (choice == 1) {
        U->deleteUser(user->getId());
    }
}

// Book Menu Logic
void bookMenu(BookList* B, UserList* U) {
    bool continueBookMenu = true;
    int choice;
    while (continueBookMenu) {
        cout << "BOOKS MENU" << endl;
        cout << "1- Create a book and add it to the list" << endl;
        cout << "2- Search for a book" << endl;
        cout << "3- Display all books (with book rating)" << endl;
        cout << "4- Get the highest rated book" << endl;
        cout << "5- Get all books of a user" << endl;
        cout << "6- Back to main menu" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            handleBookCreation(B, U);
            break;
        case 2:
            searchBookMenu(B, U);
            break;
        case 3:
            cout << *B;
            break;
        case 4:
            cout << B->getTheHighestRatedBook();
            break;
        case 5: {
            int userId;
            cout << "Enter User ID: ";
            cin >> userId;
            User* user = U->searchUser(userId);
            if (user) {
                B->getBooksForUser(*user);
            }
            else {
                cout << "User not found" << endl;
            }
            break;
        }
        case 6:
            continueBookMenu = false;
            break;
        default:
            continueBookMenu = false;
        }
    }
}

// Book Creation and Assignment Logic
void handleBookCreation(BookList* B, UserList* U) {
    Book book;
    cin >> book;

    bool assigningAuthor = true;
    while (assigningAuthor) {
        cout << "1- Assign Author" << endl;
        cout << "2- Continue" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int authorId;
            cout << "Enter author (user) ID: ";
            cin >> authorId;
            User* author = U->searchUser(authorId);
            if (author) {
                book.setAuthor(*author);
                assigningAuthor = false;
            }
            else {
                cout << "No Author Found with ID = " << authorId << endl;
            }
            break;
        }
        case 2:
            assigningAuthor = false;
            break;
        default:
            assigningAuthor = false;
        }
    }
    B->addBook(book);
}

// Search for Book Menu Logic
void searchBookMenu(BookList* B, UserList* U) {
    bool continueSearchBook = true;
    int choice;
    while (continueSearchBook) {
        cout << "SEARCH FOR A BOOK" << endl;
        cout << "1- Search by name" << endl;
        cout << "2- Search by id" << endl;
        cout << "3- Return to books menu" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            string title;
            cout << "Enter Title: ";
            cin >> title;
            Book* book = B->searchBook(title);
            if (book) {
                cout << *book;
                modifyBookMenu(book, B, U);
            }
            else {
                cout << "Book Not Found" << endl;
            }
            break;
        }
        case 2: {
            int bookId;
            cout << "Enter ID: ";
            cin >> bookId;
            Book* book = B->searchBook(bookId);
            if (book) {
                cout << *book;
            }
            else {
                cout << "Book Not Found" << endl;
            }
            break;
        }
        case 3:
            continueSearchBook = false;
            break;
        default:
            continueSearchBook = false;
        }
    }
}

// Modify Book Menu Logic
void modifyBookMenu(Book* book, BookList* B, UserList* U) {
    bool continueModifyBook = true;
    int choice;
    while (continueModifyBook) {
        cout << "1- Update Author" << endl;
        cout << "2- Update Title" << endl;
        cout << "3- Update Category" << endl;
        cout << "4- Delete Book" << endl;
        cout << "5- Rate Book" << endl;
        cout << "6- Back to books menu" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            int authorId;
            cout << "Enter author (user) ID: ";
            cin >> authorId;
            User* author = U->searchUser(authorId);
            if (author) {
                book->setAuthor(*author);
            }
            else {
                cout << "No Author Found with ID = " << authorId << endl;
            }
            break;
        }
        case 2: {
            string newTitle;
            cout << "Enter new title: ";
            cin >> newTitle;
            book->setTitle(newTitle);
            break;
        }
        case 3: {
            string newCategory;
            cout << "Enter new category: ";
            cin >> newCategory;
            book->setCategory(newCategory);
            break;
        }
        case 4:
            B->deleteBook(book->getId());
            continueModifyBook = false;
            break;
        case 5: {
            double rating;
            cout << "Enter rating: ";
            cin >> rating;
            book->rateBook(rating);
            break;
        }
        case 6:
            continueModifyBook = false;
            break;
        default:
            continueModifyBook = false;
        }
    }
}

// Main Function
int main() {
    int userCapacity, bookCapacity;

    cout << "Enter UserList capacity: ";
    cin >> userCapacity;

    cout << "Enter BookList capacity: ";
    cin >> bookCapacity;

    UserList* userList = new UserList(userCapacity);
    BookList* bookList = new BookList(bookCapacity);

    bool continueProgram = true;
    int mainChoice;
    while (continueProgram) {
        mainMenu();
        cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            bookMenu(bookList, userList);
            break;
        case 2:
            userMenu(userList);
            break;
        case 3:
            continueProgram = false;
            break;
        default:
            continueProgram = false;
        }
    }

    delete userList;
    delete bookList;

    return 0;
}
