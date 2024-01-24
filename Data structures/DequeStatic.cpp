#include <iostream>

#define MAXSIZE 10

using namespace std;

class QueueArray {
private:
  int first, last;
  char queue[MAXSIZE] = {0};

public:
  QueueArray() // konstruktorius
  {
    first = -1;
    last = -1;
  }

  void enqueue(char value) // prideti elementa i eiles pabaiga
  {
    if (isFull()) {
      cout << "Eile yra uzpildyta, negalima prideti naujo elemento. \n";
      return;
    } else if (isEmpty()) {
      first = 0;
      last = 0;
      queue[first] = value;
    } else {
      if (last != MAXSIZE - 1) {
        last++;
        queue[last] = value;
      } else {
        last = 0;
        queue[last] = value;
      }
    }
  }

  void dequeue() {
    if (first != MAXSIZE - 1) {
      queue[first] = ' ';
      if (queue[first + 1] != ' ')
        first++;
      else {
        first = -1;
        last = -1;
      }
    } else {
      queue[first] = ' ';
      first = 0;
      if (queue[first] == ' ') {
        first = -1;
        last = -1;
      }
    }
  }

  char peekFirst() {
    if (first != -1)
      return queue[first];
    else {
      return NULL;
    }
  }
  char peekLast() {
    if (last != -1)
      return queue[last];
    else
      return NULL;
  }

  bool isFull() {
    if (size() == MAXSIZE)
      return true;
    else
      return false;
  }
  bool isEmpty() {
    if (last == -1)
      return true;
    else
      return false;
  }
  int size() {
    if (isEmpty()) {
      return 0;
    } else if (last >= first) {
      return (last - first + 1);
    } else {
      return (MAXSIZE - first + last + 1);
    }
  }
  void reverse() { //not fully done
    int x = size();
    if (x > 1) {
      int i = first;
      int j = last;
      if(j>i){
      while (i < j) {
        char temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
        i++;
        j--;
      }}
      else if(i>j){
        while(queue[i]!=queue[j] && queue[i]!=queue[j-1])
      }
    } else {
      cout << "Eile tuscia" << endl;
    }
  }
void display(){
  if(isEmpty()){
    cout<<"Sarasas tuscias"<<endl;
  }
  else if(!isFull()){
    for(int i=0;i<size();i++){
    char temp=peekFirst();
    cout<<peekFirst()<<" ";
    enqueue(temp);
    dequeue();}
  }
  else{
    for(int i=0;i<size();i++){
    char temp=peekFirst();
    cout<<peekFirst()<<" ";
    dequeue();
    enqueue(temp);}
  }
}
};

int main() {
  QueueArray q;
  q.enqueue('a');
  q.enqueue('a');
  q.enqueue('a');
  q.enqueue('a');
  q.enqueue('a');
  q.enqueue('b');
  q.enqueue('b');
  q.enqueue('b');
  q.enqueue('b');
  q.enqueue('b');

  q.display();
  cout<<endl;
  std::cout << "\n--------------------------------------------------\n";
  

  system("pause");
  return 0;
}
