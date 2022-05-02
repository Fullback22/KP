#include "editingLibrary.h"

void addNewBookByAdministrator(std::vector<Book>& books)
{
    std::string const welcomeMessage{ "Добавление новой книги" };
    Book newBook{};
    if (setBookParameters(books, newBook, welcomeMessage)) //если данные книги были введены успешно
    {
        std::string const question{ "Вы действительно хотите добавить новую книгу?" };
        if (confirmationAction(question)) //если подтвердили добавление книги
        {
            books.push_back(newBook);
            std::string const bookAdded{ "Новая книга успешно добавлена" };
            std::cout << bookAdded << std::endl;
        }
        else
        {
            std::string const bookAddedCanel{ "Добавление книги отменено" };
            std::cout << bookAddedCanel << std::endl;
        }
    }
    else
    {
        std::string const errorMessage{ "Книга с таким регистрационным номером уже имеется." };
        std::cout << errorMessage << std::endl;
    }
}

void updateBookByAdministrator(std::vector<Book>& books)
{
    system("cls");//очистка консоли
    std::string const welcomeMessage{ "Введите регистрационный номер книги которую хотите редактировать:" };
    std::cout << welcomeMessage << std::endl;
    std::string registrationNumberUpdatedBook{};
    _flushall();//очистке всех входных буферов
    std::getline(std::cin, registrationNumberUpdatedBook);//чтение строки с наличием " "

    int indexUpdatedBook{ findBookIndex(books, std::atoi(registrationNumberUpdatedBook.c_str())) }; //поиск индекса книги с введенным регистрационным номером
    if (indexUpdatedBook < 0) //индекс -1(книга не найдена)
    {
        std::string const registrationNumberError{ "Ошибка.Книги с таким регистрационным номером не существует." };
        std::cout << registrationNumberError << std::endl;
    }
    else
    {
        std::string const updateBookMessage{ "Редактирование книги" };
        Book updatedBookBufer{ books[indexUpdatedBook] };//сохроняем в буфере книгу которую хотим изменить
        Book updatedBook{  };
        books.erase(books.begin() + indexUpdatedBook); //временно удаляем её из общего спитска
        if (setBookParameters(books, updatedBook, updateBookMessage))//если данные книги введены успешно
        {
            system("cls"); //очистка кансоли
            std::string const question{ "Вы действительно хотите изменить дынные в книги с регистрационным номером " + registrationNumberUpdatedBook + "?" };
            if (confirmationAction(question)) // подтверждение изменения книги
            {
                books.emplace(books.begin() + indexUpdatedBook, updatedBook);// на место временно удалённой записи помешаем новую
                system("cls");//очистка консоли
                std::string const updateSuccessful{ "Данные книги с регистрационным номером " + registrationNumberUpdatedBook + " успешно изменены." };
                std::cout << updateSuccessful << std::endl; //сообщение об успешном изменении
            }
            else //если изменения отменены
            {
                books.emplace(books.begin() + indexUpdatedBook, updatedBookBufer); //на место временно удалённой записи помещаем её буфер 
                system("cls");//очистка консоли
                std::string const updateCanel{ "Изменения отменены." };
                std::cout << updateCanel << std::endl;
            }
        }
        else
        {
            books.emplace(books.begin() + indexUpdatedBook, updatedBookBufer);//на место временно удалённой записи помещаем её буфер 
            system("cls");//очистка консоли
            std::string const updateError{ "Ошибка. Книга с таким индексом существует." };
            std::cout << updateError << std::endl;
        }
    }
}

void deleteBookByAdministrator(std::vector<Book>& books)
{
    system("cls");//очистка консоли
    std::string const welcomeMessage{ "Введите регистрационный номер книги которую хотите удалить:" };
    std::cout << welcomeMessage << std::endl;
    std::string registrationNumberDeletedBook{};

    _flushall();//очистке всех входных буферов
    std::getline(std::cin, registrationNumberDeletedBook);//чтение строки с наличием " "
    int indexDeletedBook{ findBookIndex(books, std::atoi(registrationNumberDeletedBook.c_str())) }; // поиск индекса книги с введенным регистрационным номером
    if (indexDeletedBook < 0) //индекс -1(книга не найдена)
    {
        std::string const registrationNumberError{ "Ошибка.Книги с таким регистрационным номером не существует." };
        std::cout << registrationNumberError << std::endl;
    }
    else
    {
        system("cls");//очистка консоли
        std::string const question{ "Вы действительно хотите удалить книгу с регистрационным номером " + registrationNumberDeletedBook + "?" };
        if (confirmationAction(question)) //подтвеждение удаления
        {
            books.erase(books.begin() + indexDeletedBook); //удаление книги
            system("cls");//очистка консоли
            std::string const deletedSuccessful{ "Книга с регистрационным номером " + registrationNumberDeletedBook + " успешно удалена." };
            std::cout << deletedSuccessful << std::endl;
        }
        else
        {
            system("cls");//очистка консоли
            std::string const deletedCanel{ "Удаление отменено." };
            std::cout << deletedCanel << std::endl;
        }
    }
}

bool setBookParameters(const std::vector<Book>& books, Book &newBook, std::string const welcomeMessage)
{
    unsigned int registrationNumber{ enteryNewBookRegistrationNumber(welcomeMessage) }; //ввод регистрационного номера
    if (bookExists(books, registrationNumber)) //если книга с таким номером есть
    {
        return false; //завершение
    }
    else//продолжение ввода данных
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
    system("cls");//очистка консоли
    std::string const messageInvitationEnterBookName{ "Введите регистрационный номер книги:" };   
    unsigned int newRegistrationNumber{ enteryUnsignetIntMeaning(welcomeMessage + "\n" + messageInvitationEnterBookName) }; //проверка корректности ввода
    return  newRegistrationNumber;
}

std::string enteryNewBookAuthor(std::string const welcomeMessage)
{
    system("cls");//очистка консоли
    std::string const messageInvitationEnterBookAthor{ "Введите автора книги:" };
    size_t minLen{ 0 };
    for (; ; )
    {
        std::string newBookAthor{ enteryStringMeaning(welcomeMessage + "\n" + messageInvitationEnterBookAthor) };//проверка корректности ввода
        
        if (newBookAthor.size() < minLen) //проверка на наличие автора
        {
            system("cls");//очистка консоли
            std::cout << welcomeMessage << std::endl;
            std::string const messageError{ "У книги должен быть автор" };
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
    //проверки аналогичны функции enteryNewBookAuthor
    system("cls");//очистка консоли
    std::string const messageInvitationEnterBookName{ "Введите название книги:" };
    size_t minNameLen{ 0 };
    for (; ; )
    {
        std::string newBookName{ enteryStringMeaning(welcomeMessage + "\n" + messageInvitationEnterBookName) };
        if (newBookName.size() < minNameLen)
        {
            system("cls");//очистка консоли
            std::cout << welcomeMessage << std::endl;
            std::string const messageError{ "У книги должно быть название" };
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
    system("cls");//очистка консоли
    std::string const messageInvitationEnterBookYearPuplication{ "Введите год издания книги:" };

    int maxYear{ getYear() };//определение текущего года
    for (; ; )
    {
        unsigned int newYearPuplication{ enteryUnsignetIntMeaning(welcomeMessage + "\n" + messageInvitationEnterBookYearPuplication) }; //проверка корректности ввода
        if (newYearPuplication > maxYear) //проверка, что год не привышает текущий
        {
            system("cls");//очистка консоли
            std::cout << welcomeMessage << std::endl;
            std::string const messageError{ "Не корректный год издания" };
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
    system("cls");//очистка консоли
    std::string const messageInvitationEnterBookPublishingHouse{ "Введите издательство книги:" };
    std::string newPublishingHouse{ enteryStringMeaning(welcomeMessage + "\n" + messageInvitationEnterBookPublishingHouse) };
    return  newPublishingHouse;
}

int unsigned enteryNewBookQuantityPage(std::string const welcomeMessage)
{
    system("cls");//очистка консоли
    std::string const messageInvitationEnterBookQuantityPage{ "Введите число страниц книги:" };
    size_t minPage{ 0 };
    for (; ; )
    {
        unsigned int newPublishingHouse{ enteryUnsignetIntMeaning(welcomeMessage + "\n" + messageInvitationEnterBookQuantityPage) };
        if (newPublishingHouse <= minPage) //проверка на не нулевое число страниц
        {
            system("cls");//очистка консоли
            std::cout << welcomeMessage << std::endl;
            std::string const messageError{ "Книга не может быть без страниц" };
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
    system("cls");//очистка консоли
    std::string const messageInvitationEnterLastReader{ "Введите номер читательского билета последнего читателя книги:" };

    unsigned int newLastReader{ enteryUnsignetIntMeaning(welcomeMessage + "\n" + messageInvitationEnterLastReader) };
    return  newLastReader;
}

bookStatus enteryNewBookStatus(std::string const welcomeMessage)
{
    system("cls");//очистка консоли
    std::cout << welcomeMessage << std::endl;
    std::string const messageInvitationChooseStatus{ "Выберите статус книги(ввести 0 или 1):\n0.Книга в библиотеки\n1.Книга на выдаче" };
    std::cout << messageInvitationChooseStatus << std::endl;
    for (; ; )
    {
        std::string statusInput{};
        _flushall();//очистке всех входных буферов
        std::getline(std::cin, statusInput);//чтение строки с наличием " "

        int const maxValue{ 1 };
        if (checkingCorrectnessInputForSequences(statusInput, maxValue)) //проверка на корректность ввода
        {
            return bookStatus(std::atoi(statusInput.c_str()));
        }
        else
        {
            system("cls");//очистка консоли
            std::cout << welcomeMessage << std::endl;
            std::string const messageIncorrectInput{ "Не верный ввод, попробуйте ещё раз." };
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
        _flushall();//очистке всех входных буферов
        std::getline(std::cin, newInt);//чтение строки с наличием " "
        
        if (checkingCorrectnessInputUnsignetInt(newInt) && newInt.size()>0)
        {
            return std::atoi(newInt.c_str());
        }
        else
        {
            system("cls");//очистка консоли
            std::cout << welcomeMessage << std::endl;
            std::string const messageError{ "Не корректный ввод. Попробуйте ещё раз" };
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
        _flushall();//очистке всех входных буферов
        std::getline(std::cin, newString);//чтение строки с наличием " "
        if (checkingCorrectnessInputString(newString))
        {
            return newString;
        }
        else
        {
            system("cls");//очистка консоли
            std::cout << welcomeMessage << std::endl;
            std::string const messageError{ "Не корректный ввод. Попробуйте ещё раз" };
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
    localtime_s(&newtime, &now);//определение текущего времени
    int startYear{ 1900 }; //отсчёт осуществляется с 1900, т.е. для используемой библиотеки он является 0
    return  startYear + newtime.tm_year; // прибавляем 1900 к текущему году
}
