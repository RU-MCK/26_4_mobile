#include <iostream>
#include <string>
#include <map>

int command(std::string &command) {
  if (command == "add") return 1;
  else if (command == "call") return 2;
  else if (command == "sms") return 3;
  else if (command == "exit") return 4;
  else if (command == "print") return 5;
  else return 0;
}

class Telephone {
 private:
  class PhoneBook {
   public:
    std::multimap<std::string, std::string> book;
  };
 public:
  PhoneBook phone_book;
  //------------------------------------------------------------------------
  void Add() {
    std::string number;
    std::string name;
    while (true) {
      std::cout << "Enter phone number +7 ";
      std::cin >> number;
      if (number.length() != 10) {
        std::cout << "Wrong number. Repeat please." << std::endl;
        continue;
      } else {
        std::cout << "Enter name:";
        std::cin >> name;
      }
      break;
    }
    phone_book.book.emplace(name, number);
  }
  //------------------------------------------------------------------------
  void Call() {
    std::string str;
    std::cout << "Enter name or number: +7 ";
    std::cin >> str;
    if (Find(str))
      std::cout << "--------------CALL----------------" << std::endl;
  }
  //------------------------------------------------------------------------
  void Sms() {
    std::string str;
    std::cout << "Enter name or number: +7 ";
    std::cin >> str;
    if (Find(str)) {
      std::cout << "Enter text: " << std::endl;
      std::cin >> str;
    }
  }
  //------------------------------------------------------------------------
  bool Find(std::string &str) {
    for (auto &it : phone_book.book) {
      if (it.first == str || it.second == str)
        return true;
    }
    std::cout << "Number or name not found." << std::endl;
    return false;
  }
  //------------------------------------------------------------------------
  void PrintBook() {
    for (auto &it : phone_book.book)
      std::cout << it.first << " " << it.second << std::endl;
  };
  //------------------------------------------------------------------------
};

int main() {
  Telephone telephone;
  std::string str;

  do {

    std::cout << "Enter command: "
              << "<add> <call> <sms> <print> or <exit> " << std::endl;
    std::cin >> str;

    switch (command(str)) {
      case 1://if add
        telephone.Add();
        break;
      case 2://if call
        telephone.Call();
        break;
      case 3://if sms
        telephone.Sms();
        break;
      case 4: //if exit
        std::cout << "Work finished." << std::endl;
        break;
      case 5://if print
        telephone.PrintBook();
        break;
      case 0:// if enter error
        std::cout << "Enter error command. Repeat please." << std::endl;
        break;
    }
  } while (str != "exit");
  return 0;
}
