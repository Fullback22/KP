#include "editingLibrary.h"

void addNewBookByAdministrator(std::vector<Book>& books)
{
    std::string const welcomeMessage{ "���������� ����� �����" };
    Book newBook{};
    if (setBookParameters(books, newBook, welcomeMessage)) //���� ������ ����� ���� ������� �������
    {
        std::string const question{ "�� ������������� ������ �������� ����� �����?" };
        if (confirmationAction(question)) //���� ����������� ���������� �����
        {
            books.push_back(newBook);
            std::string const bookAdded{ "����� ����� ������� ���������" };
            std::cout << bookAdded << std::endl;
        }
        else
        {
            std::string const bookAddedCanel{ "���������� ����� ��������" };
            std::cout << bookAddedCanel << std::endl;
        }
    }
    else
    {
        std::string const errorMessage{ "����� � ����� ��������������� ������� ��� �������." };
        std::cout << errorMessage << std::endl;
    }
}

void updateBookByAdministrator(std::vector<Book>& books)
{
    system("cls");//������� �������
    std::string const welcomeMessage{ "������� ��������������� ����� ����� ������� ������ �������������:" };
    std::cout << welcomeMessage << std::endl;
    std::string registrationNumberUpdatedBook{};
    _flushall();//������� ���� ������� �������
    std::getline(std::cin, registrationNumberUpdatedBook);//������ ������ � �������� " "

    int indexUpdatedBook{ findBookIndex(books, std::atoi(registrationNumberUpdatedBook.c_str())) }; //����� ������� ����� � ��������� ��������������� �������
    if (indexUpdatedBook < 0) //������ -1(����� �� �������)
    {
        std::string const registrationNumberError{ "������.����� � ����� ��������������� ������� �� ����������." };
        std::cout << registrationNumberError << std::endl;
    }
    else
    {
        std::string const updateBookMessage{ "�������������� �����" };
        Book updatedBookBufer{ books[indexUpdatedBook] };//��������� � ������ ����� ������� ����� ��������
        Book updatedBook{  };
        books.erase(books.begin() + indexUpdatedBook); //�������� ������� � �� ������ �������
        if (setBookParameters(books, updatedBook, updateBookMessage))//���� ������ ����� ������� �������
        {
            system("cls"); //������� �������
            std::string const question{ "�� ������������� ������ �������� ������ � ����� � ��������������� ������� " + registrationNumberUpdatedBook + "?" };
            if (confirmationAction(question)) // ������������� ��������� �����
            {
                books.emplace(books.begin() + indexUpdatedBook, updatedBook);// �� ����� �������� �������� ������ �������� �����
                system("cls");//������� �������
                std::string const updateSuccessful{ "������ ����� � ��������������� ������� " + registrationNumberUpdatedBook + " ������� ��������." };
                std::cout << updateSuccessful << std::endl; //��������� �� �������� ���������
            }
            else //���� ��������� ��������
            {
                books.emplace(books.begin() + indexUpdatedBook, updatedBookBufer); //�� ����� �������� �������� ������ �������� � ����� 
                system("cls");//������� �������
                std::string const updateCanel{ "��������� ��������." };
                std::cout << updateCanel << std::endl;
            }
        }
        else
        {
            books.emplace(books.begin() + indexUpdatedBook, updatedBookBufer);//�� ����� �������� �������� ������ �������� � ����� 
            system("cls");//������� �������
            std::string const updateError{ "������. ����� � ����� �������� ����������." };
            std::cout << updateError << std::endl;
        }
    }
}

void deleteBookByAdministrator(std::vector<Book>& books)
{
    system("cls");//������� �������
    std::string const welcomeMessage{ "������� ��������������� ����� ����� ������� ������ �������:" };
    std::cout << welcomeMessage << std::endl;
    std::string registrationNumberDeletedBook{};

    _flushall();//������� ���� ������� �������
    std::getline(std::cin, registrationNumberDeletedBook);//������ ������ � �������� " "
    int indexDeletedBook{ findBookIndex(books, std::atoi(registrationNumberDeletedBook.c_str())) }; // ����� ������� ����� � ��������� ��������������� �������
    if (indexDeletedBook < 0) //������ -1(����� �� �������)
    {
        std::string const registrationNumberError{ "������.����� � ����� ��������������� ������� �� ����������." };
        std::cout << registrationNumberError << std::endl;
    }
    else
    {
        system("cls");//������� �������
        std::string const question{ "�� ������������� ������ ������� ����� � ��������������� ������� " + registrationNumberDeletedBook + "?" };
        if (confirmationAction(question)) //������������ ��������
        {
            books.erase(books.begin() + indexDeletedBook); //�������� �����
            system("cls");//������� �������
            std::string const deletedSuccessful{ "����� � ��������������� ������� " + registrationNumberDeletedBook + " ������� �������." };
            std::cout << deletedSuccessful << std::endl;
        }
        else
        {
            system("cls");//������� �������
            std::string const deletedCanel{ "�������� ��������." };
            std::cout << deletedCanel << std::endl;
        }
    }
}

bool setBookParameters(const std::vector<Book>& books, Book &newBook, std::string const welcomeMessage)
{
    unsigned int registrationNumber{ enteryNewBookRegistrationNumber(welcomeMessage) }; //���� ���������������� ������
    if (bookExists(books, registrationNumber)) //���� ����� � ����� ������� ����
    {
        return false; //����������
    }
    else//����������� ����� ������
    {
        newBook.registrationNumber = registrationNumber;
        newBook.author = enteryNewBookAuthor(welcomeMessage);
        newBook.name = enteryNewBookName(welcomeMessage);
        newBook.yearPuplication = enteryNewBookYearPuplication(welcomeMessage);
        newBook.publishingHouse = enteryNewBookPublishingHouse(welcomeMessage);
        newBook.quantityPage = enteryNewBookQuantityPage(welcomeMessage);
        newBook.lastReaderTicketNumber = enteryNewBookLastReader(welcomeMessage);
        newBook.status = enteryNewBookStatus(welcomeMessage);
        return true;
    }
}

int unsigned enteryNewBookRegistrationNumber(std::string const welcomeMessage)
{
    system("cls");//������� �������
    std::string const messageInvitationEnterBookName{ "������� ��������������� ����� �����:" };   
    unsigned int newRegistrationNumber{ enteryUnsignetIntMeaning(welcomeMessage + "\n" + messageInvitationEnterBookName) }; //�������� ������������ �����
    return  newRegistrationNumber;
}

std::string enteryNewBookAuthor(std::string const welcomeMessage)
{
    system("cls");//������� �������
    std::string const messageInvitationEnterBookAthor{ "������� ������ �����:" };
    size_t minLen{ 0 };
    for (; ; )
    {
        std::string newBookAthor{ enteryStringMeaning(welcomeMessage + "\n" + messageInvitationEnterBookAthor) };//�������� ������������ �����
        
        if (newBookAthor.size() < minLen) //�������� �� ������� ������
        {
            system("cls");//������� �������
            std::cout << welcomeMessage << std::endl;
            std::string const messageError{ "� ����� ������ ���� �����" };
            std::cout << messageError << std::endl;
        }
        else
        {
            return newBookAthor;
        }
    }
}

std::string enteryNewBookName(std::string const welcomeMessage)
{
    //�������� ���������� ������� enteryNewBookAuthor
    system("cls");//������� �������
    std::string const messageInvitationEnterBookName{ "������� �������� �����:" };
    size_t minNameLen{ 0 };
    for (; ; )
    {
        std::string newBookName{ enteryStringMeaning(welcomeMessage + "\n" + messageInvitationEnterBookName) };
        if (newBookName.size() < minNameLen)
        {
            system("cls");//������� �������
            std::cout << welcomeMessage << std::endl;
            std::string const messageError{ "� ����� ������ ���� ��������" };
            std::cout << messageError << std::endl;
        }
        else
        {
            return newBookName;
        }
    }
}

int unsigned enteryNewBookYearPuplication(std::string const welcomeMessage)
{
    system("cls");//������� �������
    std::string const messageInvitationEnterBookYearPuplication{ "������� ��� ������� �����:" };

    int maxYear{ getYear() };//����������� �������� ����
    for (; ; )
    {
        unsigned int newYearPuplication{ enteryUnsignetIntMeaning(welcomeMessage + "\n" + messageInvitationEnterBookYearPuplication) }; //�������� ������������ �����
        if (newYearPuplication > maxYear) //��������, ��� ��� �� ��������� �������
        {
            system("cls");//������� �������
            std::cout << welcomeMessage << std::endl;
            std::string const messageError{ "�� ���������� ��� �������" };
            std::cout << messageError << std::endl;
        }
        else
        {
            return newYearPuplication;
        }
    }
}

std::string enteryNewBookPublishingHouse(std::string const welcomeMessage)
{
    system("cls");//������� �������
    std::string const messageInvitationEnterBookPublishingHouse{ "������� ������������ �����:" };
    std::string newPublishingHouse{ enteryStringMeaning(welcomeMessage + "\n" + messageInvitationEnterBookPublishingHouse) };
    return  newPublishingHouse;
}

int unsigned enteryNewBookQuantityPage(std::string const welcomeMessage)
{
    system("cls");//������� �������
    std::string const messageInvitationEnterBookQuantityPage{ "������� ����� ������� �����:" };
    size_t minPage{ 0 };
    for (; ; )
    {
        unsigned int newPublishingHouse{ enteryUnsignetIntMeaning(welcomeMessage + "\n" + messageInvitationEnterBookQuantityPage) };
        if (newPublishingHouse <= minPage) //�������� �� �� ������� ����� �������
        {
            system("cls");//������� �������
            std::cout << welcomeMessage << std::endl;
            std::string const messageError{ "����� �� ����� ���� ��� �������" };
            std::cout << messageError << std::endl;
        }
        else
        {
            return newPublishingHouse;
        }
    }
}

int unsigned enteryNewBookLastReader(std::string const welcomeMessage)
{
    system("cls");//������� �������
    std::string const messageInvitationEnterLastReader{ "������� ����� ������������� ������ ���������� �������� �����:" };

    unsigned int newLastReader{ enteryUnsignetIntMeaning(welcomeMessage + "\n" + messageInvitationEnterLastReader) };
    return  newLastReader;
}

bookStatus enteryNewBookStatus(std::string const welcomeMessage)
{
    system("cls");//������� �������
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationChooseStatus{ "�������� ������ �����(������ 0 ��� 1):\n0.����� � ����������\n1.����� �� ������" };
    std::cout << messageInvitationChooseStatus << std::endl;
    for (; ; )
    {
        std::string statusInput{};
        _flushall();//������� ���� ������� �������
        std::getline(std::cin, statusInput);//������ ������ � �������� " "

        int const maxValue{ 1 };
        if (checkingCorrectnessInputForSequences(statusInput, maxValue)) //�������� �� ������������ �����
        {
            return bookStatus(std::atoi(statusInput.c_str()));
        }
        else
        {
            system("cls");//������� �������
            std::cout << welcomeMessage << std::endl;
            std::string const messageIncorrectInput{ "�� ������ ����, ���������� ��� ���." };
            std::cout << messageIncorrectInput << std::endl;
            std::cout << messageInvitationChooseStatus << std::endl;
        }
    }
}


unsigned int enteryUnsignetIntMeaning(std::string const welcomeMessage)
{
    std::cout << welcomeMessage << std::endl;
    for (; ; )
    {
        std::string newInt{};
        _flushall();//������� ���� ������� �������
        std::getline(std::cin, newInt);//������ ������ � �������� " "
        
        if (checkingCorrectnessInputUnsignetInt(newInt) && newInt.size()>0)
        {
            return std::atoi(newInt.c_str());
        }
        else
        {
            system("cls");//������� �������
            std::cout << welcomeMessage << std::endl;
            std::string const messageError{ "�� ���������� ����. ���������� ��� ���" };
            std::cout << messageError << std::endl;
        }
    }
}

std::string enteryStringMeaning(std::string const welcomeMessage)
{
    std::cout << welcomeMessage << std::endl;
    for (; ; )
    {
        std::string newString{};
        _flushall();//������� ���� ������� �������
        std::getline(std::cin, newString);//������ ������ � �������� " "
        if (checkingCorrectnessInputString(newString))
        {
            return newString;
        }
        else
        {
            system("cls");//������� �������
            std::cout << welcomeMessage << std::endl;
            std::string const messageError{ "�� ���������� ����. ���������� ��� ���" };
            std::cout << messageError << std::endl;
        }
    }
}

bool bookExists(const std::vector<Book>& books, unsigned int const registrationNumber)
{
    if (findBookIndex(books, registrationNumber) >= 0)
        return true;
    else
        return false;
}

int findBookIndex(const std::vector<Book>& books, unsigned int const registrationNumber)
{
	for (size_t i{ 0 }; i < books.size(); ++i)
	{
		if (books[i].registrationNumber == registrationNumber)
			return i;
	}
	return -1;
}

int getYear()
{
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);//����������� �������� �������
    int startYear{ 1900 }; //������ �������������� � 1900, �.�. ��� ������������ ���������� �� �������� 0
    return  startYear + newtime.tm_year; // ���������� 1900 � �������� ����
}
