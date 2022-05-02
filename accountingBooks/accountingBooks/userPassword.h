#pragma once
#include <iostream>
#include <string>
#include <random>
#include <conio.h>

#include "checkFunction.h"
#include "editingUsers.h"

//������� �����������
//��������� ������ �� ������ ������������� � ������ �� ������ ��������� ������������
//��������� ������� �������� ������ �� ������ ��������� ������������, ��������� ������ ����������������� ������������
//���� ����������� ��� �������� ������� ����� true ����� false
bool authorization(const std::vector<User>& users, User& newActivUser);

//������� �������� ����� � ������ ��� ������������
//��������� ����� ������������
//���������� ������ � "�����" ��� ������������
std::string createSaltForUser(std::string const userName);

//������� ��������� �����
//��������� �������� ������ "����"
//���������� ������ � "�����"
std::string generateSalt(size_t const saltLen);

//������� �������� ������ � ������� � ���
//��������� ������ � "�����" � ����� ������������
//���������� ��� ������
std::string convertUserPasswordToHash(std::string const passwordWithSalt, std::string const userName);

//������� ��� ������ ������ � �������, �������� ������� �� ��������� *
//���������� ������ � �������
std::string readPassword();

//������� �����������
//��������� �������� ������� ���� ���������� � ����� ���� ��� ������� random
//���������� ���
std::string hashFunction(std::string const toHash, int const randomSeed);