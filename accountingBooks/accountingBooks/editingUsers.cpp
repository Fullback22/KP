#include "editingUsers.h"

void creatFirstUser(std::vector<User>& users)
{
    users.push_back(User{});
    std::string const loginFirstUser{ "Admin" };
    users[0].login = loginFirstUser;
    std::string const saltFirstUser{ createSaltForUser(loginFirstUser) };
    users[0].salt = saltFirstUser;
    std::string const standartPassword{ "1111" };
    users[0].saltedHashPassword = convertUserPasswordToHash(standartPassword + saltFirstUser, loginFirstUser);
    users[0].role = userRole::ADMINISTRATOR;
    users[0].access = true;
}

void addUsersByAdministrator(std::vector<User>& users)
{
    std::string const messageNewUserRegistration{ "����������� ������ ������������" };
    User newUser{ setUserLoginAndPassword(&users, messageNewUserRegistration) };
    userRole newUserRole{ enteryNewUserRole(messageNewUserRegistration) };
    newUser.role = newUserRole;
    newUser.access = true;
    users.push_back(newUser);
    system("cls");
    std::string const messageNewUserCreate{ "����� ������������ " + newUser.login + " ������� ������." };
    std::cout << messageNewUserCreate << std::endl;
}

void addUsersBySimpleUser(std::vector<User>& users)
{
    std::string const messageNewUserRegistration{ "����������� ������ ������������" };
    User newUser{ setUserLoginAndPassword(&users, messageNewUserRegistration) };
    users.push_back(newUser);
    system("cls");
    std::string const messageNewUserCreate{ "����� ������������ " + newUser.login + " ������� ������. �������� ������������� ���������������." };
    std::cout << messageNewUserCreate << std::endl;
}

User setUserLoginAndPassword(std::vector<User>* const users, std::string const welcomeMessage)
{
    User outUser{};
    system("cls");
    std::string newUserLogin{ enteryNewUserLogin(users, welcomeMessage) };
    outUser.login = newUserLogin;
    system("cls");
    std::string originalPassword{ enteryNewUserPasswor(welcomeMessage) };
    std::string newUserSalt{ createSaltForUser(outUser.login) };
    outUser.salt = newUserSalt;
    outUser.saltedHashPassword = convertUserPasswordToHash(originalPassword + newUserSalt, newUserLogin);
    return outUser;
}

std::string enteryNewUserLogin(std::vector<User>* const users, std::string const welcomeMessage)
{
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationEnterLogin{ "������� �������� �����:" };
    std::cout << messageInvitationEnterLogin << std::endl;
    size_t minLoginLen{ 3 };
    for ( ; ; )
    {
        std::string newLogin{};
        std::cin >> newLogin;  
        if (loginExists(users, newLogin))
        {
            system("cls");
            std::cout << welcomeMessage << std::endl;
            std::string const messageLoginDusy{ "����� " + newLogin + " ��� �����." };
            std::cout << messageLoginDusy << std::endl;
            std::string const messageInvitationEnterOtherLogin{ "������� ������ �����:" };
            std::cout << messageInvitationEnterOtherLogin << std::endl;
        }
        else if (newLogin.size() < minLoginLen)
        {
            system("cls");
            std::cout << welcomeMessage << std::endl;
            std::string const messageLoginShort{ "����� " + newLogin + " ������� ��������. ����� ������ �������� �� ���� ��� �� " + std::to_string(minLoginLen) + " ��������." };
            std::cout << messageLoginShort << std::endl;
            std::string const messageInvitationEnterOtherLogin{ "������� ������ �����:" };
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
    std::string const messageInvitationEnterPassword{ "������� ������:" };
    std::cout << messageInvitationEnterPassword << std::endl;
    size_t minPasswordLen{ 3 };
    for ( ; ; )
    {
        std::string firstPasswordInput{ readPassword() };
        std::cout << std::endl;
        if (firstPasswordInput.size() < minPasswordLen)
        {
            system("cls");
            std::cout << welcomeMessage << std::endl;
            std::string const messageLoginShort{ "������ ������� ��������. ������ ������ �������� �� ���� ��� �� " + std::to_string(minPasswordLen) + " ��������." };
            std::cout << messageLoginShort << std::endl;
            std::string const messageInvitationEnterOtherLogin{ "������� ������ �����:" };
            std::cout << messageInvitationEnterOtherLogin << std::endl;
        }
        else
        {
            std::string const messageInvitationRepeatPassword{ "��������� ������:" };
            std::cout << messageInvitationRepeatPassword << std::endl;
            std::string secondPasswordInput{ readPassword() };
            std::cout << std::endl;
            if (firstPasswordInput == secondPasswordInput)
            {
                return firstPasswordInput;
            }
            else
            {
                system("cls");
                std::cout << welcomeMessage << std::endl;
                std::string const messageIncorrectPassword{ "�� ������ ������, ���������� ��� ���." };
                std::cout << messageIncorrectPassword << std::endl;
                std::cout << messageInvitationEnterPassword << std::endl;
            }
        }
    }
}

userRole enteryNewUserRole(std::string const welcomeMessage)
{
    system("cls");
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationChooseRole{ "�������� ����� ������������(������ 0 ��� 1):\n0.������� ������������\n1.�������������" };
    std::cout << messageInvitationChooseRole << std::endl;
    for (; ; )
    {
        std::string roleInput{};
        std::cin >> roleInput;
        std::string trueInput{ "01" };
        
        if (checkingCorrectnessInput(roleInput, trueInput))
        {
            return userRole(std::atoi(roleInput.c_str()));
        }
        else
        {
            system("cls");
            std::cout << welcomeMessage << std::endl;
            std::string const messageIncorrectInput{ "�� ������ ����, ���������� ��� ���." };
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
    system("cls");
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationChooseRole{ "������������ ��� ����������� ������������(������ 0 ��� 1):\n0.����������� ������������\n1.������������ ������������" };
    std::cout << messageInvitationChooseRole << std::endl;
    for (; ; )
    {
        std::string accessInput{};
        std::cin >> accessInput;
        std::string trueInput{ "01" };
        if (checkingCorrectnessInput(accessInput, trueInput))
        {
            return std::atoi(accessInput.c_str());
        }
        else
        {
            system("cls");
            std::cout << welcomeMessage << std::endl;
            std::string const messageIncorrectInput{ "�� ������ ����, ���������� ��� ���." };
            std::cout << messageIncorrectInput << std::endl;
            std::cout << messageInvitationChooseRole << std::endl;
        }
    }
}

User setAllUserData(std::vector<User>* const users, std::string const welcomeMessage)
{
    User newUser{ setUserLoginAndPassword(users, welcomeMessage) };
    userRole newUserRole{ enteryNewUserRole(welcomeMessage) };
    bool newUserAccess{ enteryNewUserAccess(welcomeMessage, newUserRole) };
    newUser.role = newUserRole;
    newUser.access = newUserAccess;
    return newUser;
}

bool updateUserData(std::vector<User>* const users, User & updatedUser, std::string const activUserLogin)
{
    std::string const informMassege{ "���������� ������ ������������ " + updatedUser.login };
    User newUser{ setAllUserData(users, informMassege) };
    if (updatedUser.login == activUserLogin)
    {
        if (updatedUser.access != newUser.access || updatedUser.role != newUser.role)
            return false;
    }
    updatedUser = newUser;
    return true;
}

void updateUserDataByAdministrator(std::vector<User>& users, std::string const activUserLogin)
{
    system("cls");
    std::string const welcomeMessage{ "������� ����� ������������ �������� ������ �������������:" };
    std::cout << welcomeMessage << std::endl;
    std::string loginUpdatedUser{};
    std::cin >> loginUpdatedUser;
    int indexUpdatedUser{ findUserIndex(&users, loginUpdatedUser) };
    if (indexUpdatedUser < 0)
    {
        std::string const loginError{ "������.������������ � ����� ������� �� ����������." };
        std::cout << loginError << std::endl;
    }
    else
    {
        User updatedUser{ users[indexUpdatedUser] };
        users.erase(users.begin() + indexUpdatedUser);
        if (updateUserData(&users, updatedUser, activUserLogin))
        {
            system("cls");
            std::string const question { "�� ������������� ������ �������� ������ ������������ " + loginUpdatedUser + "?"};
            if (confirmationAction(question))
            {
                users.emplace(users.begin() + indexUpdatedUser, updatedUser);
                system("cls");
                std::string const updateSuccessful{ "������ ������������ " + loginUpdatedUser + " ������� ��������." };
                std::cout << updateSuccessful << std::endl;
            }
            else
            {
                users.emplace(users.begin() + indexUpdatedUser, updatedUser);
                system("cls");
                std::string const updateCanel{ "��������� ��������." };
                std::cout << updateCanel << std::endl;
            }
        }
        else
        {
            users.emplace(users.begin() + indexUpdatedUser, updatedUser);
            system("cls");
            std::string const updateError{ "������. ���������� ������ ����������� ������� �������." };
            std::cout << updateError << std::endl;
        }
    }
}

void deleteUserDataByAdministrator(std::vector<User>& users, std::string const activUserLogin)
{
    system("cls");
    std::string const welcomeMessage{ "������� ����� ������������ �������� ������ �������:" };
    std::cout << welcomeMessage << std::endl;
    std::string loginDeletedUser{};
    std::cin >> loginDeletedUser;
    int indexDeletedUser{ findUserIndex(&users, loginDeletedUser) };
    if (indexDeletedUser < 0)
    {
        std::string const loginError{ "������.������������ � ����� ������� �� ����������." };
        std::cout << loginError << std::endl;
    }
    else
    {
        system("cls");
        std::string const question{ "�� ������������� ������ ������� ������������ " + loginDeletedUser + "?" };
        if (confirmationAction(question))
        {
            if (deleteUser(users, indexDeletedUser, activUserLogin))
            {
                system("cls");
                std::string const deleteSuccessful{ "������ ������������ " + loginDeletedUser + " ������� �������." };
                std::cout << deleteSuccessful << std::endl;
            }
            else
            {
                system("cls");
                std::string const deleteError{ "������. ���������� ������� ������������ ������������." };
                std::cout << deleteError << std::endl;
            }
        }
        else
        {
            system("cls");
            std::string const deleteCanel{ "�������� ��������." };
            std::cout << deleteCanel << std::endl;
        }
    }
}

bool deleteUser(std::vector<User>& const users, size_t const indexDeletedUser, std::string const activUserLogin)
{
    if(users[indexDeletedUser].login == activUserLogin)
        return false;
    else
    {
        users.erase(users.begin() + indexDeletedUser);
        return true;
    }
}

void activationUserByAdministrator(std::vector<User>& users)
{
    system("cls");
    std::string const welcomeMessage{ "������� ����� ������������ �������� ������ ������������:" };
    std::cout << welcomeMessage << std::endl;
    std::string loginActivatedUser{};
    std::cin >> loginActivatedUser;
    int indexActivatedUser{ findUserIndex(&users, loginActivatedUser) };
    if (indexActivatedUser < 0)
    {
        std::string const loginError{ "������.������������ � ����� ������� �� ����������." };
        std::cout << loginError << std::endl;
    }
    else
    {
        system("cls");
        std::string const question{ "�� ������������� ������ ������������ ������������ " + loginActivatedUser + "?" };
        if (confirmationAction(question))
        {
            users[indexActivatedUser].access = true;
            system("cls");
            std::string const activatedSuccessful{ "������������ " + loginActivatedUser + " ������� �����������." };
            std::cout << activatedSuccessful << std::endl;
        }
        else
        {
            system("cls");
            std::string const activatedCanel{ "��������� ��������." };
            std::cout << activatedCanel << std::endl;
        }
    }
}

void blockUserByAdministrator(std::vector<User>& users, std::string const activUserLogin)
{
    system("cls");
    std::string const welcomeMessage{ "������� ����� ������������ �������� ������ �������������:" };
    std::cout << welcomeMessage << std::endl;
    std::string loginBlockedUser{};
    std::cin >> loginBlockedUser;
    int indexBlockedUser{ findUserIndex(&users, loginBlockedUser) };
    if (indexBlockedUser < 0)
    {
        std::string const loginError{ "������.������������ � ����� ������� �� ����������." };
        std::cout << loginError << std::endl;
    }
    else
    {
        system("cls");
        if (loginBlockedUser == activUserLogin)
        {
            std::string const blockedError{ "������. ������������ �� ����� ������������� ����." };
            std::cout << blockedError << std::endl;
            return;
        }
        std::string const question{ "�� ������������� ������ ����������� ������������ " + loginBlockedUser + "?" };
        if (confirmationAction(question))
        {
            users[indexBlockedUser].access = false;
            system("cls");
            std::string const blockedSuccessful{ "������������ " + loginBlockedUser + " ������� ������������." };
            std::cout << blockedSuccessful << std::endl;
        }
        else
        {
            system("cls");
            std::string const blockedCanel{ "���������� ��������." };
            std::cout << blockedCanel << std::endl;
        }
    }
}

bool loginExists(std::vector<User>* const users, std::string const login)
{
    if (findUserIndex(users, login) >= 0)
        return true;
    return false;
}

int findUserIndex(std::vector<User>* const users, std::string const login)
{
    for (size_t i{}; i < users->size(); ++i)
    {
        if ((*users)[i].login == login)
            return i;
    }
    return -1;
}

bool confirmationAction(std::string const message)
{
    system("cls");
    for (; ; )
    {
        std::cout << message << std::endl;
        std::string answer{};
        std::cin >> answer;
        std::string trueInput{ "01" };
        if (checkingCorrectnessInput(answer, trueInput))
        {
            return std::atoi(answer.c_str());
        }
        else
        {
            system("cls");
            std::string const errorInput{ "������������ ����. ������� 0(������) ��� 1(��)" };
            std::cout << errorInput << std::endl;
        }
    }
}

void printUsers(const std::vector<User> & users)
{
    std::vector<size_t> columnSize{ 20,30,30,20,20 };
    std::vector<std::string> columnNames{ "�����","��� ������","���� ������","�����","������" };
    drawTableRaw(columnSize, columnNames, true);
    for (size_t i{ 0 }; i < users.size(); ++i)
    {
        std::vector<std::string> userData{};
        userData.push_back(users[i].login);
        userData.push_back(users[i].saltedHashPassword);
        userData.push_back(users[i].salt);
        userData.push_back(std::to_string(static_cast<int>(users[i].role)));
        userData.push_back(std::to_string(users[i].access));
        if(i < users.size() - 1)
            drawTableRaw(columnSize, userData);
        else
            drawTableRaw(columnSize, userData, true);
    }
}

