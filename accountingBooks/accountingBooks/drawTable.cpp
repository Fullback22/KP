#include "drawTable.h"

void drawTableRaw(const std::vector<size_t>& columnSize, const std::vector<std::string>& data, bool drawLowerBorder)
{
    size_t rawSize{ mySum<size_t>(columnSize) }; //определения ширины таблицы
    repetSimvol("-", rawSize); //вывод верхней границы строки
    std::cout << std::endl;
    for (size_t i{}; i < columnSize.size(); ++i)
    {
        printDataInCell(columnSize[i], data[i]); //ввод ячеек
    }
    std::cout << std::endl;
    if (drawLowerBorder) //если требутся ввести нижную границу
    {
        repetSimvol("-", rawSize); //вывод нижней границы строки
        std::cout << std::endl;
    }
}

void printDataInCell(size_t const cellSize, std::string const data)
{
    if (data.size() < cellSize) //если значение помешается в ячейку
    {
        size_t leftIndent{ (cellSize - data.size()) / 2 + data.size() }; //определение смешения слева
        size_t rightIndent{ cellSize - leftIndent }; //определение смешения справ
        std::cout << std::setw(leftIndent) << data << std::setw(rightIndent) << "|"; //установка смещения слева ввод значеня, дополнительное смещение
    }
    else
    {
        size_t maxNameLen{ cellSize - 1 }; //максимальный размер строки
        std::string cropData{ cropString(data, maxNameLen) }; //обрезание строки
        std::cout << cropData << "|";//вывод обрезанного значения
    }
}

void repetSimvol(std::string const simvol, size_t const repetNumber)
{
    for (size_t i{}; i < repetNumber; ++i)
    {
        std::cout << simvol;
    }
}

std::string cropString(std::string const originalString, size_t const maxLen)
{
    if (originalString.size() < maxLen) //если исходная строка меньше допустимой длины
        return originalString;
    else
    {
        std::string cropSimvol{ "..." }; //символ продолжения
        std::string crop{ originalString.begin(), originalString.begin() + maxLen - cropSimvol.size() }; //обрезания строки, от 0 индеса до индекса с номером maxLen-3 (3-размер символа продолжения)
        return crop + cropSimvol;
    }
}

