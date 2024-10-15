#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  //first thing, create a deep copy of Student
  Student* sCopy = new Student(s); 

  //create the object
  Node* newStudent = new Node(); 
  newStudent->next = nullptr;
  newStudent->s = sCopy;

  //check if its originally empty
  if (head == NULL) {
    head = newStudent;
    tail = newStudent;
  } else {
    tail->next = newStudent;
    tail = tail->next; 
  }
}

std::string StudentRoll::toString() const {
  if (this->head == nullptr) {
    return "[]";
  }

  std::string returnString = "["; 
  Node* shallowHead = this->head;
  while (shallowHead->next != nullptr) {
    returnString += shallowHead->s->toString(); 
    returnString += ","; 
    shallowHead = shallowHead->next; 
  }
  returnString += shallowHead->s->toString(); 
  returnString += "]";
  return returnString;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL;

  Node* current = orig.head;
  while (current != nullptr) {
    this->insertAtTail(*current->s);
    current = current->next; 
  }

}

StudentRoll::~StudentRoll() {
  Node* shallowHead = this->head;
  while (shallowHead != nullptr) {
    Node* dummyHead = shallowHead; 
    shallowHead = shallowHead->next; 
    delete dummyHead;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...

  Node* shallowHead = this->head;
  while (shallowHead != nullptr) {
    Node* dummyHead = shallowHead; 
    shallowHead = shallowHead->next; 
    delete dummyHead;  
  }

  head = tail = NULL;
  if (right.head == nullptr) {
    return (*this);
  }

  Node* current = right.head;
  while (current != nullptr) {
    this->insertAtTail(*current->s);
    current = current->next; 
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





