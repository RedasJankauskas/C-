//This program reads an encoded program from a "decryptor.bin" file and executes the instructions and outputs a specific result.


#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

void increase(unsigned char regs[], char progmem[], int &j);
void decrease(unsigned char regs[], char progmem[], int &j);
void move(unsigned char regs[], char progmem[], int &j);
void movc(unsigned char regs[], char progmem[], int &j);
void lsl(unsigned char regs[], char progmem[], int &j);
void lsr(unsigned char regs[], char progmem[], int &j);
void jmp(char progmem[], int &j, int i, char &veliava);
void jz(char progmem[], int &j, int i, char &veliava);
void jnz(char progmem[], int &j, int i, char &veliava);
void jfe(char progmem[], int &j, int i, char &veliava);
void add(unsigned char regs[], char progmem[], int &j);
void sub(unsigned char regs[], char progmem[], int &j);
void XOR(unsigned char regs[], char progmem[], int &j);
void OR(unsigned char regs[], char progmem[], int &j);
void in(unsigned char regs[], char progmem[], int &j, int &kiek);
void out(unsigned char regs[], char progmem[], int &j);
void jo(char progmem[], int &j, int i, char &veliava);
void testuojam(unsigned char regs[], char progmem[]);

int main() {
  unsigned char regs[16] = {0};
  char progmem[256];
  char veliava = veliava & 0b00000000;
  char a;
  ifstream fin;
  int i = 0;
  fin.open("decryptor.bin", ios::in | ios::binary);

  while (fin.get(a)) {
    progmem[i] = a;
    i++;
  }
  fin.close();

  fin.open("q1_encr.txt");
  int j = 0;

  while (progmem[j] != 0b1011) {
    if (progmem[j] == 0b1) {
      increase(regs, progmem, j);
      j += 2;
    }
    if (progmem[j] == 0b10) {

      decrease(regs, progmem, j);
      j += 2;
    }
    if (progmem[j] == 0b11) {

      move(regs, progmem, j);
      j += 2;
    }
    if (progmem[j] == 0b100) {

      movc(regs, progmem, j);
      j += 2;
    }
    if (progmem[j] == 0b101) {

      lsl(regs, progmem, j);
      j += 2;
    }
    if (progmem[j] == 0b110) {

      lsr(regs, progmem, j);
      j += 2;
    }
    if (progmem[j] == 0b111) {

      j = j + (signed)progmem[j + 1];
    }
    if (progmem[j] == 0b1000) {

      if ((veliava & 0b1) == 0b1) {
        j = j + (signed)progmem[j + 1];
      } else {
        j += 2;
      }
    }
    if (progmem[j] == 0b1001) {

      if ((veliava & 0b1) != 0b1)
        j = j + (signed)progmem[j + 1];
      else {
        j += 2;
      }
    }
    if (progmem[j] == 0b1010) {

      if ((veliava & 0b100) == 0b100)
        j = j + (signed)progmem[j + 1];
      else
        (j += 2);
    }
    if (progmem[j] == 0b1100) {

      add(regs, progmem, j);
      j += 2;
    }
    if (progmem[j] == 0b1101) {

      sub(regs, progmem, j);
      j += 2;
    }
    if (progmem[j] == 0b1110) {

      XOR(regs, progmem, j);
      j += 2;
    }
    if (progmem[j] == 0b1111) {

      OR(regs, progmem, j);
      j += 2;
    }
    if (progmem[j] == 0x10) {

      if (!fin.eof()) {
        char symbol;
        fin >> symbol;
        unsigned char RX = progmem[j + 1] & 0b11111111;
        regs[RX] = symbol;
      } else {
        veliava = veliava | 0b100;
      }
      j += 2;
    }
    if (progmem[j] == 0x11) {

      out(regs, progmem, j);
      j += 2;
    }
    if (progmem[j] == 0x12) {

      if ((veliava & 0b10) == 0b10)
        j = j + (signed)progmem[j + 1];
      else
        (j += 2);
    }
  }
  cout<<endl;
  cout << "Testai!!!!!!!"<<endl;
  testuojam(regs, progmem);
  return 0;
}

void increase(unsigned char regs[], char progmem[], int &j) {
  unsigned char RX = progmem[j + 1] & 0x0F;
  regs[RX] += 1;
  //cout << "01- reg[" << RX << "] = " << regs[RX] << "/n";
}
void decrease(unsigned char regs[], char progmem[], int &j) {
  unsigned char RX = progmem[j + 1] & 0x0F;
  regs[RX] -= 1;
}
void move(unsigned char regs[], char progmem[], int &j) {
  unsigned char RX = progmem[j + 1] & (0x0F);
  unsigned char RY = (progmem[j + 1] & (0xF0)) >> 4;
  regs[RX] = regs[RY];
}
void movc(unsigned char regs[], char progmem[], int &j) {
  regs[0] = progmem[j + 1];
}
void lsl(unsigned char regs[], char progmem[], int &j) {
  unsigned char RX = progmem[j + 1] & 0x0F;
  regs[RX] <<= 1;
}
void lsr(unsigned char regs[], char progmem[], int &j) {
  unsigned char RX = progmem[j + 1] & 0x0F;
  regs[RX] >>= 1;
}
void jmp(char progmem[], int &j, int i, char &veliava) {
  int kieksokt = progmem[j + 1] % i;
  if (kieksokt > 0) {
    while (kieksokt > 0) {
      if (j != i) {
        j++;
        kieksokt--;
      } else {
        veliava = veliava | 0b100;
        j = 0;
        j++;
        kieksokt--;
      }
    }
  }
}
void jz(char progmem[], int &j, int i, char &veliava) {
  int kieksokt = progmem[j + 1] % i;
  if (kieksokt > 0) {
    while (kieksokt > 0) {
      if (j != i) {
        j++;
        kieksokt--;
      } else {
        veliava = veliava | 0b100;
        j = 0;
        j++;
        kieksokt--;
      }
    }
  }
}
void jnz(char progmem[], int &j, int i, char &veliava) {
  int kieksokt = progmem[j + 1] % i;
  if (kieksokt > 0) {
    while (kieksokt > 0) {
      if (j != i) {
        j++;
        kieksokt--;
      } else {
        veliava = veliava | 0b100;
        j = 0;
        j++;
        kieksokt--;
      }
    }
  }
}
void jfe(char progmem[], int &j, int i, char &veliava) {
  int kieksokt = progmem[j + 1] % i;
  if (kieksokt > 0) {
    while (kieksokt > 0) {
      if (j != i) {
        j++;
        kieksokt--;
      } else {
        j = 0;
        j++;
        kieksokt--;
      }
    }
  }
}
void add(unsigned char regs[], char progmem[], int &j) {
  unsigned char RX = progmem[j + 1] & (0x0F);
  unsigned char RY = (progmem[j + 1] & (0xF0))>>4;
  regs[RX] = regs[RX] + regs[RY];
}
void sub(unsigned char regs[], char progmem[], int &j) {
  unsigned char RX = (progmem[j + 1] & 0x0F);
  unsigned char RY = (progmem[j + 1] & (0xF0))>>4;
  regs[RX] = regs[RX] - regs[RY];
}
void XOR(unsigned char regs[], char progmem[], int &j) {
  unsigned char RX = progmem[j + 1] & (0x0F);
  unsigned char RY = (progmem[j + 1] & (0xF0)) >>4;
  regs[RX] = regs[RX] ^ regs[RY];
}
void OR(unsigned char regs[], char progmem[], int &j) {
  unsigned char RX = progmem[j + 1] & (0x0F);
  unsigned char RY = (progmem[j + 1] & (0xF0)) >>4;
  regs[RX] = regs[RX] | regs[RY];
}
void in(unsigned char regs[], char progmem[], int &j) {
  ifstream fin("q1_encr.txt");
  char symbol;
  fin >> symbol;
  unsigned char RX = progmem[j + 1] & 0b1111;
  regs[RX] = symbol;
}
void out(unsigned char regs[], char progmem[], int &j) {
  unsigned char RX = progmem[j + 1] & 0x0F;
  cout << regs[RX];
}
void jo(char progmem[], int &j, int i, char &veliava) {
  int kieksokt = progmem[j + 1] % i;
  if (kieksokt > 0) {
    while (kieksokt > 0) {
      if (j != i) {
        j++;
        kieksokt--;
      } else {
        veliava = veliava | 0b100;
        j = 0;
        j++;
        kieksokt--;
      }
    }
  }
}
void testuojam(unsigned char regs[], char progmem[]) {
  int j = 6;
  unsigned char RX = progmem[j + 1] & 0x0F;
  regs[RX] = 5;
  regs[RX] += 1;
  printf("%1X", regs[RX]);
  j += 2;
  cout << endl; // 1 funkc

  j = 6;
  RX = progmem[j + 1] & 0x0F;
  regs[RX] = 5;
  regs[RX] -= 1;
  printf("%1X", regs[RX]);
  j += 2;
  cout << endl; // 2 funkc

  j = 28;
  j = j + (signed)progmem[j + 1];
  printf("%1X", j); // suoliai
  cout << endl;

  j = 22;
  RX = (progmem[j + 1] & (0x0F));
  unsigned char RY = (progmem[j + 1] & (0xF0)) >> 4;
  regs[RX]=24;
  regs[RY]=81;
  regs[RX]=regs[RX] ^ regs[RY];
  printf("%1d", regs[RX]); // tvarkom RX, RY
}