#include "menu.h"

void inputMenu(std::vector<User>& users, std::vector<Book>& booksInLibrary)
{
    for (; ; )
    { 
        std::string const message{ "1.Войти\n2.Регистрация\n0.Завершение работы" };
        std::cout << message << std::endl;
        std::string answer{};
        _flushall();//очистке всех входных буферов
        std::getline(std::cin, answer);//чтение строки с наличием " "
        int const maxAnswer{ 2 }; //возможные пункты 0,1,2
        if (checkingCorrectnessInputForSequences(answer, maxAnswer))//проверка корректности ввода
        {
            switch (std::atoi(answer.c_str())) //конвертация string из в int
            {
            case 1:
            {
                User activUser{}; // авторизораванный пользователь
                if (authorization(users, activUser))
                {
                    system("cls");//очистка консоли
                    std::string const welcomeMessage{ "Приветствуем " + activUser.login + "!"};
                    std::cout << welcomeMessage << std::endl;
                    if (activUser.role == userRole::SIMPLE_USER)
                    {
                        simpleUserMenu(booksInLibrary, activUser);//меню пользователя
                    }
                    else
                    {
                        administratorMenu(users, booksInLibrary, activUser);//меню администратора
                    }
                }
                else
                {
                    system("cls");//очистка консоли
                    std::string const authorizationError{ "Не верный логин или пароль." };
                    std::cout << authorizationError << std::endl;
                }
                break;
            }
            case 2:
            {
                addUsersBySimpleUser(users);//добавления пользователя самостоятельно
                break;
            }
            case 0:
            {
                return;// выход из функции, завершение программы
                break;
            }
            }
        }
        else
        {
            system("cls");//очистка консоли
            std::string const errorInput{ "Некорректный ввод. Попробуйте ещё раз." };
            std::cout << errorInput << std::endl;
        }
    }
}

void simpleUserMenu(std::vector<Book>& booksInLibrary, User const activUser)
{
    if (isActivatedUser(activUser))//если пользователь активирован
    {
        menuProcessingLibrary(booksInLibrary);//меню обработки данных библиотеки
    }
    else
    {
        std::string userNotActivatedMessage{ "Пользователь " + activUser.login + " ещй не активирован. Ожидайте подтвержение записи администратором." };
        std::cout << userNotActivatedMessage << std::endl;
    }
}

void administratorMenu(std::vector<User>& users, std::vector<Book>& booksInLibrary, User const activUser)
{
    if (isActivatedUser(activUser))//если пользователь активен
    {
        for (; ; )
        {
            std::string const welcomeMessage{ "Выберите режим работы:\n1.Управление данными пользователей\n2.Управление данными библиотеки\n3.Обработка данных библиотеки\n0.Назад" };
            std::cout << welcomeMessage << std::endl;
            std::string answer{};

            _flushall();//очистке всех входных буферов
            std::getline(std::cin, answer);//чтение строки с наличием " "

            int const maxAnswer{ 3 };//возможные пункты 0,1,2,3
            if (checkingCorrectnessInputForSequences(answer, maxAnswer))//проверка корректности ввода
            {
                system("cls");//очистка консоли
                switch (std::atoi(answer.c_str())) //конвертация string из в int
                {
                case 1: {
                    menuEditingUsers(users, activUser);//меню работы с пользователями
                    break;
                }
                case 2: {
                    menuEditingLibrary(booksInLibrary);//меню работы книгами
                    break;
                }
                case 3: {
                    menuProcessingLibrary(booksInLibrary);//меню обработки книг
                    break;
                }
                case 0: {
                    return;// выход из функции, возвращение в предыдушие меню
                }
                }
            }
            else
            {
                system("cls");//очистка консоли
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

void menuEditingUsers(std::vector<User>& users, User const activUser)
{
    for (; ; )
    {
        std::string const welcomeMessage{ "1.Просмотр всех данных пользователей\n2.Добавление нового пользователя\n"
                                          "3.Редактирование пользователя\n4.Активатия пользователя\n5.Блокировка пользователя\n"
                                          "6.Удаление пользователя\n0.Назад" };
        std::cout << welcomeMessage << std::endl;
        std::string answer{};

        _flushall();//очистке всех входных буферов
        std::getline(std::cin, answer);//чтение строки с наличием " "

        int const maxAnswer{ 6 };//возможные пункты 0,1,2,3,4,5,6
        if (checkingCorrectnessInputForSequences(answer, maxAnswer))//проверка корректности ввода
        {
            system("cls");//очистка консоли
            switch (std::atoi(answer.c_str()))//конвертация string из в int
            {
            case 1: {
                printUsers(users);//вывести пользователей
                break;
            }
            case 2: {
                addUsersByAdministrator(users);//добавить пользователя
                break;
            }
            case 3: {
                updateUserDataByAdministrator(users, activUser.login); //редактировать пользователя
                break;
            }
            case 4: {
                activationUserByAdministrator(users);//активировать пользователя
                break;
            }
            case 5: {
                blockUserByAdministrator(users, activUser.login);//блокировать пользователя
                break;
            }
            case 6: {
                deleteUserDataByAdministrator(users, activUser.login);//удалить пользователя
                break;
            }
            case 0: {
                return;// выход из функции, возвращение в предыдушие меню
            }
            }
        }
        else
        {
            system("cls");//очистка консоли
            std::string const errorInput{ "Некорректный ввод. Попробуйте ещё раз." };
            std::cout << errorInput << std::endl;
        }
    }
}

void menuEditingLibrary(std::vector<Book>& booksInLibrary)
{
    for (; ; )
    {
        std::string const welcomeMessage{ "1.Просмотр всех книг в библиотеки\n2.Добавление новой книги\n"
                                          "3.Редактирование книги\n4.Удаление книги\n0.Назад" };
        std::cout << welcomeMessage << std::endl;
        std::string answer{};
        _flushall();//очистке всех входных буферов
        std::getline(std::cin, answer);//чтение строки с наличием " "
        int const maxAnswer{ 4 };//возможные пункты 0,1,2,3,4
        if (checkingCorrectnessInputForSequences(answer, maxAnswer))//проверка корректности ввода
        {
            system("cls");//очистка консоли
            switch (std::atoi(answer.c_str()))//конвертация string из в int
            {
            case 1: {
                printBooks(booksInLibrary);//вывести книги
                break;
            }
            case 2: {
                addNewBookByAdministrator(booksInLibrary);//добаввить книгу
                break;
            }
            case 3: {
                updateBookByAdministrator(booksInLibrary);//редактировать книгу
                break;
            }
            case 4: {
                deleteBookByAdministrator(booksInLibrary);//удалить книгу
                break;
            }
            case 0: {
                return;// выход из функции, возвращение в предыдушие меню
            }
            }
        }
        else
        {
            system("cls");//очистка консоли
            std::string const errorInput{ "Некорректный ввод. Попробуйте ещё раз." };
            std::cout << errorInput << std::endl;
        }
    }
}

void menuProcessingLibrary(std::vector<Book>& booksInLibrary)
{
    for (; ; )
    {
        std::string const welcomeMessage{ "1.Просмотр всех книг в библиотеки\n2.Сортировка книг\n"
                                          "3.Поиск книги\n4.Сортировка по автору и поиск по году\n5.Просмотр книг находящихся на выдачи\n0.Назад" };
        std::cout << welcomeMessage << std::endl;
        std::string answer{};
        _flushall();//очистке всех входных буферов
        std::getline(std::cin, answer);//чтение строки с наличием " "

        int const maxAnswer{ 5 };//возможные пункты 0,1,2,3,4,5
        if (checkingCorrectnessInputForSequences(answer, maxAnswer))//проверка корректности ввода
        {
            system("cls");//очистка консоли
            switch (std::atoi(answer.c_str()))//конвертация string из в int
            {
            case 1: {
                printBooks(booksInLibrary);//вывести книги
                break;
            }
            case 2: {
                menuSortedBooks(booksInLibrary);//меню сортировки
                break;
            }
            case 3: {
                menuSearcBooks(booksInLibrary);//меню поиска
                break;
            }
            case 4: {//сортировка по фамилии автора и вывод книг изданных после заданного года
                sortBooksByAuthor(booksInLibrary);//сортировка по автору
                searchQueryByYearPuolicationMoreThen(booksInLibrary);//поиск книг изданных после .. года
                break;
            }
            case 5: {
                searchQueryBooksOnIssue(booksInLibrary);//вывод книг на выдаче
                break;
            }
            case 0: {
                return;// выход из функции, возвращение в предыдушие меню
            }
            }
        }
        else
        {
            system("cls");//очистка консоли
            std::string const errorInput{ "Некорректный ввод. Попробуйте ещё раз." };
            std::cout << errorInput << std::endl;
        }
    }
}

void menuSortedBooks(std::vector<Book>& booksInLibrary)
{
    for (; ; )
    {
        std::string const welcomeMessage{ "1.Сортировка по году издания\n2.Сортировка по фамилии автора\n"
                                          "3.Сортировка по числу страниц\n0.Назад" };
        std::cout << welcomeMessage << std::endl;
        std::string answer{};
        _flushall();//очистке всех входных буферов
        std::getline(std::cin, answer);//чтение строки с наличием " "

        int const maxAnswer{ 3 };//возможные пункты 0,1,2,3
        if (checkingCorrectnessInputForSequences(answer, maxAnswer))//проверка корректности ввода
        {
            system("cls");//очистка консоли
            switch (std::atoi(answer.c_str()))//конвертация string из в int
            {
            case 1: {
                sortBooksByYearPublication(booksInLibrary);//сортировка по году публикации
                break;
            }
            case 2: {
                sortBooksByAuthor(booksInLibrary);//сортировка по автору
                break;
            }
            case 3: {
                sortBooksByQuantityPage(booksInLibrary); //сортирова по числу страниц
                break;
            }
            case 0: {
                return;// выход из функции, возвращение в предыдушие меню
            }
            }
        }
        else
        {
            system("cls");//очистка консоли
            std::string const errorInput{ "Некорректный ввод. Попробуйте ещё раз." };
            std::cout << errorInput << std::endl;
        }
    }
}

void menuSearcBooks(const std::vector<Book>& booksInLibrary)
{
    for (; ; )
    {
        std::string const welcomeMessage{ "1.Поиск книги по автору\n2.Поиск книги по году издания\n"
                                          "3.Поиск книги по издательству\n4.Поиск книги после ... года издания\n0.Назад" };
        std::cout << welcomeMessage << std::endl;
        std::string answer{};
        _flushall();//очистке всех входных буферов
        std::getline(std::cin, answer);//чтение строки с наличием " "

        int const maxAnswer{ 4 };//возможные пункты 0,1,2,3,4
        if (checkingCorrectnessInputForSequences(answer, maxAnswer))//проверка корректности ввода
        {
            system("cls");//очистка консоли
            switch (std::atoi(answer.c_str()))//конвертация string из в int
            {
            case 1: {
                searchQueryByAuthor(booksInLibrary);//поиск книг по автору
                break;
            }
            case 2: {
                searchQueryByYearPuolication(booksInLibrary); //поиск книг по году издания
                break;
            }
            case 3: {
                searchQueryByPublishingHouse(booksInLibrary);//поиск книг по издательству
                break;
            }
            case 4: {
                searchQueryByYearPuolicationMoreThen(booksInLibrary);//поиск книг изданных после ... года
                break;
            }
            case 0: {
                return;// выход из функции, возвращение в предыдушие меню
            }
            }
        }
        else
        {
            system("cls");//очистка консоли
            std::string const errorInput{ "Некорректный ввод. Попробуйте ещё раз." };
            std::cout << errorInput << std::endl;
        }
    }
}

bool isActivatedUser(User const user)
{
    return user.access;
}
