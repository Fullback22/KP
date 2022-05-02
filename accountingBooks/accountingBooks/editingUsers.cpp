#include "editingUsers.h"

void creatFirstUser(std::vector<User>& users)
{
    users.push_back(User{});//добавление в вектор
    std::string const loginFirstUser{ "Admin" };
    users[0].login = loginFirstUser;
    std::string const saltFirstUser{ createSaltForUser(loginFirstUser) }; //генерация "соли"
    users[0].salt = saltFirstUser;
    std::string const standartPassword{ "1111" };//стандартный пароль
    users[0].saltedHashPassword = convertUserPasswordToHash(standartPassword + saltFirstUser, loginFirstUser);//хэширование пароля
    users[0].role = userRole::ADMINISTRATOR;
    users[0].access = true;
}

void addUsersByAdministrator(std::vector<User>& users)
{
    std::string const messageNewUserRegistration{ "Регистрация нового пользователя" };
    User newUser{ setUserLoginAndPassword(users, messageNewUserRegistration) }; //установка пользователю логина и пароля
    userRole newUserRole{ enteryNewUserRole(messageNewUserRegistration) }; //установка прав доступа
    newUser.role = newUserRole; 
    newUser.access = true; //если пользователь создан администратором, он сразу является активным
    users.push_back(newUser);
    system("cls");//очистка кансоли
    std::string const messageNewUserCreate{ "Новый пользователь " + newUser.login + " успешно создан." }; 
    std::cout << messageNewUserCreate << std::endl;
}

void addUsersBySimpleUser(std::vector<User>& users)
{
    std::string const messageNewUserRegistration{ "Регистрация нового пользователя" };
    User newUser{ setUserLoginAndPassword(users, messageNewUserRegistration) }; //установка логина и пароля пользователю
    users.push_back(newUser); //добавление в вектор
    system("cls");//очистка кансоли
    std::string const messageNewUserCreate{ "Новый пользователь " + newUser.login + " успешно создан. Ожидайте подтверждения администратором." };
    std::cout << messageNewUserCreate << std::endl;
}

User setUserLoginAndPassword(const std::vector<User>& users, std::string const welcomeMessage)
{
    User outUser{};
    system("cls");//очистка кансоли
    std::string newUserLogin{ enteryNewUserLogin(users, welcomeMessage) };//ввод логина
    outUser.login = newUserLogin;
    system("cls");//очистка кансоли
    std::string originalPassword{ enteryNewUserPasswor(welcomeMessage) };//ввод пароля
    std::string newUserSalt{ createSaltForUser(outUser.login) }; //генерация соли
    outUser.salt = newUserSalt;
    outUser.saltedHashPassword = convertUserPasswordToHash(originalPassword + newUserSalt, newUserLogin);//хеширование пароля
    return outUser;
}

std::string enteryNewUserLogin(const std::vector<User>& users, std::string const welcomeMessage)
{
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationEnterLogin{ "Введите желаемый логин:" };
    std::cout << messageInvitationEnterLogin << std::endl;
    size_t minLoginLen{ 3 }; //установка минимальной длины логина
    for ( ; ; )
    {
        std::string newLogin{};
        _flushall();//очистке всех входных буферов
        std::getline(std::cin, newLogin);//чтение строки с наличием " "
        if (loginExists(users, newLogin)) //проверка на существование введённого логина
        {
            //логин уже занят
            system("cls");//очистка консоли
            std::cout << welcomeMessage << std::endl;
            std::string const messageLoginDusy{ "Логин " + newLogin + " уже занят." };
            std::cout << messageLoginDusy << std::endl;
            std::string const messageInvitationEnterOtherLogin{ "Введите другой логин:" };
            std::cout << messageInvitationEnterOtherLogin << std::endl;
        }
        else if (newLogin.size() < minLoginLen) //проверка соответствия минимальной длине
        {
            system("cls");//очистка кансоли
            std::cout << welcomeMessage << std::endl;
            std::string const messageLoginShort{ "Логин " + newLogin + " слишком короткий. Логин должен состоять не мене чем из " + std::to_string(minLoginLen) + " символов." };
            std::cout << messageLoginShort << std::endl;
            std::string const messageInvitationEnterOtherLogin{ "Введите другой логин:" };
            std::cout << messageInvitationEnterOtherLogin << std::endl;
        }
        else
        {
            return newLogin;
        }
    }
}

std::string enteryNewUserPasswor(std::string const welcomeMessage)
{
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationEnterPassword{ "Введите пароль:" };
    std::cout << messageInvitationEnterPassword << std::endl;
    size_t minPasswordLen{ 3 };//минимальная длина пароля
    for ( ; ; )
    {
        std::string firstPasswordInput{ readPassword() };//ввод пароля первый раз
        std::cout << std::endl;
        if (firstPasswordInput.size() < minPasswordLen)//проверка соответствия минимальной длине
        {
            system("cls");//очистка кансоли
            std::cout << welcomeMessage << std::endl;
            std::string const messageLoginShort{ "Пароль слишком короткий. Пароль должен состоять не мене чем из " + std::to_string(minPasswordLen) + " символов." };
            std::cout << messageLoginShort << std::endl;
            std::string const messageInvitationEnterOtherLogin{ "Введите другой логин:" };
            std::cout << messageInvitationEnterOtherLogin << std::endl;
        }
        else
        {
            std::string const messageInvitationRepeatPassword{ "Повторите пароль:" };
            std::cout << messageInvitationRepeatPassword << std::endl; 
            std::string secondPasswordInput{ readPassword() };//повторение пароля
            std::cout << std::endl;
            if (firstPasswordInput == secondPasswordInput) //пароли совпали
            {
                return firstPasswordInput;
            }
            else
            {
                system("cls");//очистка кансоли
                std::cout << welcomeMessage << std::endl;
                std::string const messageIncorrectPassword{ "Не верный пароль, попробуйте ещё раз." };
                std::cout << messageIncorrectPassword << std::endl;
                std::cout << messageInvitationEnterPassword << std::endl;
            }
        }
    }
}

userRole enteryNewUserRole(std::string const welcomeMessage)
{
    system("cls");//очистка кансоли
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationChooseRole{ "Выберите права пользователя(ввести 0 или 1):\n0.Простой пользователь\n1.Администратор" };
    std::cout << messageInvitationChooseRole << std::endl;
    for (; ; )
    {
        std::string roleInput{};
        _flushall();//очистке всех входных буферов
        std::getline(std::cin, roleInput);//чтение строки с наличием " "
        int const maxValue{ 1 };//можно ввести 0 и 1
        if (checkingCorrectnessInputForSequences(roleInput, maxValue)) //проверка кооректности ввода
        {
            return userRole(std::atoi(roleInput.c_str()));
        }
        else
        {
            system("cls");//очистка кансоли
            std::cout << welcomeMessage << std::endl;
            std::string const messageIncorrectInput{ "Не верный ввод, попробуйте ещё раз." };
            std::cout << messageIncorrectInput << std::endl;
            std::cout << messageInvitationChooseRole << std::endl;
        }
    }
}

bool enteryNewUserAccess(std::string const welcomeMessage, userRole const role)
{
    if (role == userRole::ADMINISTRATOR)
    {
        return 1;
    }
    system("cls");//очистка кансоли
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationChooseRole{ "Блокироватьь или активироват пользователя(ввести 0 или 1):\n0.Блокировать пользователь\n1.Активировать пользователь" };
    std::cout << messageInvitationChooseRole << std::endl;
    for (; ; )
    {
        std::string accessInput{};
        _flushall();
        std::getline(std::cin, accessInput);
        int const maxValue{ 1 }; //можно ввести 0 и 1
        if (checkingCorrectnessInputForSequences(accessInput, maxValue))//проверка корректности ввода
        {
            return std::atoi(accessInput.c_str()); //преобразование из string в int 
        }
        else
        {
            system("cls");//очистка кансоли
            std::cout << welcomeMessage << std::endl;
            std::string const messageIncorrectInput{ "Не верный ввод, попробуйте ещё раз." };
            std::cout << messageIncorrectInput << std::endl;
            std::cout << messageInvitationChooseRole << std::endl;
        }
    }
}

User setAllUserData(const std::vector<User>& users, std::string const welcomeMessage)
{
    User newUser{ setUserLoginAndPassword(users, welcomeMessage) };
    userRole newUserRole{ enteryNewUserRole(welcomeMessage) };
    bool newUserAccess{ enteryNewUserAccess(welcomeMessage, newUserRole) };
    newUser.role = newUserRole;
    newUser.access = newUserAccess;
    return newUser;
}

bool updateUserData(const std::vector<User>& users, User & updatedUser, std::string const activUserLogin)
{
    std::string const informMassege{ "Обновление данных пользователя " + updatedUser.login };
    User newUser{ setAllUserData(users, informMassege) };
    if (updatedUser.login == activUserLogin) // если пользователь пытается изменить свои данные
    {
        if (updatedUser.access != newUser.access || updatedUser.role != newUser.role) // и изменил уровень прав или заблокировал себя
            return false;//запретить изменения
    }
    updatedUser = newUser; //обновить данные пользователя
    return true;//разрешить изменения
}

void updateUserDataByAdministrator(std::vector<User>& users, std::string const activUserLogin)
{
    system("cls");//очистка кансоли
    std::string const welcomeMessage{ "Введите логин пользователя которого хотите редактировать:" };
    std::cout << welcomeMessage << std::endl;
    std::string loginUpdatedUser{};
    
    _flushall();//очистке всех входных буферов
    std::getline(std::cin, loginUpdatedUser);//чтение строки с наличием " "
    int indexUpdatedUser{ findUserIndex(users, loginUpdatedUser) }; //поиск индекса пользователя по логину
    if (indexUpdatedUser < 0)//индекс -1(пользователь не найден)
    {
        std::string const loginError{ "Ошибка.Пользователя с таким логином не существует." };
        std::cout << loginError << std::endl;
    }
    else
    {
        User updatedUserBufer{ users[indexUpdatedUser] };// буфер хранящий данные изменяемого пользователя
        User updatedUser{ };// место для хранения вновь введённых данных
        users.erase(users.begin() + indexUpdatedUser);//временное удаление пользователя из вектора
        if (updateUserData(users, updatedUser, activUserLogin)) //если данные были ведены успешно
        {
            system("cls");//очистка кансоли
            std::string const question { "Вы действительно хотите изменить дынные пользователя " + loginUpdatedUser + "?"};
            if (confirmationAction(question))//если подтвержденно изменения пользователя
            {
                users.emplace(users.begin() + indexUpdatedUser, updatedUser);//на место временно удаленного пользователя вернуть обнавлённые данные
                system("cls");//очистка кансоли
                std::string const updateSuccessful{ "Данные пользователя " + loginUpdatedUser + " успешно изменены." };
                std::cout << updateSuccessful << std::endl;
            }
            else
            {
                users.emplace(users.begin() + indexUpdatedUser, updatedUserBufer);//на место временно удаленного пользователя вернуть буферные данные
                system("cls");//очистка кансоли
                std::string const updateCanel{ "Изменения отменены." };
                std::cout << updateCanel << std::endl;
            }
        }
        else
        {
            users.emplace(users.begin() + indexUpdatedUser, updatedUserBufer);//на место временно удаленного пользователя вернуть буферные данные
            system("cls");//очистка кансоли
            std::string const updateError{ "Ошибка. Запрещенно менять собственный уровень доступа." };
            std::cout << updateError << std::endl;
        }
    }
}

void deleteUserDataByAdministrator(std::vector<User>& users, std::string const activUserLogin)
{
    system("cls");//очистка кансоли
    std::string const welcomeMessage{ "Введите логин пользователя которого хотите удалить:" };
    std::cout << welcomeMessage << std::endl;
    std::string loginDeletedUser{};

    _flushall();//очистке всех входных буферов
    std::getline(std::cin, loginDeletedUser);//чтение строки с наличием " "
    int indexDeletedUser{ findUserIndex(users, loginDeletedUser) }; //поиск индекса пользователя по логину
    if (indexDeletedUser < 0) //индекс -1 логин не найден
    {
        std::string const loginError{ "Ошибка.Пользователя с таким логином не существует." };
        std::cout << loginError << std::endl;
    }
    else
    {
        system("cls");//очистка кансоли
        std::string const question{ "Вы действительно хотите удалить пользователя " + loginDeletedUser + "?" };
        if (confirmationAction(question))//подтверждение удаления пользователя
        {
            if (deleteUser(users, indexDeletedUser, activUserLogin)) //пользователь был удалён
            {
                system("cls");//очистка кансоли
                std::string const deleteSuccessful{ "Данные пользователя " + loginDeletedUser + " успешно удалены." };
                std::cout << deleteSuccessful << std::endl;
            }
            else //пользователь не может быть удалён
            {
                system("cls");//очистка кансоли
                std::string const deleteError{ "Ошибка. Запрещенно удалять собственного пользователя." };
                std::cout << deleteError << std::endl;
            }
        }
        else//отмена удаления
        {
            system("cls");//очистка кансоли
            std::string const deleteCanel{ "Удаление отменены." };
            std::cout << deleteCanel << std::endl;
        }
    }
}

bool deleteUser(std::vector<User>& const users, size_t const indexDeletedUser, std::string const activUserLogin)
{
    if(users[indexDeletedUser].login == activUserLogin) // проверка на то, что бы пользователь не удалил сам себя
        return false;//удаление не завершено
    else
    {
        users.erase(users.begin() + indexDeletedUser); //удаления пользователя 
        return true; //успешно удален
    }
}

void activationUserByAdministrator(std::vector<User>& users)
{
    system("cls");//очистка кансоли
    std::string const welcomeMessage{ "Введите логин пользователя которого хотите активировать:" };
    std::cout << welcomeMessage << std::endl;
    std::string loginActivatedUser{};
    _flushall();//очистке всех входных буферов
    std::getline(std::cin, loginActivatedUser);//чтение строки с наличием " "
    int indexActivatedUser{ findUserIndex(users, loginActivatedUser) };//поиск индекса пользователя по логину
    if (indexActivatedUser < 0)//индекс -1, пользователь не найден
    {
        std::string const loginError{ "Ошибка.Пользователя с таким логином не существует." };
        std::cout << loginError << std::endl;
    }
    else
    {
        system("cls");//очистка кансоли
        std::string const question{ "Вы действительно хотите активировать пользователя " + loginActivatedUser + "?" };
        if (confirmationAction(question)) //подтверждение активации пользователя
        {
            users[indexActivatedUser].access = true;//актиация пользователя
            system("cls");//очистка кансоли
            std::string const activatedSuccessful{ "Пользователь " + loginActivatedUser + " успешно активирован." };
            std::cout << activatedSuccessful << std::endl;
        }
        else//отмена активации
        {
            system("cls");//очистка кансоли
            std::string const activatedCanel{ "Активация отменена." };
            std::cout << activatedCanel << std::endl;
        }
    }
}

void blockUserByAdministrator(std::vector<User>& users, std::string const activUserLogin)
{
    system("cls");//очистка кансоли
    std::string const welcomeMessage{ "Введите логин пользователя которого хотите заблокировать:" };
    std::cout << welcomeMessage << std::endl;
    std::string loginBlockedUser{};
    
    _flushall();//очистке всех входных буферов
    std::getline(std::cin, loginBlockedUser);//чтение строки с наличием " "
    int indexBlockedUser{ findUserIndex(users, loginBlockedUser) };//поиск индекса пользователя по логину
    if (indexBlockedUser < 0)//индекс -1, пользователь не найден
    {
        std::string const loginError{ "Ошибка.Пользователя с таким логином не существует." };
        std::cout << loginError << std::endl;
    }
    else
    {
        system("cls");//очистка кансоли
        if (loginBlockedUser == activUserLogin)//если пользователь пытается сам себя заблокировать
        {
            std::string const blockedError{ "Ошибка. Пользователь не может заблокировать себя." };
            std::cout << blockedError << std::endl;
            return; //прерывание функции 
        }
        std::string const question{ "Вы действительно хотите блокировать пользователя " + loginBlockedUser + "?" };
        if (confirmationAction(question)) //подверждение блокировки
        {
            users[indexBlockedUser].access = false; //блокировка пользователя
            system("cls");//очистка кансоли
            std::string const blockedSuccessful{ "Пользователь " + loginBlockedUser + " успешно заблокирован." };
            std::cout << blockedSuccessful << std::endl;
        }
        else //отмена блокировки
        {
            system("cls");//очистка кансоли
            std::string const blockedCanel{ "Блокировка отменена." };
            std::cout << blockedCanel << std::endl;
        }
    }
}

bool loginExists(const std::vector<User>& users, std::string const login)
{
    if (findUserIndex(users, login) >= 0)
        return true;
    return false;
}

int findUserIndex(const std::vector<User>& users, std::string const login)
{
    for (size_t i{}; i < users.size(); ++i)
    {
        if (users[i].login == login)
            return i;
    }
    return -1;
}

void printUsers(const std::vector<User> & users)
{
    std::vector<size_t> columnSize{ 20,30,30,20,20 };//размеры калонок
    std::vector<std::string> columnNames{ "Логин","Хэш пароля","Соль пароля","Права","Статус" };//заголовки калонок
    drawTableRaw(columnSize, columnNames, true);//рисование заголовка
    for (size_t i{ 0 }; i < users.size(); ++i)//рисование данных
    {
        std::vector<std::string> userData{};
        userData.push_back(users[i].login);
        userData.push_back(users[i].saltedHashPassword);
        userData.push_back(users[i].salt);
        userData.push_back(std::to_string(static_cast<int>(users[i].role))); //конвертация перечесления в int затем string
        userData.push_back(std::to_string(users[i].access)); //ковертаци bool в string
        if(i < users.size() - 1)
            drawTableRaw(columnSize, userData);
        else
            drawTableRaw(columnSize, userData, true);//рисование нижней границы для последней строки
    }
}

