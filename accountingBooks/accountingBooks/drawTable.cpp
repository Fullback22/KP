#include "drawTable.h"

void drawTableRaw(const std::vector<size_t>& columnSize, const std::vector<std::string>& data, bool drawLowerBorder)
{
    size_t rawSize{ mySum<size_t>(columnSize) };
    repetSimvol("-", rawSize);
    std::cout << std::endl;
    for (size_t i{}; i < columnSize.size(); ++i)
    {
        printDataInCell(columnSize[i], data[i]);
    }
    std::cout << std::endl;
    if (drawLowerBorder)
    {
        repetSimvol("-", rawSize);
        std::cout << std::endl;
    }
}

void printDataInCell(size_t const cellSize, std::string const data)
{
    if (data.size() <= cellSize)
    {
        size_t leftIndent{ (cellSize - data.size()) / 2 + data.size() };
        size_t rightIndent{ cellSize - leftIndent };
        std::cout << std::setw(leftIndent) << data << std::setw(rightIndent) << "|";
    }
    else
    {
        size_t maxNameLen{ cellSize - 1 };
        std::string cropData{ cropString(data, maxNameLen) };
        std::cout << cropData << "|";
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
    if (originalString.size() < maxLen)
        return originalString;
    else
    {
        std::string cropSimvol{ "..." };
        std::string crop{ originalString.begin(), originalString.begin() + maxLen - cropSimvol.size() };
        return crop + cropSimvol;
    }
}