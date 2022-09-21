#include <iostream>
#include <cstring>
#include "vector3f.h"

// Задание 1
namespace myspace {

void printNTimes(const char *str, int n = 10) {
  for (int i = 0; i < 10; ++i) {
    std::cout << str;
  }
}

}

// Задание 2
int cubeV(int num) {
  return num * num * num;
}

// Задание 3
void cubeR(int &num) {
  num = num * num * num;
}

// Задание 4
void countLetters(const char *str, int &numLetters, int &numDigits, int &numOther) {
  numLetters = numDigits = numOther = 0;
  for (int i = 0; i < std::strlen(str); ++i) {
    if (str[i] >= '0' && str[i] <= '9') {
      ++numDigits;
    } else if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
      ++numLetters;
    } else {
      ++numOther;
    }
  }
}

struct Book
{
  char title[100];
  int pages;
  float price;
};

// Задание 5
void addPrice(Book& book, float x) {
  book.price += x;
}

// Задание 6
bool isExpensive(const Book& book) {
  return book.price > 1000;
}




int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
