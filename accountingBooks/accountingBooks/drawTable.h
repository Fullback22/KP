#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>

//������� ������� � ������� ���� �� ����� �������
//�� ���� �������� ������ ���������� ������� ������� �������, ������ �� ���������� ������� ���� ��������� � ������� �
//���� ����������� �� ������������� ��������� ������ ������� ������
void drawTableRaw(const std::vector<size_t>& columnSize, const std::vector<std::string>& data, bool drawLowerBorder = false);
//������� ������� �������� � ���� �� ����� �������
//�� ���� ������� ������ ������ � �������� ������� ���� ���� ���������
void printDataInCell(size_t const cellSize, std::string const data);
//������� ������ ��� ���������� ���������� �������� �������� ����� ���
//�� ���� ������� ������ ������� ���� ��������� � ����� ��� ������� ��� ���� �������
void repetSimvol(std::string const simvol, size_t const repetNumber);
//������� �������� �������� ������ ��� �������� ������, ������������� ������� ���������� ���
//�� ���� ������� ������ ������� ���� ��������� � ������������ ���������� �����
std::string cropString(std::string const originalString, size_t const maxLen);

//������ ������� ������������ ��������� �������
//�� ���� �������� ������ �������� �������� ���� �����������
//������� ���������� ����� ��������� �������
template <typename T>
T mySum(const std::vector<T>& inputVector)
{
	T outSumm{};
	for (auto element : inputVector)
	{
		outSumm += element;
	}
	return outSumm;
}