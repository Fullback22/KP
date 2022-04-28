#include "menu.h"

void inputMenu(std::vector<User>& users)
{
    for (; ; )
    { 
        std::string const message{ "1.Войти\n2.Регистрация\n0.Завершение работы" };
        std::cout << message << std::endl;
        std::string answer{};
        std::cin >> answer;
        std::string trueInput{ "012" };
        if (checkingCorrectnessInput(answer, trueInput))
        {
            switch (std::atoi(answer.c_str()))
            {
            case 1:
            {
                User activUser{};
                if (authorization(&users, activUser))
                {
                    system("cls");
                    std::string const welcomeMessage{ "Приветствуем " + activUser.login + "!"};
                    std::cout << welcomeMessage << std::endl;
                    if (activUser.role == userRole::SIMPLE_USER)
                    {
                        simpleUserMenu(activUser);
                    }
                    else
                    {
                        administratorMenu(users, activUser);
                    }
                }
                else
                {
                    system("cls");
                    std::string const authorizationError{ "Не верный логин или пароль." };
                    std::cout << authorizationError << std::endl;
                }
                break;
            }
            case 2:
            {
                addUsersBySimpleUser(users);
                break;
            }
            case 0:
            {
                return;
                break;
            }
            }
        }
        else
        {
            system("cls");
            std::string const errorInput{ "Некорректный ввод. Попробуйте ещё раз." };
            std::cout << errorInput << std::endl;
            std::cout << message << std::endl;
        }
    }
}

bool authorization(std::vector<User>* const users, User& newActivUser)
{
    system("cls");
    std::string const loginMessage{ "Логин:" };
    std::cout << loginMessage << std::endl;
    std::string loginNewActivUser{};
    std::cin >> loginNewActivUser;

    std::string const passwordMessage{ "Пароль:" };
    std::cout << passwordMessage << std::endl;
    std::string passwordNewActivUser{ readPassword() };

    int indexNewActivUser{ findUserIndex(users, loginNewActivUser) };
    if (indexNewActivUser < 0)
    {
        return 0;
    }
    else
    {
        std::string userSalt{ (*users)[indexNewActivUser].salt };
        std::string inputHashPassword{ convertUserPasswordToHash(passwordNewActivUser + userSalt, loginNewActivUser) };
        std::string userHashPassword{ (*users)[indexNewActivUser].saltedHashPassword };

        if (userHashPassword == inputHashPassword)
        {
            newActivUser = (*users)[indexNewActivUser];
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void simpleUserMenu(User const activUser)
{
    if (isActivatedUser(activUser))
    {
        std::string const welcomeMessage{ "Приветствуем " + activUser.login + "!" };
        std::cout << welcomeMessage << std::endl;
    }
    else
    {
        std::string userNotActivatedMessage{ "Пользователь " + activUser.login + " ещй не активирован. Ожидайте подтвержение записи администратором." };
        std::cout << userNotActivatedMessage << std::endl;
    }
}

void administratorMenu(std::vector<User>& users, User const activUser)
{
    if (isActivatedUser(activUser))
    {
        for (; ; )
        {
            std::string const welcomeMessage{ "Выберите режим работы:\n1.Управление данными пользователй\n2.Управление данными библиотеки\n3.Обработка данных библиотеки\n0.Назад" };
            std::cout << welcomeMessage << std::endl;
            std::string answer{};
            std::cin >> answer;
            std::string const correctAnswer{ "0123" };
            if (checkingCorrectnessInput(answer, correctAnswer))
            {
                switch (std::atoi(answer.c_str()))
                {
                case 1: {
                    break;
                }
                case 2: {
                    break;
                }
                case 3: {
                    break;
                }
                case 0: {
                    system("cls");
                    return;
                }
                }
            }
            else
            {
                system("cls");
                std::string const errorInput{ "Некорректный ввод. Попробуйте ещё раз." };
                std::cout << errorInput << std::endl;
            }
        }
    }
    else
    {
        std::string userNotActivatedMessage{ "Пользователь " + activUser.login + " ещй не активирован. Ожидайте подтвержение записи администратором." };
        std::cout << userNotActivatedMessage << std::endl;
    }
}

bool isActivatedUser(User const user)
{
    return user.access;
}
