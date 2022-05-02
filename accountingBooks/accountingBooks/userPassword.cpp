#include "userPassword.h"

bool authorization(const std::vector<User>& users, User& newActivUser)
{
    system("cls");//очистка консоли
    std::string const loginMessage{ "Логин:" };
    std::cout << loginMessage << std::endl;
    std::string loginNewActivUser{};
    _flushall();//очистке всех входных буферов
    std::getline(std::cin, loginNewActivUser);//чтение строки с наличием " "
    std::string const passwordMessage{ "Пароль:" };
    std::cout << passwordMessage << std::endl;
    std::string passwordNewActivUser{ readPassword() };//ввод паспорта

    int indexNewActivUser{ findUserIndex(users, loginNewActivUser) };//поиск индекса пользователя по логину
    if (indexNewActivUser < 0) //индекс -1 пользователь не найден 
    {
        return 0;
    }
    else
    {
        std::string userSalt{ (users)[indexNewActivUser].salt };//считывание соли к паролю
        std::string inputHashPassword{ convertUserPasswordToHash(passwordNewActivUser + userSalt, loginNewActivUser) }; //ковертация введённого пароля с добавлением "соли" в хеш
        std::string userHashPassword{ (users)[indexNewActivUser].saltedHashPassword }; //верный хеш пароля

        if (userHashPassword == inputHashPassword)//верный хеш совподает с хэшем полученым из введённого пароля 
        {
            newActivUser = (users)[indexNewActivUser];//определение нового активного пользователя
            return 1;
        }
        else //пароли не совпали
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
    std::mt19937 gen{ rd() }; //генерация случайного сида
    double minSimvolIndex{ 33.0 };//минимальный номер сиволя в ASCII(нижняя граница генерации)
    double maxSimvolIndex{ 127.0 };//максимальный номер сиволя в ASCII(верхняя граница генерации)
    std::uniform_real_distribution<double> simvolGenerate{ minSimvolIndex, maxSimvolIndex };//равномерная генерация чисел из диапазона
    std::string salt{};//хранит результат генерирования "соли"
    for (size_t i{}; i < saltLen; ++i)
    {
        int newSimvol{ static_cast<int>(round(simvolGenerate(gen))) };//генерация номера символа, round округляет до целой части, после конвертируется в int
        salt.push_back(newSimvol);//добавление нового символа
    }
    return salt;
}

std::string convertUserPasswordToHash(std::string const passwordWithSalt, std::string const userName)
{
    size_t randomSeed{ userName.size() + passwordWithSalt.size() };//установка сида для генерации случайных чисел, на основе суммы числа элементов в логине и пароли с "солью"
    return hashFunction(passwordWithSalt, randomSeed);//результат хэширования
}

std::string readPassword()
{
    std::string password{};//хранит введённый пароль
    for (;;)
    {
        char simvol{ };
        simvol = _getch();// происход считывания клавиши без её вывода в кансоль и нажатия Enter
        if (simvol == '\r')//если введён Enter
            return password; //вернуть результат
        else if (simvol == '\b')//если нажат backspace
        {
            std::cout << "\b"<<" "<< "\b";//вернутся назад ввести пробел и опять вернутся назад
            if(password.size()>0) //пока в пароли есть символы
                password.pop_back();//удалять последний
        }
        else
        {
            password.push_back(simvol);//добавить введённый символ в пароль
            std::cout << "*";//вывести символ *
        }
    }
}

std::string hashFunction(std::string const toHash, int const randomSeed)
{
    srand(randomSeed);//устанвка сида для генерации случайных чисел
    std::string hash{};//переменная для хеш
    int sumSimvols{ 0 };
    for (size_t i{}; i < toHash.size(); ++i)
    {
        sumSimvols += toHash[i];//сумма индексов символов пароля по таблице ASCII
    }
    for (size_t i{}; i < toHash.size(); ++i)//для каждого из элементов пароля
    {
        double denominator{ static_cast<double>(rand()) }; //генерация знаменателя
        double firstPartHashElement{ sumSimvols / denominator };//первая часть элемента 
        double secondPartHashElement{ toHash[i] / denominator };//вторая часть элемента
        hash += std::to_string(firstPartHashElement + secondPartHashElement);//один элемент определяется как сумма двух частей, конвертируется в string и добовляется в hash
    }
    return hash;
}