#include "workingWithLibraryFile.h"

bool fileWithLibraryIsOpen(std::string const fileName)
{
    std::ifstream fileWithLibraryData(fileName);//открытие файла
    if (fileWithLibraryData.is_open())//файл открыт
        return true;
    else
        return false;
}

void downloadLibraryData(std::string const fileName, std::vector<Book>& booksInLibrary)
{
    std::ifstream fileWithLibraryData(fileName);
    if (fileWithLibraryIsOpen(fileName))//если файл открыт
    {
        readLibraryDataFromFile(fileWithLibraryData, booksInLibrary);//чтение данных из файла
    }
}

void readLibraryDataFromFile(std::ifstream& fileWithData, std::vector<Book>& booksInLibrary)
{
    size_t bookNumber{};//переменная хранения номера книги
    size_t stringNumber{};//переменная хранения номера строки
    for (; !fileWithData.eof();) {//пока файл не закончился
        std::string bufer;//буфер для хранения строки
        std::getline(fileWithData, bufer);//чтение строки
        switch (stringNumber) {
        case 0: {
            booksInLibrary.push_back(Book{});//добавление книги
            booksInLibrary[bookNumber].registrationNumber = atoi(bufer.c_str());//установка регистрационного номера, конвертация из string в int
            ++stringNumber;//увеличенияе номера строки на 1
            break;
        }
        case 1: {
            booksInLibrary[bookNumber].author = bufer;//установка автора
            ++stringNumber;//увеличенияе номера строки на 1
            break;
        }
        case 2: {
            booksInLibrary[bookNumber].name = bufer;//установка названия книги
            ++stringNumber;//увеличенияе номера строки на 1
            break;
        }
        case 3: {
            booksInLibrary[bookNumber].yearPuplication = atoi(bufer.c_str());//установка года издания, конвертация из string в int
            ++stringNumber;//увеличенияе номера строки на 1
            break;
        }
        case 4: {
            booksInLibrary[bookNumber].publishingHouse = bufer;//установка издательства
            ++stringNumber;//увеличенияе номера строки на 1
            break;
        }
        case 5: {
            booksInLibrary[bookNumber].quantityPage = atoi(bufer.c_str());//установка число страниц, конвертация из string в int
            ++stringNumber;//увеличенияе номера строки на 1
            break;
        }
        case 6: {
            booksInLibrary[bookNumber].lastReaderTicketNumber = atoi(bufer.c_str());//установкачитательского билета, конвертация из string в int
            ++stringNumber;//увеличенияе номера строки на 1
            break;
        }
        case 7: {
            booksInLibrary[bookNumber].status = bookStatus(atoi(bufer.c_str()));//установка статуса книги, конвертация из string в int
            stringNumber = 0;//обнуление номера строки
            ++bookNumber; //увеличение номера книги на 1
            break;
        }
        }
    }
}

void writeLibraryDataToFile(std::string const fileName, std::vector<Book> const* booksInLibrary)
{
    std::ofstream outFile(fileName, std::ofstream::out | std::ofstream::trunc);//открытие файла для записи и его очистка
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
            outFile << std::endl;//если книга не последняя перейти на новую строку
    }

}
