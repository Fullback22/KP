#include "editingLibrary.h"

int findBookIndex(const std::vector<Book>& books, unsigned int const registrationNumber)
{
	for (size_t i{ 0 }; i < books.size(); ++i)
	{
		if (books[i].registrationNumber == registrationNumber)
			return i;
	}
	return -1;
}

int unsigned enteryNewBookRegistrationNumber(std::string const welcomeMessage)
{
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationEnterBookName{ "������� ��������������� ����� �����:" };
    std::cout << messageInvitationEnterBookName << std::endl;

    unsigned int newRegistrationNumber{ enteryUnsignetIntMeaning(welcomeMessage + "\n" + messageInvitationEnterBookName) };
    return  newRegistrationNumber;
}

std::string enteryNewBookAuthor(std::string const welcomeMessage)
{
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationEnterBookAthor{ "������� ������ �����:" };
    std::cout << messageInvitationEnterBookAthor << std::endl;
    size_t minLen{ 0 };
    for (; ; )
    {
        std::string newBookAthor{ enteryStringMeaning(welcomeMessage + "\n" + messageInvitationEnterBookAthor) };
        
        if (newBookAthor.size() < minLen)
        {
            system("cls");
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
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationEnterBookName{ "������� �������� �����:" };
    std::cout << messageInvitationEnterBookName << std::endl;
    size_t minNameLen{ 0 };
    for (; ; )
    {
        std::string newBookName{ enteryStringMeaning(welcomeMessage + "\n" + messageInvitationEnterBookName) };
        if (newBookName.size() < minNameLen)
        {
            system("cls");
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
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationEnterBookYearPuplication{ "������� ��� ������� �����:" };
    std::cout << messageInvitationEnterBookYearPuplication << std::endl;
    size_t maxYear{ 2050 };
    for (; ; )
    {
        unsigned int newYearPuplication{ enteryUnsignetIntMeaning(welcomeMessage + "\n" + messageInvitationEnterBookYearPuplication) };
        if (newYearPuplication > maxYear)
        {
            system("cls");
            std::cout << welcomeMessage << std::endl;
            std::string const messageError{ "�� ���������� ��� ����������" };
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
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationEnterBookPublishingHouse{ "������� ������������ �����:" };
    std::cout << messageInvitationEnterBookPublishingHouse << std::endl;

    std::string newPublishingHouse{ enteryStringMeaning(welcomeMessage + "\n" + messageInvitationEnterBookPublishingHouse) };
    return  newPublishingHouse;
}

int unsigned enteryNewBookQuantityPage(std::string const welcomeMessage)
{
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationEnterBookQuantityPage{ "������� ����� ������� �����:" };
    std::cout << messageInvitationEnterBookQuantityPage << std::endl;
    size_t minPage{ 0 };
    for (; ; )
    {
        unsigned int newPublishingHouse{ enteryUnsignetIntMeaning(welcomeMessage + "\n" + messageInvitationEnterBookQuantityPage) };
        if (newPublishingHouse <= minPage)
        {
            system("cls");
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


unsigned int enteryUnsignetIntMeaning(std::string const welcomeMessage)
{
    std::cout << welcomeMessage << std::endl;
    for (; ; )
    {
        std::string newInt{};
        std::cin >> newInt;
        if (checkingCorrectnessInputUnsignetInt(newInt))
        {
            return std::atoi(newInt.c_str());
        }
        else
        {
            system("cls");
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
        std::cin >> newString;
        if (checkingCorrectnessInputString(newString))
        {
            return newString;
        }
        else
        {
            system("cls");
            std::cout << welcomeMessage << std::endl;
            std::string const messageError{ "�� ���������� ����. ���������� ��� ���" };
            std::cout << messageError << std::endl;
        }
    }
}
