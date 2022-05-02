#include "checkFunction.h"

bool checkingCorrectnessInputForSequences(std::string const input, int const maxValue)
{
    std::string const trueAnswer{ "0123456789" };//�������� ����������� ��� ����� ��������
    size_t index{ input.find_first_not_of(trueAnswer) };//����� ������� ������� ������� �� ���������������� �������
    if (index == std::string::npos)//���� ������ ������
    {
        int inputToInt{ std::atoi(input.c_str()) };
        if (inputToInt <= maxValue)//��������, ��� �������� ����� �� ������ �� �������� �������
            return true;
    }
    return false;
}

bool checkingCorrectnessInputUnsignetInt(std::string const input)
{
    std::string const trueAnswer{ "0123456789" };//�������� ����������� ��� ����� ��������, �.�. ��� ������� ������ ����� 
    size_t index{ input.find_first_not_of(trueAnswer) };//����� ������� ������� ������� �� ���������������� �������
    if (index == std::string::npos)//���� ������ ������
        return true;
    else
        return false;
}

bool checkingCorrectnessInputString(std::string const input)
{
    std::string const falseAnswer{ " " }; //������� ������
    size_t index{ input.find_first_not_of(falseAnswer) }; //����� ������� ������� ������� �� ���������������� ������� �������
    if (index == std::string::npos) //���� ������ ������, �.�. ���� ������� ������ �� ��������
        return false;
    else
        return true;
}

bool confirmationAction(std::string const message)
{
    system("cls");//������� �������
    for (; ; )
    {
        std::string const addToMessage{ "\n0.������\n1.��" };
        std::cout << message + addToMessage << std::endl;
        std::string answer{};
        _flushall();//������� ���� ������� �������
        std::getline(std::cin, answer); //������ ������ � �������� " "
        int const maxValue{ 1 };
        if (checkingCorrectnessInputForSequences(answer, maxValue)) //���� ���� ���������
        {
            return std::atoi(answer.c_str()); //������� 0 ��� 1
        }
        else
        {
            system("cls");//������� �������
            std::string const errorInput{ "������������ ����. ������� 0(������) ��� 1(��)" };
            std::cout << errorInput << std::endl;
        }
    }
}
