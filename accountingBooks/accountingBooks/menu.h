#pragma once
#include <iostream>
#include "editingUsers.h"
#include "editingLibrary.h"
#include "procesingLibrary.h"
#include "userPassword.h"
#include "checkFunction.h"

//���� ����� � �������
//��������� ������ �� ������ ������������� � ������ �� ������ ������������ ����
void inputMenu(std::vector<User>& users, std::vector<Book>& booksInLibrary);

//������� ���� ������������
//��������� ������ �� ������ ������������ ���� � ��������� ������������
void simpleUserMenu(std::vector<Book>& booksInLibrary, User const activUser);

//������� ���� ��������������
//��������� ������ �� ������ �������������, ������ �� ������ ������������ ����  � ��������� ������������
void administratorMenu(std::vector<User>& users, std::vector<Book>& booksInLibrary, User const activUser);

//���� ��������� ���������� �������������
//��������� ������ �� ������ ������������� � ��������� ������������
void menuEditingUsers(std::vector<User>& users, User const activUser);

//���� ��������� ���������� ������������ ����
//��������� ������ �� ������ ������������ ����
void menuEditingLibrary(std::vector<Book>& booksInLibrary);

//���� ��������� ������������ ����
//��������� ������ �� ������ ������������ ����
void menuProcessingLibrary(std::vector<Book>& booksInLibrary);

//���� ����� ���������� ����
//��������� ������ �� ������ ������������ ����
void menuSortedBooks(std::vector<Book>& booksInLibrary);

//���� ������ ����
//��������� ������ �� ������ ������������ ����
void menuSearcBooks(const std::vector<Book>& booksInLibrary);

//�������� �� ��������� ������������
//���� ������������ ����������� ������� ����� true ����� false
bool isActivatedUser(User const user);