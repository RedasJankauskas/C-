#include <iostream>

using namespace std;

struct node {
  int data;
  node *next;
  node *prev;
};

class linkedList {
private:
  node *head;
  node *tail;
  node *prev;

public:
  linkedList() // konstruktorius
  {
    head = NULL;
    tail = NULL;
    prev = NULL;
  }

  void addNodeEnd(int value) {
    node *temp = new node; 
    
    temp->data = value; 
    
    temp->next = NULL;
    
    if (head == NULL) 
    {
      head = temp; 
      tail = temp;
      temp->prev = NULL;
    } else
    {
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
    }
  }

  void display() {
    if (head != NULL) {
      node *temp =
          head; // sukuria pagalbine "temp" rodykle ir ji rodo i pirma elementa
      while (temp != NULL) {
        cout << temp->data << "\t"; // #tab
        temp = temp->next;          // rodykle rodo i sekanti elementa
      }
    } else
      cout << "Sarasas tuscias." << endl;
  }

  void addNodeStart(int value) {
    // naudoti galvute/head surasti pirma pozicija
    node *temp = new node;
    if (head != NULL) {
      temp->next = head;
      temp->data = value;
      temp->prev = NULL;
      head = temp;
    } else {
      temp->data = value;
      temp->next = NULL;
      temp->prev = NULL;
      head = temp;
      tail = temp;
    }
  }
  void addNodePos(int pos, int value) {
    // 1. - nubegti iki pozicijos, i kuria reikia iterpti
    // 2. - ideti nauja mazga ir sukeisti rodykles
    node *temp = new node;
    node *pre = new node;
    pre = head;

    if (pos > 1 && head != NULL) {
      for (int i = 1; i < pos - 1; i++)
        pre = pre->next;

      temp->data = value;
      temp->next = pre->next;
      temp->prev = pre;
      pre->next = temp;
    } else if (pos == 1) {
      addNodeStart(value);
    }

    // nepamirsti kitu funkciju ir destruktoriaus
  }
  void deleteNodeStart() {

    if (head != NULL) {
      node *temp = new node;
      temp = head;
      head = head->next;
      delete temp;
    } else
      cout << "Nera ka istrinti, sarasas jau tuscias!";
  }

  void deleteNodePos(int pos) {
    node *pre = new node;
    pre = head;
    if (pos > 1 && head != NULL) {
      for (int i = 1; i < pos - 1; i++)
        pre = pre->next;

      node *cur = new node;
      cur = pre->next;
      pre->next = cur->next;
      delete cur;
    } else if (pos == 1 && head != NULL) {
      node *cur = new node;
      cur = head;
      head = head->next;
      delete cur;
    } else
      cout << "Sarasas tuscias arba blogas ivedimas." << endl;
  }

  void deleteNodeEnd() {
    node *temp = new node;
    temp = head;

    while (temp->next != tail) {
      temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = NULL;
  }

  void search(int value) {
    node *temp = new node;
    int pos = 1;
    if (head != NULL) {
      temp = head;
      while (temp->data != value && temp->next != NULL) {
        temp = temp->next;
        pos++;
      }
      if (temp->data == value)
        cout << "elemento pozicija: " << pos << endl;
      else
        cout << "Nera tokio elemento." << endl;
    } else {
      cout << "Sarasas tuscias" << endl;
    }
  }

  void clear() {
    node *temp = new node;
    if (head != NULL) {
      while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
      }
      tail = NULL;
    } else
      cout << "Sarasas jau tuscias." << endl;
  }
  bool isEmpty() {
    if (head != NULL)
      return 0;
    else
      return 1;
  }

  void reverse() {
    if (head != NULL) {
        if (head != tail) {
            node *temp = head;
            node *nxt = NULL;

            while (temp != NULL) {
                nxt = temp->next;
                temp->next = temp->prev;
                temp->prev = temp;
              if(nxt==NULL)
                break;
                temp = nxt;
            }

            tail = head;
            head = temp->prev;} 
          
        else cout << "Sarase tik 1 elementas, nera ka apsukti."<<endl;} 
      
    else cout << "Sarasas tuscias." << endl;
    
}
};

int main() {
  linkedList listas;

  listas.addNodeStart(95);
  listas.addNodeEnd(13);
  listas.addNodeEnd(54);
  listas.addNodeEnd(82);
  listas.display();
  listas.reverse();
  cout<<endl;
  listas.display();

  system("pause");
  return 0;
}
