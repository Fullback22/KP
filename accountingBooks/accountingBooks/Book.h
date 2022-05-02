#pragma once
#include <iostream>
//������������ ���������� ��������� ������ ����
enum class bookStatus
{
    BOOK_IN_LIBRARY, //����� � ����������
    BOOK_ON_ISSUE //����� �� ������
};
//��������� �������� ������ � �����
struct Book
{
    unsigned int registrationNumber{}; //��������������� �����
    std::string author{}; //�����
    std::string name{}; //�������� �����
    unsigned int yearPuplication{}; //��� �������
    std::string publishingHouse{}; //������������
    unsigned int quantityPage{}; //����� �������
    unsigned int lastReaderTicketNumber{}; //����� ������������� ������ ���������� ��������
    bookStatus status{}; //������ �����
};