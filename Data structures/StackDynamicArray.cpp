#include <iostream>

using namespace std;

struct node {
  int data;
  node *prev;
};

class Stekas {
private:
  node *top;

public:
  Stekas() // konstruktorius
  {
    top = NULL; // nullptr
  }

  void push(int value) {
    node *temp = new node;
    temp = new node; // iskiria vietos atminty node tipo kintamajam
    temp->data = value;
    temp->prev = top; // rodo i pries tai buvusi
    top = temp;       // naujas top
  }

  void display() // pakeisti po to, kad veiktu tik steko operacijomis
  {
    Stekas pagalbinis;
    while (!isEmpty()) {
      cout << peektop() << " ";
      pagalbinis.push(peektop());
      pop();
    }
    while (!pagalbinis.isEmpty()) {
      push(pagalbinis.peektop());
      pagalbinis.pop();
    }
  }

  // ~Stekas()
  // pop()
  void pop() {
    node *temp = top;
    if (temp != NULL) {
      top = temp->prev;
      delete temp;
    } else
      cout << "Stack overflow!";
  }
  int peektop() { // top()
    if (top != NULL)
      return top->data;
  }
  // isEmpty()
  bool isEmpty() { return (top == NULL); }

  int size() {
    int count = 0;
    node *temp = top;
    while (temp != NULL) {
      count++;
      temp = temp->prev;
    }
    return count;
  }
  void clear() {
    while (!isEmpty()) {
      pop();
    }
  }
};

int main() {
  Stekas s;
  s.push(1);
  s.pop();
  s.push(9);
  s.push(18);
  s.pop();
  s.push(11);
  s.push(0);
  s.display();
  cout << endl;
  cout << s.size();
  return 0;
}
