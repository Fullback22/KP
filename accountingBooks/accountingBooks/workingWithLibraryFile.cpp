#include "workingWithLibraryFile.h"

bool downloadLibraryData(std::string const fileName, std::vector<Book>& booksInLibrary)
{
    std::ifstream fileWithLibraryData(fileName);
    if (fileWithLibraryData.is_open())
    {
        readLibraryDataFromFile(fileWithLibraryData, booksInLibrary);
        return true;
    }
    else
    {
        return false;
    }
}

void readLibraryDataFromFile(std::ifstream& fileWithData, std::vector<Book>& booksInLibrary)
{
    size_t bookNumber{};
    size_t stringNumber{};
    for (; !fileWithData.eof();) {
        std::string bufer;
        std::getline(fileWithData, bufer);
        switch (stringNumber) {
        case 0: {
            booksInLibrary.push_back(Book{});
            booksInLibrary[bookNumber].registrationNumber = atoi(bufer.c_str());
            ++stringNumber;
            break;
        }
        case 1: {
            booksInLibrary[bookNumber].author = bufer;
            ++stringNumber;
            break;
        }
        case 2: {
            booksInLibrary[bookNumber].name = bufer;
            ++stringNumber;
            break;
        }
        case 3: {
            booksInLibrary[bookNumber].yearPuplication = atoi(bufer.c_str());
            ++stringNumber;
            break;
        }
        case 4: {
            booksInLibrary[bookNumber].publishingHouse = bufer;
            ++stringNumber;
            break;
        }
        case 5: {
            booksInLibrary[bookNumber].quantityPage = atoi(bufer.c_str());
            ++stringNumber;
            break;
        }
        case 6: {
            booksInLibrary[bookNumber].lastReaderTicketNumber = atoi(bufer.c_str());
            ++stringNumber;
            break;
        }
        case 7: {
            booksInLibrary[bookNumber].status = bookStatus(atoi(bufer.c_str()));
            stringNumber = 0;
            ++bookNumber;
            break;
        }
        }
    }
}

void writeLibraryDataToFile(std::string const fileName, std::vector<Book> const* booksInLibrary)
{
    std::ofstream outFile(fileName, std::ofstream::out | std::ofstream::trunc);
    for (size_t i{ }; i < booksInLibrary->size(); ++i)
    {
        outFile << (*booksInLibrary)[i].registrationNumber << std::endl;
        outFile << (*booksInLibrary)[i].author << std::endl;
        outFile << (*booksInLibrary)[i].name << std::endl;
        outFile << (*booksInLibrary)[i].yearPuplication << std::endl;
        outFile << (*booksInLibrary)[i].publishingHouse << std::endl;
        outFile << (*booksInLibrary)[i].quantityPage << std::endl;
        outFile << (*booksInLibrary)[i].lastReaderTicketNumber << std::endl;
        outFile << static_cast<int>((*booksInLibrary)[i].status);
        if (i < booksInLibrary->size() - 1)
            outFile << std::endl;
    }

}
