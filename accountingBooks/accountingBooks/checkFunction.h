#pragma once
#include <iostream>
#include <string>
#include <vector>

//��������� ������������ ����� ��� ������ ������� �� ������������������ (�������� ������� ����)
//�� ���� �������� �������� ������� ���� ��������� � ������������ ��������� ��������
//���� ���� ��� ��������� ������� ����� true ����� false
bool checkingCorrectnessInputForSequences(std::string const input, int const maxValue);
//��������� ������������ ����� ��� �������� �����
//�� ���� �������� �������� ������� ���� ���������
//���� ���� ��� ��������� ������� ����� true ����� false
bool checkingCorrectnessInputUnsignetInt(std::string const input);
//��������� ������������ ����� ��������� ��������
//�� ���� �������� �������� ������� ���� ���������
//���� ���� ��� ��������� ������� ����� true ����� false
bool checkingCorrectnessInputString(std::string const input);
//������� ������ ��� ������������� �������� ������������
//�� ���� �������� ��������� �� ������������� ������-���� ��������
//���� ������������ ������������ �������� ������� ����� true ����� false
bool confirmationAction(std::string const message);