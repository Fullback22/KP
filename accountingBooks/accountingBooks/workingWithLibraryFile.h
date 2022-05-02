#pragma once
#include <fstream>
#include <string>
#include <vector>

#include "Book.h"

//�������� �� ������� ����� � ����� ������ ������������ ����
//��������� ��� ����� � ��
//���� ���� ���������� ��������� ������� ����� true ����� false
bool fileWithLibraryIsOpen(std::string const fileName);

//�������� ������ �� ������������ ����� �� ����� � ������
//��������� ��� ����� � �� � ������ �� ������ ������������ ����
void downloadLibraryData(std::string const fileName, std::vector<Book>& booksInLibrary);

//������ ������ �� ����� ���� ������ � ������������ ������
//��������� ����� � �� � ������ �� ������ ������������ ����
void readLibraryDataFromFile(std::ifstream& fileWithData, std::vector<Book>& booksInLibrary);

//������ �� ������� � ���� ������ � ������������ ������
//��������� ��� ����� � �� � ��������� �� ������ ������������ ����
void writeLibraryDataToFile(std::string const fileName, std::vector<Book> const* booksInLibrary);