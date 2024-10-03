#include "BookList.h"

BookList::BookList()
{
	capacity = 0;
	booksCount = 0;
}

BookList::BookList(int capacity)
{
	this->capacity = capacity;
	books = new Book[capacity];
	booksCount = 0;
}

void BookList::addBook(const Book& book)
{
	if (booksCount < capacity) 
	{
		books[booksCount] = book;
		books[booksCount].setId(booksCount + 1);
		booksCount++;
	}
	else 
	{
		cout << "list is full" << endl;
	}

}

Book* BookList::searchBook(string title)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getTitle() == title) {
			return &books[i];
		}
	}
	return nullptr;
}

Book* BookList::searchBook(int id)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getId() == id) {
			return &books[i];
		}
	}
	return nullptr;
}

void BookList::deleteBook(int id)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getId() == id)
		{
			while (i < booksCount - 1)
			{
				books[i] = books[i + 1];
				i++;
			}
		}
		booksCount--;
		break;

	}
}

Book BookList::getTheHighestRatedBook()
{
	double highestRate = -1.0;
	int index = 0;
	
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getAverageRating() > highestRate)
		{
			highestRate = books[i].getAverageRating();
			index = i;
		}
	}
	return books[index];
}

void BookList::getBooksForUser(const User& author)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getAuthor() == author)
		{
			cout << books[i];
		}
	}
}

Book& BookList::operator[](int index)
{
	if (index < 0 || index > booksCount)
	{
		cout << "index out of array range" << endl;		
	}
	else {
		return books[index];
	}
}



ostream& operator<<(ostream& output, const BookList& bookList)
{
	for (int i = 0; i < bookList.booksCount; i++)
	{
		output << bookList.books[i];
	}
	return output;
}

BookList::~BookList()
{
	delete[] books;
} 