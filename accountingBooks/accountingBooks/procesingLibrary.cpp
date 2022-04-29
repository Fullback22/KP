#include "procesingLibrary.h"

void printBooks(const std::vector<Book>& books)
{
    std::vector<size_t> columnSize{ 20,20,20,20,20,10,20,20 };
    std::vector<std::string> columnNames{ "Регистрационный номер","Автор","Название","Год публикации","Издание","Число страниц","Последний пользователь","Книга на выдачи" };
    drawTableRaw(columnSize, columnNames, true);
    for (size_t i{ 0 }; i < books.size(); ++i)
    {
        std::vector<std::string> userData{};
        userData.push_back(std::to_string(books[i].registrationNumber));
        userData.push_back(books[i].author);
        userData.push_back(books[i].name);
        userData.push_back(std::to_string(books[i].yearPuplication));
        userData.push_back(books[i].publishingHouse);
        userData.push_back(std::to_string(books[i].quantityPage));
        userData.push_back(std::to_string(books[i].lastReaderTicketNumber));
        userData.push_back(std::to_string(static_cast<int>(books[i].status)));
        if (i < books.size() - 1)
            drawTableRaw(columnSize, userData);
        else
            drawTableRaw(columnSize, userData, true);
    }
}
