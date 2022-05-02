#include "menu.h"

void inputMenu(std::vector<User>& users, std::vector<Book>& booksInLibrary)
{
    for (; ; )
    { 
        std::string const message{ "1.�����\n2.�����������\n0.���������� ������" };
        std::cout << message << std::endl;
        std::string answer{};
        _flushall();//������� ���� ������� �������
        std::getline(std::cin, answer);//������ ������ � �������� " "
        int const maxAnswer{ 2 }; //��������� ������ 0,1,2
        if (checkingCorrectnessInputForSequences(answer, maxAnswer))//�������� ������������ �����
        {
            switch (std::atoi(answer.c_str())) //����������� string �� � int
            {
            case 1:
            {
                User activUser{}; // ���������������� ������������
                if (authorization(users, activUser))
                {
                    system("cls");//������� �������
                    std::string const welcomeMessage{ "������������ " + activUser.login + "!"};
                    std::cout << welcomeMessage << std::endl;
                    if (activUser.role == userRole::SIMPLE_USER)
                    {
                        simpleUserMenu(booksInLibrary, activUser);//���� ������������
                    }
                    else
                    {
                        administratorMenu(users, booksInLibrary, activUser);//���� ��������������
                    }
                }
                else
                {
                    system("cls");//������� �������
                    std::string const authorizationError{ "�� ������ ����� ��� ������." };
                    std::cout << authorizationError << std::endl;
                }
                break;
            }
            case 2:
            {
                addUsersBySimpleUser(users);//���������� ������������ ��������������
                break;
            }
            case 0:
            {
                return;// ����� �� �������, ���������� ���������
                break;
            }
            }
        }
        else
        {
            system("cls");//������� �������
            std::string const errorInput{ "������������ ����. ���������� ��� ���." };
            std::cout << errorInput << std::endl;
        }
    }
}

void simpleUserMenu(std::vector<Book>& booksInLibrary, User const activUser)
{
    if (isActivatedUser(activUser))//���� ������������ �����������
    {
        menuProcessingLibrary(booksInLibrary);//���� ��������� ������ ����������
    }
    else
    {
        std::string userNotActivatedMessage{ "������������ " + activUser.login + " ��� �� �����������. �������� ������������ ������ ���������������." };
        std::cout << userNotActivatedMessage << std::endl;
    }
}

void administratorMenu(std::vector<User>& users, std::vector<Book>& booksInLibrary, User const activUser)
{
    if (isActivatedUser(activUser))//���� ������������ �������
    {
        for (; ; )
        {
            std::string const welcomeMessage{ "�������� ����� ������:\n1.���������� ������� �������������\n2.���������� ������� ����������\n3.��������� ������ ����������\n0.�����" };
            std::cout << welcomeMessage << std::endl;
            std::string answer{};

            _flushall();//������� ���� ������� �������
            std::getline(std::cin, answer);//������ ������ � �������� " "

            int const maxAnswer{ 3 };//��������� ������ 0,1,2,3
            if (checkingCorrectnessInputForSequences(answer, maxAnswer))//�������� ������������ �����
            {
                system("cls");//������� �������
                switch (std::atoi(answer.c_str())) //����������� string �� � int
                {
                case 1: {
                    menuEditingUsers(users, activUser);//���� ������ � ��������������
                    break;
                }
                case 2: {
                    menuEditingLibrary(booksInLibrary);//���� ������ �������
                    break;
                }
                case 3: {
                    menuProcessingLibrary(booksInLibrary);//���� ��������� ����
                    break;
                }
                case 0: {
                    return;// ����� �� �������, ����������� � ���������� ����
                }
                }
            }
            else
            {
                system("cls");//������� �������
                std::string const errorInput{ "������������ ����. ���������� ��� ���." };
                std::cout << errorInput << std::endl;
            }
        }
    }
    else
    {
        std::string userNotActivatedMessage{ "������������ " + activUser.login + " ��� �� �����������. �������� ������������ ������ ���������������." };
        std::cout << userNotActivatedMessage << std::endl;
    }
}

void menuEditingUsers(std::vector<User>& users, User const activUser)
{
    for (; ; )
    {
        std::string const welcomeMessage{ "1.�������� ���� ������ �������������\n2.���������� ������ ������������\n"
                                          "3.�������������� ������������\n4.��������� ������������\n5.���������� ������������\n"
                                          "6.�������� ������������\n0.�����" };
        std::cout << welcomeMessage << std::endl;
        std::string answer{};

        _flushall();//������� ���� ������� �������
        std::getline(std::cin, answer);//������ ������ � �������� " "

        int const maxAnswer{ 6 };//��������� ������ 0,1,2,3,4,5,6
        if (checkingCorrectnessInputForSequences(answer, maxAnswer))//�������� ������������ �����
        {
            system("cls");//������� �������
            switch (std::atoi(answer.c_str()))//����������� string �� � int
            {
            case 1: {
                printUsers(users);//������� �������������
                break;
            }
            case 2: {
                addUsersByAdministrator(users);//�������� ������������
                break;
            }
            case 3: {
                updateUserDataByAdministrator(users, activUser.login); //������������� ������������
                break;
            }
            case 4: {
                activationUserByAdministrator(users);//������������ ������������
                break;
            }
            case 5: {
                blockUserByAdministrator(users, activUser.login);//����������� ������������
                break;
            }
            case 6: {
                deleteUserDataByAdministrator(users, activUser.login);//������� ������������
                break;
            }
            case 0: {
                return;// ����� �� �������, ����������� � ���������� ����
            }
            }
        }
        else
        {
            system("cls");//������� �������
            std::string const errorInput{ "������������ ����. ���������� ��� ���." };
            std::cout << errorInput << std::endl;
        }
    }
}

void menuEditingLibrary(std::vector<Book>& booksInLibrary)
{
    for (; ; )
    {
        std::string const welcomeMessage{ "1.�������� ���� ���� � ����������\n2.���������� ����� �����\n"
                                          "3.�������������� �����\n4.�������� �����\n0.�����" };
        std::cout << welcomeMessage << std::endl;
        std::string answer{};
        _flushall();//������� ���� ������� �������
        std::getline(std::cin, answer);//������ ������ � �������� " "
        int const maxAnswer{ 4 };//��������� ������ 0,1,2,3,4
        if (checkingCorrectnessInputForSequences(answer, maxAnswer))//�������� ������������ �����
        {
            system("cls");//������� �������
            switch (std::atoi(answer.c_str()))//����������� string �� � int
            {
            case 1: {
                printBooks(booksInLibrary);//������� �����
                break;
            }
            case 2: {
                addNewBookByAdministrator(booksInLibrary);//��������� �����
                break;
            }
            case 3: {
                updateBookByAdministrator(booksInLibrary);//������������� �����
                break;
            }
            case 4: {
                deleteBookByAdministrator(booksInLibrary);//������� �����
                break;
            }
            case 0: {
                return;// ����� �� �������, ����������� � ���������� ����
            }
            }
        }
        else
        {
            system("cls");//������� �������
            std::string const errorInput{ "������������ ����. ���������� ��� ���." };
            std::cout << errorInput << std::endl;
        }
    }
}

void menuProcessingLibrary(std::vector<Book>& booksInLibrary)
{
    for (; ; )
    {
        std::string const welcomeMessage{ "1.�������� ���� ���� � ����������\n2.���������� ����\n"
                                          "3.����� �����\n4.���������� �� ������ � ����� �� ����\n5.�������� ���� ����������� �� ������\n0.�����" };
        std::cout << welcomeMessage << std::endl;
        std::string answer{};
        _flushall();//������� ���� ������� �������
        std::getline(std::cin, answer);//������ ������ � �������� " "

        int const maxAnswer{ 5 };//��������� ������ 0,1,2,3,4,5
        if (checkingCorrectnessInputForSequences(answer, maxAnswer))//�������� ������������ �����
        {
            system("cls");//������� �������
            switch (std::atoi(answer.c_str()))//����������� string �� � int
            {
            case 1: {
                printBooks(booksInLibrary);//������� �����
                break;
            }
            case 2: {
                menuSortedBooks(booksInLibrary);//���� ����������
                break;
            }
            case 3: {
                menuSearcBooks(booksInLibrary);//���� ������
                break;
            }
            case 4: {//���������� �� ������� ������ � ����� ���� �������� ����� ��������� ����
                sortBooksByAuthor(booksInLibrary);//���������� �� ������
                searchQueryByYearPuolicationMoreThen(booksInLibrary);//����� ���� �������� ����� .. ����
                break;
            }
            case 5: {
                searchQueryBooksOnIssue(booksInLibrary);//����� ���� �� ������
                break;
            }
            case 0: {
                return;// ����� �� �������, ����������� � ���������� ����
            }
            }
        }
        else
        {
            system("cls");//������� �������
            std::string const errorInput{ "������������ ����. ���������� ��� ���." };
            std::cout << errorInput << std::endl;
        }
    }
}

void menuSortedBooks(std::vector<Book>& booksInLibrary)
{
    for (; ; )
    {
        std::string const welcomeMessage{ "1.���������� �� ���� �������\n2.���������� �� ������� ������\n"
                                          "3.���������� �� ����� �������\n0.�����" };
        std::cout << welcomeMessage << std::endl;
        std::string answer{};
        _flushall();//������� ���� ������� �������
        std::getline(std::cin, answer);//������ ������ � �������� " "

        int const maxAnswer{ 3 };//��������� ������ 0,1,2,3
        if (checkingCorrectnessInputForSequences(answer, maxAnswer))//�������� ������������ �����
        {
            system("cls");//������� �������
            switch (std::atoi(answer.c_str()))//����������� string �� � int
            {
            case 1: {
                sortBooksByYearPublication(booksInLibrary);//���������� �� ���� ����������
                break;
            }
            case 2: {
                sortBooksByAuthor(booksInLibrary);//���������� �� ������
                break;
            }
            case 3: {
                sortBooksByQuantityPage(booksInLibrary); //��������� �� ����� �������
                break;
            }
            case 0: {
                return;// ����� �� �������, ����������� � ���������� ����
            }
            }
        }
        else
        {
            system("cls");//������� �������
            std::string const errorInput{ "������������ ����. ���������� ��� ���." };
            std::cout << errorInput << std::endl;
        }
    }
}

void menuSearcBooks(const std::vector<Book>& booksInLibrary)
{
    for (; ; )
    {
        std::string const welcomeMessage{ "1.����� ����� �� ������\n2.����� ����� �� ���� �������\n"
                                          "3.����� ����� �� ������������\n4.����� ����� ����� ... ���� �������\n0.�����" };
        std::cout << welcomeMessage << std::endl;
        std::string answer{};
        _flushall();//������� ���� ������� �������
        std::getline(std::cin, answer);//������ ������ � �������� " "

        int const maxAnswer{ 4 };//��������� ������ 0,1,2,3,4
        if (checkingCorrectnessInputForSequences(answer, maxAnswer))//�������� ������������ �����
        {
            system("cls");//������� �������
            switch (std::atoi(answer.c_str()))//����������� string �� � int
            {
            case 1: {
                searchQueryByAuthor(booksInLibrary);//����� ���� �� ������
                break;
            }
            case 2: {
                searchQueryByYearPuolication(booksInLibrary); //����� ���� �� ���� �������
                break;
            }
            case 3: {
                searchQueryByPublishingHouse(booksInLibrary);//����� ���� �� ������������
                break;
            }
            case 4: {
                searchQueryByYearPuolicationMoreThen(booksInLibrary);//����� ���� �������� ����� ... ����
                break;
            }
            case 0: {
                return;// ����� �� �������, ����������� � ���������� ����
            }
            }
        }
        else
        {
            system("cls");//������� �������
            std::string const errorInput{ "������������ ����. ���������� ��� ���." };
            std::cout << errorInput << std::endl;
        }
    }
}

bool isActivatedUser(User const user)
{
    return user.access;
}
