// include ex09_05/ex09_06/ex09_07
#include "std_lib_facilities.h"

class Book
{
public:
    enum class Genre { fiction, nonfiction, periodical, biography, children };

    Book(string isbn, string title, string author, string date, Genre genre, bool checked);
    ~Book();

    string isbn() const { return m_isbn; }
    string title() const { return m_title; }
    string author() const { return m_author; }
    string date() const { return m_date; }
    Genre genre() const { return m_genre; }
    bool checked() const { return m_checked; }

    void checked(bool checked) { m_checked = checked; }

private:
    string m_isbn;
    string m_title;
    string m_author;
    string m_date;
    Genre m_genre;
    bool m_checked;

    void init_book(string isbn);
};

bool operator==(const Book& b1, const Book& b2);
bool operator!=(const Book& b1, const Book& b2);
ostream& operator<<(ostream& os, const Book& b);

// implementation of Book class
Book::Book(string isbn, string title, string author, string date, Genre genre, bool checked)
    : m_title{title}, m_author{author}, m_date{date}, m_genre{genre}, m_checked{checked}
{
    init_book(isbn);
}

Book::~Book()
{
}

void Book::init_book(string isbn)
{
    regex r{"([[:digit:]]+)-([[:digit:]]+)-([[:digit:]]+)-([[:alnum:]]+)"};
    if (!regex_match(isbn, r)) {
        error("invalid isbn");
    }
    m_isbn{isbn};
}

bool operator==(const Book& b1, const Book& b2)
{
    return b1.isbn == b2.isbn;
}

bool operator!=(const Book& b1, const Book& b2)
{
    return !(b1 == b2);
}

ostream& operator<<(ostream& os, const Book& b)
{
    os << b.title() << '\n';
    os << b.author() << '\n';
    os << b.isbn() << '\n';
    return os;
}
