#include "student.h"
#include <string>
#include <cstring>

// int countDigit(int number) {
//   if (number == 0) return 0; 
//   return 1 + countDigit(number / 10); //Edge Case: negative ID number. 
// }

// char* getChar(int number) {
//   int digits = countDigit(number); 
//   char* returnChar = new char[digits + 1];
//   for (int i = 0; i < digits; i++) {
//     returnChar[i] = number % 10 + '0';
//     number = number / 10; 
//   }

//   for (int i = 0; i < digits / 2; i++) {
//     char temp = returnChar[i]; 
//     returnChar[i] = returnChar[digits - i - 1]; 
//     returnChar[digits - i - 1] = temp;  
//   }

//   returnChar[digits] = '\0';

//   return returnChar; 
// }

Student::Student(const char * const name, int perm): name(nullptr) {
  this->setName(name);
  this->setPerm(perm);
}

int Student::getPerm() const {
  return this->perm;
}

const char * const Student::getName() const {
  return this->name;
}

void Student::setPerm(const int permNumber) {
  this->perm = permNumber; 
}

void Student::setName(const char * const name) {
  if (this->name != nullptr) {
      delete[] this->name; 
  }

  if (name == nullptr) {
    this->name = nullptr;
    return;
  }

  this->name = new char[strlen(name)+1];
  strcpy(this->name, name);
}


Student::Student(const Student &orig) {
  this->setName(orig.getName());
  this->setPerm(orig.getPerm());
}

Student::~Student() {
  delete[] this->name; 
  this->name = nullptr;
}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  const char* name = right.getName(); 
  int perm = right.getPerm(); 

  delete [] this->name; 
  this->setName(name);
  this->setPerm(perm);


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
  std::string returnString = "[";

  if (this->name != nullptr) {
    returnString += this->name;
  }
  returnString += ",";
  returnString += std::to_string(this->perm);
  returnString += "]";

  return returnString;
}

