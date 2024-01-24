#include <iostream>
#include <fstream>

using namespace std;

void vienasbaitas(int sk);
void dubaitai(int sk);
void trysbaitai(int sk);
void keturibaitai(int sk);

void vienasbaitasfailas(int sk1);
void dubaitaifailas(int sk1);
void trysbaitaifailas(int sk1);
void keturibaitaifailas(int sk1);

int main(){
  ifstream fin("386intel.txt");
  ofstream fout("output.txt");
  
  int sk;
  cin>>sk;
  vienasbaitas(sk);
  dubaitai(sk);
  trysbaitai(sk);
  keturibaitai(sk);

unsigned char symbol;
int sk1;
while(!fin.eof()){
  symbol=fin.get();
  sk1=int(symbol);
  vienasbaitasfailas(sk1);
  dubaitaifailas(sk1);
  trysbaitaifailas(sk1);
  keturibaitaifailas(sk1);
}
fin.close();
return 0;
}
void vienasbaitas(int sk){
   if(sk >= 0x0000 && sk <= 0x007F){
    unsigned char utf[1];
    unsigned char uni[2];
    char temp[1];
    
    utf[0]=0b00000000;
    
    utf[0]=utf[0] | (sk & 0b1111111);

    temp[0]=utf[0];
    
    uni[1] = temp[0] & 0b00001111;
    uni[0] = (temp[0] & 0b11110000) >> 4;
    
    
    printf("Unicode: U+00%01X%01X", uni[0], uni[1]);
    cout<<endl;
    printf("UTF-8: %02X", utf[0]);
    cout<<endl<<"CHAR: "<<utf<<endl;
  }
  
}

void dubaitai(int sk){
    if(sk >= 0x80 && sk <= 0x7FF){
    unsigned char utf[2];
    /*int galutinis;
    //unsigned char uni[3];
    char temp[2];*/
    
    utf[1]=0b10000000;
    utf[1]= utf[1] | (sk & 0b111111);

    utf[0] = 0b11000000;
    utf[0]= utf[0] | ((sk >> 6) & 0b11111);
    
    //temp[1]=utf[1];
    //temp[0]=utf[0];

    /*uni[0] = (temp[0] & 0b00001111);
    uni[1] = (temp[0] & 0b00001111) << 6;
    uni[2] = (temp[1] & 0b00111111);
    galutinis= uni[0] | uni[1] | uni[2];
    printf("Unicode: U+%04X", galutinis)*/
    
    printf("Unicode: U+%04X", sk);
    cout<<endl;
    printf("UTF-8: %02X %02X", utf[0], utf[1]);
    cout<<endl<<"CHAR: "<<utf<<endl;
    
  }
}

void trysbaitai(int sk){
  if(sk >= 0x0800 && sk <=0xFFFF){
    unsigned char utf[3];
    
    utf[2]=0b10000000;
    utf[2]= utf[2] | (sk & 0b111111);

    utf[1]=0b10000000;
    utf[1]= utf[1] | ((sk >> 6) & 0b111111);

    utf[0]=0b11100000;
    utf[0]= utf[0] | ((sk >> 12) & 0b1111);
    
    printf("Unicode: U+%04X", sk);
    cout<<endl;
    printf("UTF-8: %02X %02X %02X", utf[0], utf[1], utf[2]);
    cout<<endl<<"CHAR: "<<utf<<endl;
  }
}

void keturibaitai(int sk){
  if (sk >= 0x10000 && sk <= 0x10FFFF) {
    unsigned char utf[4];
  
    utf[3] = 0b10000000;
    utf[3] = utf[3] | (sk & 0b111111);
  
    utf[2] = 0b10000000;
    utf[2] = utf[2] | ((sk >> 6) & 0b111111);
  
    utf[1] = 0b10000000;
    utf[1] = utf[1] | ((sk >> 12) & 0b111111);
  
    utf[0] = 0b11110000;
    utf[0] = utf[0] | ((sk >> 18) & 0b111);

    printf("Unicode: U+%04X", sk);
    cout<<endl;
    printf("UTF-8: %02X %02X %02X %02X", utf[0], utf[1], utf[2], utf[3]);
    cout<<endl<<"CHAR: "<<utf<<endl;
}
}

void vienasbaitasfailas(int sk1){
  ofstream fout("output.txt");
  fout.open("output.txt");
   if(sk1 > 0x0000 && sk1 < 0x007F){
    char utf[1];
    
    utf[0]=0b00000000;
    
    utf[0]=utf[0] | (sk1 & 0b1111111);
    
    fout<<utf[0];
  }
  fout.close();
}

void dubaitaifailas(int sk1){
  ofstream fout("output.txt");
  fout.open("output.txt");
    if(sk1 > 0x80 && sk1 < 0x7FF){
    char utf[2];
    /*int galutinis;
    //unsigned char uni[3];
    char temp[2];*/
    
    utf[1]=0b10000000;
    utf[1]= utf[1] | (sk1 & 0b111111);

    utf[0] = 0b11000000;
    utf[0]= utf[0] | ((sk1 >> 6) & 0b11111);
    
    //temp[1]=utf[1];
    //temp[0]=utf[0];

    /*uni[0] = (temp[0] & 0b00001111);
    uni[1] = (temp[0] & 0b00001111) << 6;
    uni[2] = (temp[1] & 0b00111111);
    galutinis= uni[0] | uni[1] | uni[2];
    printf("Unicode: U+%04X", galutinis)*/
    
    fout<<utf[0]<<utf[1];
    fout.close();
  }
}

void trysbaitaifailas(int sk1){
  ofstream fout("output.txt");
  fout.open("output.txt");
  if(sk1 > 0x0800 && sk1 < 0xFFFF){
    char utf[3];
    
    utf[2]=0b10000000;
    utf[2]= utf[2] | (sk1 & 0b111111);

    utf[1]=0b10000000;
    utf[1]= utf[1] | ((sk1 >> 6) & 0b111111);

    utf[0]=0b11100000;
    utf[0]= utf[0] | ((sk1 >> 12) & 0b1111);
    
    fout<<utf[0]<<utf[1]<<utf[2];
    fout.close();
  }
}

void keturibaitaifailas(int sk1){
  ofstream fout("output.txt");
  fout.open("output.txt");
  if (sk1 > 0x10000 && sk1 < 0x10FFFF) {
    char utf[4];
  
    utf[3] = 0b10000000;
    utf[3] = utf[3] | (sk1 & 0b111111);
  
    utf[2] = 0b10000000;
    utf[2] = utf[2] | ((sk1>> 6) & 0b111111);
  
    utf[1] = 0b10000000;
    utf[1] = utf[1] | ((sk1 >> 12) & 0b111111);
  
    utf[0] = 0b11110000;
    utf[0] = utf[0] | ((sk1 >> 18) & 0b111);

    fout<<utf[0]<<utf[1]<<utf[2]<<utf[3];
    fout.close();
}
}