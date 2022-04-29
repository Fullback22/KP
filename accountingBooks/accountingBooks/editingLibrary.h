#pragma once
#include <vector>

#include "Book.h"

#include "hashFunction.h"
void addNewBook(std::vector<Book>& books);

int unsigned enteryNewBookRegistrationNumber(std::string const welcomeMessage);
std::string enteryNewBookAuthor(std::string const welcomeMessage);
std::string enteryNewBookName(std::string const welcomeMessage);
int unsigned enteryNewBookYearPuplication(std::string const welcomeMessage);
std::string enteryNewBookPublishingHouse(std::string const welcomeMessage);
int unsigned enteryNewBookQuantityPage(std::string const welcomeMessage);

int unsigned enteryUnsignetIntMeaning(std::string const welcomeMessage);
std::string enteryStringMeaning(std::string const welcomeMessage);

int findBookIndex(const std::vector<Book>& books, unsigned int const registrationNumber);