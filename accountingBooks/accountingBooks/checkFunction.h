#pragma once
#include <iostream>
#include <string>
#include <vector>

//проверяет корректность ввода при выборе пунктов из последовательности (например пунктов меню)
//на вход подается значение которое надо проверить и максимальное возможное значение
//если ввод был корректен функция вернёт true иначе false
bool checkingCorrectnessInputForSequences(std::string const input, int const maxValue);
//проверяет корректность ввода без знаковых чисел
//на вход подается значение которое надо проверить
//если ввод был корректен функция вернёт true иначе false
bool checkingCorrectnessInputUnsignetInt(std::string const input);
//проверяет корректность ввода строковых значений
//на вход подается значение которое надо проверить
//если ввод был корректен функция вернёт true иначе false
bool checkingCorrectnessInputString(std::string const input);
//функция служит для подтверждения действий пользователя
//на вход подается сообщение об подтверждении какого-либо действия
//если пользователь подтверждает действие функция вернёт true иначе false
bool confirmationAction(std::string const message);