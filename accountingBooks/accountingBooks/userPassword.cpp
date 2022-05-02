#include "userPassword.h"

bool authorization(const std::vector<User>& users, User& newActivUser)
{
    system("cls");//������� �������
    std::string const loginMessage{ "�����:" };
    std::cout << loginMessage << std::endl;
    std::string loginNewActivUser{};
    _flushall();//������� ���� ������� �������
    std::getline(std::cin, loginNewActivUser);//������ ������ � �������� " "
    std::string const passwordMessage{ "������:" };
    std::cout << passwordMessage << std::endl;
    std::string passwordNewActivUser{ readPassword() };//���� ��������

    int indexNewActivUser{ findUserIndex(users, loginNewActivUser) };//����� ������� ������������ �� ������
    if (indexNewActivUser < 0) //������ -1 ������������ �� ������ 
    {
        return 0;
    }
    else
    {
        std::string userSalt{ (users)[indexNewActivUser].salt };//���������� ���� � ������
        std::string inputHashPassword{ convertUserPasswordToHash(passwordNewActivUser + userSalt, loginNewActivUser) }; //���������� ��������� ������ � ����������� "����" � ���
        std::string userHashPassword{ (users)[indexNewActivUser].saltedHashPassword }; //������ ��� ������

        if (userHashPassword == inputHashPassword)//������ ��� ��������� � ����� ��������� �� ��������� ������ 
        {
            newActivUser = (users)[indexNewActivUser];//����������� ������ ��������� ������������
            return 1;
        }
        else //������ �� �������
        {
            return 0;
        }
    }
}


std::string createSaltForUser(std::string const userName)
{
    return generateSalt(userName.size());
}

std::string generateSalt(size_t const saltLen)
{
    std::random_device rd{};
    std::mt19937 gen{ rd() }; //��������� ���������� ����
    double minSimvolIndex{ 33.0 };//����������� ����� ������ � ASCII(������ ������� ���������)
    double maxSimvolIndex{ 127.0 };//������������ ����� ������ � ASCII(������� ������� ���������)
    std::uniform_real_distribution<double> simvolGenerate{ minSimvolIndex, maxSimvolIndex };//����������� ��������� ����� �� ���������
    std::string salt{};//������ ��������� ������������� "����"
    for (size_t i{}; i < saltLen; ++i)
    {
        int newSimvol{ static_cast<int>(round(simvolGenerate(gen))) };//��������� ������ �������, round ��������� �� ����� �����, ����� �������������� � int
        salt.push_back(newSimvol);//���������� ������ �������
    }
    return salt;
}

std::string convertUserPasswordToHash(std::string const passwordWithSalt, std::string const userName)
{
    size_t randomSeed{ userName.size() + passwordWithSalt.size() };//��������� ���� ��� ��������� ��������� �����, �� ������ ����� ����� ��������� � ������ � ������ � "�����"
    return hashFunction(passwordWithSalt, randomSeed);//��������� �����������
}

std::string readPassword()
{
    std::string password{};//������ �������� ������
    for (;;)
    {
        char simvol{ };
        simvol = _getch();// �������� ���������� ������� ��� � ������ � ������� � ������� Enter
        if (simvol == '\r')//���� ����� Enter
            return password; //������� ���������
        else if (simvol == '\b')//���� ����� backspace
        {
            std::cout << "\b"<<" "<< "\b";//�������� ����� ������ ������ � ����� �������� �����
            if(password.size()>0) //���� � ������ ���� �������
                password.pop_back();//������� ���������
        }
        else
        {
            password.push_back(simvol);//�������� �������� ������ � ������
            std::cout << "*";//������� ������ *
        }
    }
}

std::string hashFunction(std::string const toHash, int const randomSeed)
{
    srand(randomSeed);//�������� ���� ��� ��������� ��������� �����
    std::string hash{};//���������� ��� ���
    int sumSimvols{ 0 };
    for (size_t i{}; i < toHash.size(); ++i)
    {
        sumSimvols += toHash[i];//����� �������� �������� ������ �� ������� ASCII
    }
    for (size_t i{}; i < toHash.size(); ++i)//��� ������� �� ��������� ������
    {
        double denominator{ static_cast<double>(rand()) }; //��������� �����������
        double firstPartHashElement{ sumSimvols / denominator };//������ ����� �������� 
        double secondPartHashElement{ toHash[i] / denominator };//������ ����� ��������
        hash += std::to_string(firstPartHashElement + secondPartHashElement);//���� ������� ������������ ��� ����� ���� ������, �������������� � string � ����������� � hash
    }
    return hash;
}