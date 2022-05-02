#include "procesingLibrary.h"

void searchQueryByAuthor(const std::vector<Book>& books)
{
    std::string const welcomeMessage{ "����� ����� �� ������" };
    std::string author{ enteryNewBookAuthor(welcomeMessage) };
    std::vector<Book> booksByAuthor(0);//������ ������ ����, ��� �������� ����������� �����
    findBooksByAuthor(books, author, booksByAuthor);//����� ���� �� ������
    if (booksByAuthor.size() > 0)//���� ������ booksByAuthor �� ������
    {
        printBooks(booksByAuthor);//����� ��������� ����
    }
    else
    {
        std::string const booksNotFound{ "���� �������� ������ " + author + " �� ��������" };
        std::cout << booksNotFound << std::endl;
    }
}

void searchQueryByYearPuolication(const std::vector<Book>& books)
{
    std::string const welcomeMessage{ "����� ����� �� ���� ����������" };
    unsigned int yearPuplication{ enteryNewBookYearPuplication(welcomeMessage) };
    std::vector<Book> booksByYearPublication(0);//������ ������ ����, ��� �������� ����������� �����
    findBooksByYearPuolication(books, yearPuplication, booksByYearPublication);//����� ���� �� ���� �������
    if (booksByYearPublication.size() > 0)//���� ������ booksByYearPublication �� ������
    {
        printBooks(booksByYearPublication);//����� ��������� ����
    }
    else
    {
        std::string const booksNotFound{ "���� " + std::to_string(yearPuplication) + " ���� ������� �� ��������" };
        std::cout << booksNotFound << std::endl;
    }
}

void searchQueryByYearPuolicationMoreThen(const std::vector<Book>& books)
{
    std::string const welcomeMessage{ "����� ���� �������������� �����:" };
    unsigned int yearPuplication{ enteryNewBookYearPuplication(welcomeMessage) };
    std::vector<Book> booksByYearPublication(0);//������ ������ ����, ��� �������� ����������� �����
    findBooksByYearPuolicationMoreThen(books, yearPuplication, booksByYearPublication);//����� ���� �������� �����
    if (booksByYearPublication.size() > 0)//���� ������ booksByYearPublication �� ������
    {
        printBooks(booksByYearPublication);//����� ��������� ����
    }
    else
    {
        std::string const booksNotFound{ "���� �������� ����� " + std::to_string(yearPuplication) + " ���� �� ��������" };
        std::cout << booksNotFound << std::endl;
    }
}

void searchQueryByPublishingHouse(const std::vector<Book>& books)
{
    std::string const welcomeMessage{ "����� ����� �� ��������" };
    std::string publishingHouse{ enteryNewBookPublishingHouse(welcomeMessage) };
    std::vector<Book> booksByPublishingHouse(0);//������ ������ ����, ��� �������� ����������� �����
    findBooksByPublishingHouse(books, publishingHouse, booksByPublishingHouse);//����� ���� �� ������������
    if (booksByPublishingHouse.size() > 0)//���� ������ booksByPublishingHouse �� ������
    {
        printBooks(booksByPublishingHouse);//����� ��������� ����
    }
    else
    {
        std::string const booksNotFound{ "���� ������������ " + publishingHouse + " �� ��������" };
        std::cout << booksNotFound << std::endl;
    }
}

void searchQueryBooksOnIssue(const std::vector<Book>& books)
{
    std::string const welcomeMessage{ "����� ���� �� ������" };
    std::cout << welcomeMessage << std::endl;
    std::vector<Book> booksOnIssue(0);//������ ������ ����, ��� �������� ����������� �����
    findBooksOnIssue(books, booksOnIssue);//����� ���� �� ������
    if (booksOnIssue.size() > 0)//���� ������ booksOnIssue �� ������
    {
        printBooks(booksOnIssue);//����� ��������� ����
    }
    else
    {
        std::string const booksNotFound{ "���� �� ������ ���" };
        std::cout << booksNotFound << std::endl;
    }
}

void findBooksByAuthor(const std::vector<Book>& books, std::string const author, std::vector<Book>& outBooks)
{
    for (auto book : books)
    {
        if (book.author == author)
            outBooks.push_back(book);//���������� ����� � �������� ������
    }
}

void findBooksByYearPuolication(const std::vector<Book>& books, unsigned int const yearPuolication, std::vector<Book>& outBooks)
{
    for (auto book : books)
    {
        if (book.yearPuplication == yearPuolication)
            outBooks.push_back(book);//���������� ����� � �������� ������
    }
}

void findBooksByYearPuolicationMoreThen(const std::vector<Book>& books, unsigned int const minYearPuolication, std::vector<Book>& outBooks)
{
    for (auto book : books)
    {
        if (book.yearPuplication > minYearPuolication)
            outBooks.push_back(book);//���������� ����� � �������� ������
    }
}

void findBooksByPublishingHouse(const std::vector<Book>& books, std::string const publishingHouse, std::vector<Book>& outBooks)
{
    for (auto book : books)
    {
        if (book.publishingHouse == publishingHouse)
            outBooks.push_back(book);//���������� ����� � �������� ������
    }
}

void findBooksOnIssue(const std::vector<Book>& books, std::vector<Book>& outBooks)
{
    for (auto book : books)
    {
        if (book.status == bookStatus::BOOK_ON_ISSUE)
            outBooks.push_back(book);//���������� ����� � �������� ������
    }
}

void sortBooksByYearPublication(std::vector<Book> &books)
{
    std::sort(books.begin(), books.end(), sortByYearPublication);
}

void sortBooksByAuthor(std::vector<Book>& books)
{
    std::sort(books.begin(), books.end(), sortByAuthor);
}

void sortBooksByQuantityPage(std::vector<Book>& books)
{
    std::sort(books.begin(), books.end(), sortByQuantityPage);
}

bool sortByYearPublication(Book firstBook, Book secondBook)
{
    return firstBook.yearPuplication < secondBook.yearPuplication;
}

bool sortByAuthor(Book firstBook, Book secondBook)
{
    return firstBook.author < secondBook.author;
}

bool sortByQuantityPage(Book firstBook, Book secondBook)
{
    return firstBook.quantityPage < secondBook.quantityPage;
}

void printBooks(const std::vector<Book>& books)
{
    std::vector<size_t> columnSize{ 24,20,20,20,20,20,30,20 }; //������ �������
    std::vector<std::string> columnNames{ "��������������� �����","�����","��������","��� ����������","�������","����� �������","��������� ������������","����� �� ������" };//��������� �������
    drawTableRaw(columnSize, columnNames, true);//����� ���������
    for (size_t i{ 0 }; i < books.size(); ++i)//����� ����
    {
        std::vector<std::string> userData{};
        userData.push_back(std::to_string(books[i].registrationNumber)); //����������� �� int � string 
        userData.push_back(books[i].author);
        userData.push_back(books[i].name);
        userData.push_back(std::to_string(books[i].yearPuplication));//����������� �� int � string 
        userData.push_back(books[i].publishingHouse);
        userData.push_back(std::to_string(books[i].quantityPage));//����������� �� int � string 
        userData.push_back(std::to_string(books[i].lastReaderTicketNumber));//����������� �� int � string 
        userData.push_back(std::to_string(static_cast<int>(books[i].status)));//����������� �� ������������ � int, ����� � string 
        if (i < books.size() - 1)
            drawTableRaw(columnSize, userData);
        else
            drawTableRaw(columnSize, userData, true);//���� ����� ��������� ���������� ������ ������� 
    }
}
