#pragma 
#include <Windows.h>

#include "workingWithLibraryFile.h"
#include "workingWithUserFile.h"

//������������� ������� ����������� ��� �������
void setRusSettings();

//������� ������������� ��� �������� ��������� ������ � �������
//������� ��������� ��� ����� � �� ������������ ����, ������ �� ������ ��� �������� ����,
//��� ����� � �� �������������, ������ �� ������ ��� �������� �������������
void downloadData(std::string const libraryFileName, std::vector<Book>& books, std::string const usersFileName, std::vector<User>& users);

//������� ������������� ��� �������� � ����� ������ �� ��������������� ��������
//������� ��������� ��� ����� � ������� ���� �������� ������ ������������ ����, ������ �� ������ � ������� ����,
//��� ����� � ������� ���� �������� ������ �������������, ������ �� ������ � ������� �������������
void writeData(std::string const libraryFileName, const std::vector<Book>& books, std::string const usersFileName, const std::vector<User>& users);
