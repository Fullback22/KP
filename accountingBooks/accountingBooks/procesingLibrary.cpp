#include "procesingLibrary.h"

void searchQueryByAuthor(const std::vector<Book>& books)
{
    std::string const welcomeMessage{ "ѕоиск книги по автору" };
    std::string author{ enteryNewBookAuthor(welcomeMessage) };
    std::vector<Book> booksByAuthor(0);//пустой вектор книг, дл€ хранени€ результатов поиск
    findBooksByAuthor(books, author, booksByAuthor);//поиск книг по автору
    if (booksByAuthor.size() > 0)//если вектор booksByAuthor не пустой
    {
        printBooks(booksByAuthor);//вывод найденных книг
    }
    else
    {
        std::string const booksNotFound{ " ниг искомого автора " + author + " не найденно" };
        std::cout << booksNotFound << std::endl;
    }
}

void searchQueryByYearPuolication(const std::vector<Book>& books)
{
    std::string const welcomeMessage{ "ѕоиск книги по году публикации" };
    unsigned int yearPuplication{ enteryNewBookYearPuplication(welcomeMessage) };
    std::vector<Book> booksByYearPublication(0);//пустой вектор книг, дл€ хранени€ результатов поиск
    findBooksByYearPuolication(books, yearPuplication, booksByYearPublication);//поиск книг по году издани€
    if (booksByYearPublication.size() > 0)//если вектор booksByYearPublication не пустой
    {
        printBooks(booksByYearPublication);//вывод найденных книг
    }
    else
    {
        std::string const booksNotFound{ " ниг " + std::to_string(yearPuplication) + " года издани€ не найденно" };
        std::cout << booksNotFound << std::endl;
    }
}

void searchQueryByYearPuolicationMoreThen(const std::vector<Book>& books)
{
    std::string const welcomeMessage{ "ѕоиск книг опубликованных после:" };
    unsigned int yearPuplication{ enteryNewBookYearPuplication(welcomeMessage) };
    std::vector<Book> booksByYearPublication(0);//пустой вектор книг, дл€ хранени€ результатов поиск
    findBooksByYearPuolicationMoreThen(books, yearPuplication, booksByYearPublication);//поиск книг изданных после
    if (booksByYearPublication.size() > 0)//если вектор booksByYearPublication не пустой
    {
        printBooks(booksByYearPublication);//вывод найденных книг
    }
    else
    {
        std::string const booksNotFound{ " ниг изданных после " + std::to_string(yearPuplication) + " года не найденно" };
        std::cout << booksNotFound << std::endl;
    }
}

void searchQueryByPublishingHouse(const std::vector<Book>& books)
{
    std::string const welcomeMessage{ "ѕоиск книги по издателю" };
    std::string publishingHouse{ enteryNewBookPublishingHouse(welcomeMessage) };
    std::vector<Book> booksByPublishingHouse(0);//пустой вектор книг, дл€ хранени€ результатов поиск
    findBooksByPublishingHouse(books, publishingHouse, booksByPublishingHouse);//поиск книг по издательству
    if (booksByPublishingHouse.size() > 0)//если вектор booksByPublishingHouse не пустой
    {
        printBooks(booksByPublishingHouse);//вывод найденных книг
    }
    else
    {
        std::string const booksNotFound{ " ниг издательства " + publishingHouse + " не найденно" };
        std::cout << booksNotFound << std::endl;
    }
}

void searchQueryBooksOnIssue(const std::vector<Book>& books)
{
    std::string const welcomeMessage{ "ѕоиск книг на выдаче" };
    std::cout << welcomeMessage << std::endl;
    std::vector<Book> booksOnIssue(0);//пустой вектор книг, дл€ хранени€ результатов поиск
    findBooksOnIssue(books, booksOnIssue);//поиск книг на выдаче
    if (booksOnIssue.size() > 0)//если вектор booksOnIssue не пустой
    {
        printBooks(booksOnIssue);//вывод найденных книг
    }
    else
    {
        std::string const booksNotFound{ " ниг на выдаче нет" };
        std::cout << booksNotFound << std::endl;
    }
}

void findBooksByAuthor(const std::vector<Book>& books, std::string const author, std::vector<Book>& outBooks)
{
    for (auto book : books)
    {
        if (book.author == author)
            outBooks.push_back(book);//добавление книги в выходной вектор
    }
}

void findBooksByYearPuolication(const std::vector<Book>& books, unsigned int const yearPuolication, std::vector<Book>& outBooks)
{
    for (auto book : books)
    {
        if (book.yearPuplication == yearPuolication)
            outBooks.push_back(book);//добавление книги в выходной вектор
    }
}

void findBooksByYearPuolicationMoreThen(const std::vector<Book>& books, unsigned int const minYearPuolication, std::vector<Book>& outBooks)
{
    for (auto book : books)
    {
        if (book.yearPuplication > minYearPuolication)
            outBooks.push_back(book);//добавление книги в выходной вектор
    }
}

void findBooksByPublishingHouse(const std::vector<Book>& books, std::string const publishingHouse, std::vector<Book>& outBooks)
{
    for (auto book : books)
    {
        if (book.publishingHouse == publishingHouse)
            outBooks.push_back(book);//добавление книги в выходной вектор
    }
}

void findBooksOnIssue(const std::vector<Book>& books, std::vector<Book>& outBooks)
{
    for (auto book : books)
    {
        if (book.status == bookStatus::BOOK_ON_ISSUE)
            outBooks.push_back(book);//добавление книги в выходной вектор
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
    std::vector<size_t> columnSize{ 24,20,20,20,20,20,30,20 }; //размер колонок
    std::vector<std::string> columnNames{ "–егистрационный номер","јвтор","Ќазвание","√од публикации","»здание","„исло страниц","ѕоследний пользователь"," нига на выдачи" };//заголовки колонок
    drawTableRaw(columnSize, columnNames, true);//вывод заголовка
    for (size_t i{ 0 }; i < books.size(); ++i)//вывод книг
    {
        std::vector<std::string> userData{};
        userData.push_back(std::to_string(books[i].registrationNumber)); //конвертаци€ из int в string 
        userData.push_back(books[i].author);
        userData.push_back(books[i].name);
        userData.push_back(std::to_string(books[i].yearPuplication));//конвертаци€ из int в string 
        userData.push_back(books[i].publishingHouse);
        userData.push_back(std::to_string(books[i].quantityPage));//конвертаци€ из int в string 
        userData.push_back(std::to_string(books[i].lastReaderTicketNumber));//конвертаци€ из int в string 
        userData.push_back(std::to_string(static_cast<int>(books[i].status)));//конвертаци€ из перечислени€ в int, затем в string 
        if (i < books.size() - 1)
            drawTableRaw(columnSize, userData);
        else
            drawTableRaw(columnSize, userData, true);//если книга последн€€ нарисовать нижную границу 
    }
}
