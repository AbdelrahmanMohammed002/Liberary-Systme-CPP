#ifndef BOOK_HEADER
#define BOOK_HEADER


#include <string>
#include <iostream>
#include "User.h"
using namespace std;


class Book
{
private:
	string title;
	string ISBN;
	int id;
	string category;
	double averageRating;
	User author;
	int numberOfRates;
	double sumOfRates;

public:
	static int count;
	Book();
	Book(string, string, string);
	Book(const Book&);

	void setTitle(string);
	string getTitle() const;
	void setISBN(string);
	string getISBN() const;
	void setId(int);
	int getId() const;
	void setCategory(string);
	string getCategory()const;
	void setAuthor(const User&);
	User getAuthor() const;
	void rateBook(double);
	double getAverageRating() const;
	bool operator==(const Book&);
	friend ostream& operator<<(ostream&, const Book&);
	friend istream& operator>>(istream&, Book&);
};

#endif // !BOOK_HEADER

