#include "Book.h"

int Book::count = 0;


Book::Book()
{
	title = "";
	ISBN = "";
	category = "";
	averageRating = 0.0;
	User author;

	numberOfRates = 0;
	sumOfRates = 0.0;

	count++;
	id = count;
}

Book::Book(string title, string ISBN, string category)
{
	this->title = title;
	this->ISBN = ISBN;
	this->category = category;

	User author;
	averageRating = 0.0;

	numberOfRates = 0;
	sumOfRates = 0.0;


	count++;
	id = count;
}

Book::Book(const Book& book)
{
	title = book.title;
	ISBN = book.ISBN;
	category = book.category;
	averageRating = book.averageRating;
	id = book.id;
	author = book.author;
	numberOfRates = book.numberOfRates;
	sumOfRates = book.sumOfRates;

}

void Book::setTitle(string title)
{
	this->title = title;
}

string Book::getTitle() const
{
	return title;
}

void Book::setISBN(string ISBN)
{
	this->ISBN = ISBN;
}

string Book::getISBN() const
{
	return ISBN;
}

void Book::setId(int id)
{
	this->id = id;
}

int Book::getId() const
{
	return id;
}

void Book::setCategory(string category)
{
	this->category = category;
}

string Book::getCategory() const
{
	return category;
}

void Book::setAuthor(const User& author)
{
	this->author = author;
}

User Book::getAuthor() const
{
	return author;
}

void Book::rateBook(double bookRate)
{
	numberOfRates++;
	sumOfRates += bookRate;
	averageRating = sumOfRates / numberOfRates;
}

double Book::getAverageRating() const
{
	return averageRating;
}

bool Book::operator==(const Book& book)
{
	return(title == book.title && ISBN == book.ISBN && id == book.id && category == book.category && averageRating == book.averageRating && author == book.author);

}

ostream& operator<<(ostream& output, const Book& book)
{
	cout << "////////////////////////////////////////////////" << endl;
	cout << "Book " << book.id << "'s Informations: " << endl;
	output << "Title: " << book.title << endl;
	output << "ISBN: " << book.ISBN << endl;
	output << "Category: " << book.category << endl;
	output << "Average Rating: " << book.averageRating << endl;
	if (book.getAuthor().getName() != "") {
		cout << book.author << endl;
	}
	cout << "////////////////////////////////////////////////" << endl;

	return output;
}

istream& operator>>(istream& input, Book& book)
{
	cout << "Please Enter Book Information." << endl;
	cout << "Title: "; input >> book.title; 
	cout << "ISBN: "; input >> book.ISBN; 
	cout << "Category: "; input >> book.category; 
	cout << "Average Rating: "; input >> book.averageRating; 
	//cout << "Author: "; input >> book.author; 

	return input;
}
