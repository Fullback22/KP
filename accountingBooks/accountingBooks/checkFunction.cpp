#include "checkFunction.h"

bool checkingCorrectnessInputForSequences(std::string const input, int const maxValue)
{
    std::string const trueAnswer{ "0123456789" };//перечень разрешонных для ввода символов
    size_t index{ input.find_first_not_of(trueAnswer) };//поиск индексо первого символа не соответствующего перечню
    if (index == std::string::npos)//если индекс пустой
    {
        int inputToInt{ std::atoi(input.c_str()) };
        if (inputToInt <= maxValue)//проверка, что введённое число не выходи за заданные пределы
            return true;
    }
    return false;
}

bool checkingCorrectnessInputUnsignetInt(std::string const input)
{
    std::string const trueAnswer{ "0123456789" };//перечень разрешонных для ввода символов, т.е. что введены только числа 
    size_t index{ input.find_first_not_of(trueAnswer) };//поиск индексо первого символа не соответствующего перечню
    if (index == std::string::npos)//если индекс пустой
        return true;
    else
        return false;
}

bool checkingCorrectnessInputString(std::string const input)
{
    std::string const falseAnswer{ " " }; //искомые символ
    size_t index{ input.find_first_not_of(falseAnswer) }; //поиск индексо первого символа не соответствующего перечню искомых
    if (index == std::string::npos) //если индекс пустой, т.е. ввод состоит только из пробелов
        return false;
    else
        return true;
}

bool confirmationAction(std::string const message)
{
    system("cls");//очистка консоли
    for (; ; )
    {
        std::string const addToMessage{ "\n0.Отмена\n1.Да" };
        std::cout << message + addToMessage << std::endl;
        std::string answer{};
        _flushall();//очистке всех входных буферов
        std::getline(std::cin, answer); //чтение строки с наличием " "
        int const maxValue{ 1 };
        if (checkingCorrectnessInputForSequences(answer, maxValue)) //если ввод корректен
        {
            return std::atoi(answer.c_str()); //возврот 0 или 1
        }
        else
        {
            system("cls");//очистка консоли
            std::string const errorInput{ "Некорректный ввод. Введите 0(отмена) или 1(ОК)" };
            std::cout << errorInput << std::endl;
        }
    }
}
