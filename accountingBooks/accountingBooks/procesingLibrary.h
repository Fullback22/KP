#pragma once
#include <iostream>
#include <string>
#include <algorithm>

#include "editingLibrary.h"
#include "drawTable.h"
#include "Book.h"

//������ �� ����� ����� �� ������
//��������� ������ �� ������ ����
void searchQueryByAuthor(const std::vector<Book>& books);

//������ �� ����� ����� �� ���� �������
//��������� ������ �� ������ ����
void searchQueryByYearPuolication(const std::vector<Book>& books);

//������ �� ����� ����� �������� ����� ��������� ����
//��������� ������ �� ������ ����
void searchQueryByYearPuolicationMoreThen(const std::vector<Book>& books);

//������ �� ����� ����� �� ������������
//��������� ������ �� ������ ����
void searchQueryByPublishingHouse(const std::vector<Book>& books);

//������ �� ����� ���� ����������� �� ������
//��������� ������ �� ������ ����
void searchQueryBooksOnIssue(const std::vector<Book>& books);

//������� ������ ����� �� ������
//��������� ������ �� ������ ����, �������� ������, ������ �� ������ ���� ��������������� �������
void findBooksByAuthor(const std::vector<Book>& books, std::string const author, std::vector<Book>& outBooks);

//������� ������ ����� �� ���� �������
//��������� ������ �� ������ ����, ������� ��� �������, ������ �� ������ ���� ��������������� �������
void findBooksByYearPuolication(const std::vector<Book>& books, unsigned int const yearPuolication, std::vector<Book>& outBooks);

//������� ������ ����� �������� ����� ��������� ����
//��������� ������ �� ������ ����, ��������� ��� �������, ������ �� ������ ���� ��������������� �������
void findBooksByYearPuolicationMoreThen(const std::vector<Book>& books, unsigned int const minYearPuolication, std::vector<Book>& outBooks);

//������� ������ ����� �� ������������
//��������� ������ �� ������ ����, �������� ������������, ������ �� ������ ���� ��������������� �������
void findBooksByPublishingHouse(const std::vector<Book>& books, std::string const publishingHouse, std::vector<Book>& outBooks);

//������� ������ ���� ����������� �� ������
//��������� ������ �� ������ ���� � ������ �� ������ ���� ��������������� �������
void findBooksOnIssue(const std::vector<Book>& books, std::vector<Book>& outBooks);

//���������� ���� �� ���� �������
//��������� ������ �� ������ ����
//��������� ������� ������ ��������������� �� ���� �������
void sortBooksByYearPublication(std::vector<Book> &books);

//���������� ���� �� ������
//��������� ������ �� ������ ����
//��������� ������� ������ ��������������� �� �����
void sortBooksByAuthor(std::vector<Book> &books);

//���������� ���� �� ����� �������
//��������� ������ �� ������ ����
//��������� ������� ������ ��������������� �� ����� �������
void sortBooksByQuantityPage(std::vector<Book> &books);

//���������� �� ���� ���� �������
//������� ��������� ������������ �����
//���� ��� ������� ������ ����� ������ ������ ������� ����� true ����� false
bool sortByYearPublication(Book firstBook, Book secondBook);

//���������� �� ���� ������
//������� ��������� ������������ �����
//���� ����� ������ ����� � ���������� ������� ��������� ����� ������� ������ ������� ����� true ����� false
bool sortByAuthor(Book firstBook, Book secondBook);

//���������� �� ���� ����� �������
//������� ��������� ������������ �����
//���� ����� ������� ������ ����� ������ ������ ������� ����� true ����� false
bool sortByQuantityPage(Book firstBook, Book secondBook);

//����� ������ �� ���� ������
//��������� ������ �� ������ ����
void printBooks(const std::vector<Book>& books);



