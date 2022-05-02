// accountingBooks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "forMainFunction.h"
#include "menu.h"

int main()
{
    setRusSettings();
    std::string const FILE_NAME_WITH_LIBRARY_DB{ "libraryDB.txt" };// ��������� ��� �������� ����� ����� � �� ������������ ����
    std::vector<Book> booksInLibrary{};// ���������� ������� ��� �������� ���������� ������������ ����
    std::string const FILE_NAME_WITH_USERS{ "users1.txt" };// ��������� ��� �������� ����� ����� � �� �������������
    std::vector<User> users{};// ���������� ������� ��� �������� ���������� �������������

    if (fileWithLibraryIsOpen(FILE_NAME_WITH_LIBRARY_DB))
    {
        downloadData(FILE_NAME_WITH_LIBRARY_DB, booksInLibrary, FILE_NAME_WITH_USERS, users);
        inputMenu(users, booksInLibrary);
        writeData(FILE_NAME_WITH_LIBRARY_DB, booksInLibrary, FILE_NAME_WITH_USERS, users);
    }
    else
    {
        std::string const dbError{ "������. ���� � ����� ������ ���������� �� ������. ��������� ���������." };//��������� �������� ��������� �� ������ ����������� � ��
        std::cout << dbError << std::endl;
        system("pause");//�����, ������������� ��������������� �������� �������
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer wi
// ndow to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
