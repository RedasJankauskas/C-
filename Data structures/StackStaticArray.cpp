#include <iostream>

using namespace std;

#define MAXSIZE 14


class Stekas
{
private:
	int top; //kur virsus
	int array[MAXSIZE];

public:
	Stekas() // konstruktorius
	{
		top = -1;
	}

	bool isFull()  // tikrina ar stekas pilnas
	{
		return (top == MAXSIZE - 1);
	}

	void push(int value) // prideti elementa
	{
		if (isFull())
			cout << "OMG! Stekas pilnas!" << endl;
		else
		{
			top++;
			array[top] = value;
		}
	}
	//~Stekas()
	void pop() { //pop()
		if (top > -1) {
			array[top] = -1;
			top--;
		}
		else {
			cout << "Stack underflow!" << endl;
		}
	}
	int peektop() { //top()
		if (top > -1)
			return array[top];
	}
	bool isEmpty() { //isEmpty()
		return (top == -1);
	}


	void size() {
		if (top > -1) {
			cout << "Dydis - "<<top + 1;
		}
		else cout << "Stekas tuscias";
	}

	void clear() {
		if (top > -1) {
			while (!isEmpty()) {
				pop();
			}
		}
	}
};
int main() {
	int pagalbinis[MAXSIZE], pagalbinis_top=-1;
	Stekas s;
	s.push(19);
	s.push(27);
	s.push(36);
	s.push(44);
	s.push(52);

	while (!s.isEmpty()) { //Display()
		cout<<s.peektop()<<" ";
		pagalbinis_top++;
		pagalbinis[pagalbinis_top] = s.peektop();
		s.pop();
	}
	while (pagalbinis_top > -1) {
		s.push(pagalbinis[pagalbinis_top]);
		pagalbinis_top--;
	}

	s.push(97);
	s.size();
	s.clear();

	return 0;
}
