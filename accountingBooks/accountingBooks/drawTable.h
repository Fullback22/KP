#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>

//функци€ выводит в консоль одну из строк таблицы
//на вход подаетс€ вектор содержаший размеры каждого столбца, вектор со значени€ми которые надо поместить в столбцы и
//флаг указывающий на необходимость рисовани€ нижней границы строки
void drawTableRaw(const std::vector<size_t>& columnSize, const std::vector<std::string>& data, bool drawLowerBorder = false);
//функци€ выводит значени€ в одну из €чеек таблицы
//на вход подаЄтс€ размер €чейки и значение которое туда надо поместить
void printDataInCell(size_t const cellSize, std::string const data);
//функци€ служит дл€ повторени€ одинаковых символов заданное число раз
//на вход подаЄтс€ символ который надо повторить и число раз сколько его надо вывести
void repetSimvol(std::string const simvol, size_t const repetNumber);
//функци€ обрезает исходную строку под заданный размер, отсутствующие символы замен€ютс€ ЂЕї
//на вход подаЄтс€ строка которую надо проверить и максимальна€ допустима€ длина
std::string cropString(std::string const originalString, size_t const maxLen);

//шаблон функции суммировани€ элементов вектора
//на вход подаетс€ вектор элементы которого надо суммировать
//функци€ возврощает сумму элементов вектора
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