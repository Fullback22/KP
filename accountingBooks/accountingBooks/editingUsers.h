#pragma once
#include <vector>
#include <iomanip>
#include <stdlib.h>

#include "User.h"
#include "userPassword.h"
#include "drawTable.h"

//������� ������� ������������(������������ �� ���������)
//��������� ������ �� ������ �������������
void creatFirstUser(std::vector<User>& users);

//������� ��������� ������ �� ���������� ������ ������������ � ���� ������ ���������������
//��������� ������ �� ������ �������������
void addUsersByAdministrator(std::vector<User>& users);

//������� ��������� ������ �� ���������� ������ ������������ � ���� ������ ������� �������������
//��������� ������ �� ������ �������������
void addUsersBySimpleUser(std::vector<User>& users);

//������� ������ ��� ��������� ������ � ������ ��� ������������
//��������� ������ �� ������ ������������� � ��������� ������� ������ ��������� ��� ����� ������
//���������� ������������ � �������� ������� � �������
User setUserLoginAndPassword(const std::vector<User>& users, std::string const welcomeMessage);

//������� ������ ��� ����� ������ ������������
//��������� ������ �� ������ ������������� � ��������� ������� ������ ��������� ��� ����� ������
//���������� ������ ��������������� ����������� � ������
std::string enteryNewUserLogin(const std::vector<User>& users, std::string const welcomeMessage);

//������� ������ ��� ����� ������ ������������
//��������� ��������� ������� ������ ��������� ��� ����� ������
//���������� ������ ��������������� ����������� � ������
std::string enteryNewUserPasswor(std::string const welcomeMessage);

//������� ������ ��� ����� ���� ������������(������������ ��� �������������)
//��������� ��������� ������� ������ ��������� ��� ����� ������
//���������� ����� ������������
userRole enteryNewUserRole(std::string const welcomeMessage);

//������� ������ ��� ����� ������� ������������(������� ��� ������������)
//��������� ��������� ������� ������ ��������� ��� ����� ������ � 
//������� ���� ������������ ��� �������� �������� ������
//���� ������������ ������������ ������� ����� true ����� false
bool enteryNewUserAccess(std::string const welcomeMessage, userRole const role);

//����� ������� ��� ������� �������� ������������ � �������� �������
//�� ���� ��������� ������ �� ������ ������������� � ������� �����
//���� ������������ � ����� ������� ������ ������� ����� ��� ������ ����� -1
int findUserIndex(const std::vector<User>& users, std::string const login);

//�������� �� ������������� ������������ � �������� �������
//�� ���� ��������� ������ �� ������ ������������� � ������� �����
//���� ������������ � ����� ������� ������ ������� ����� true ����� false
bool loginExists(const std::vector<User>& users, std::string const login);

//������� ��������� ������ �� ��������� ���������� � ������������ ���������������
//��������� ������ �� ������ ������������� � ����� ��������� ������������
void updateUserDataByAdministrator(std::vector<User>& users, std::string const activUserLogin);

//������� ������ ��� ����� ���� ���������� � ������������
//��������� ������ �� ������ ������������� � ��������� ������� ������ ��������� ��� ����� ������
//���������� ������������ � �������� �����������
User setAllUserData(const std::vector<User>& users, std::string const welcomeMessage);

//������� ������ ��� ��������� ������ � ������������ � ���� ������
//��������� ������ �� ������ �������������, ������ �� ������������ �������� �������� ����������� �������� �
//����� ��������� ������������
//���� ���������� ������ ������ ������� ������� ����� true ����� false
bool updateUserData(const std::vector<User>& users, User& updatedUser, std::string const activUserLogin);

//������� ��������� ������ �� �������� ������������ ���������������
//��������� ������ �� ������ ������������� � ����� ��������� ������������
void deleteUserDataByAdministrator(std::vector<User>& users, std::string const activUserLogin);

//������� ������ ��� �������� ������������ �� ���� ������
//��������� ������ �� ������ �������������, ������ ������������ ������������ � ����� ��������� ������������
//���� ������������ ����� ������� ����� true ����� false
bool deleteUser(std::vector<User>& const users, size_t const indexDeletedUser, std::string const activUserLogin);

//������� ��������� ������ �� ��������� ������������ ���������������
//��������� ������ �� ������ �������������
void activationUserByAdministrator(std::vector<User>& users);

//������� ��������� ������ �� ���������� ������������ ���������������
//��������� ������ �� ������ ������������� � ����� ��������� ������������
void blockUserByAdministrator(std::vector<User>& users, std::string const activUserLogin);

//����� ������ � ���� �������������
//��������� ������ �� ������ �������������
void printUsers(const std::vector<User> &users);
