#include <iostream>
#include <fstream>

bool NAND(bool a, bool b);
bool NOT(bool a);
bool AND(bool a, bool b);
bool OR(bool a, bool b);
bool XOR(bool a, bool b);
bool NOR(bool a, bool b);
void ivedimas(bool in[], bool A[], bool B[]);
void minusB(bool B[]);
bool halfadder(bool a, bool b);
bool carry(bool a, bool b);
void fulladder(bool A[], bool B[],bool out[]);
void fulladderdaugyba(bool A[], bool S[]);
void AplusB(bool A[],bool B[], bool out[]);
void AminusB(bool A[],bool B[],bool out[]);
void daugyba(bool A[],bool B[], bool S[]);
void shiftleft(bool A[], bool out[]);
void shiftright(bool A[], bool out[]);
void minus1(bool A[]);
void lyginumas(bool A[], bool B[]);
bool Blygu0(bool A[], bool B[]);
void decoder(bool in[],bool A[],bool B[], bool out[], bool S[]);
void ALU(bool A[], bool B[], bool in[], bool out[], bool S[]);

using namespace std;

int main() {
  bool in[3], out[8]={false}, S[16]={0};
  bool A[8], B[8];
  ALU(A,B,in,out,S);
}
bool NAND(bool a, bool b){
if(a==1 && b==1)
return 0;
else return 1;
}

bool NOT(bool a){
  return NAND(a,a);
}

bool AND(bool a, bool b){
  return NAND(NAND(a,b),NAND(a,b));
}

bool OR(bool a, bool b){
  return NAND(NAND(a,a),NAND(b,b));
}

bool XOR(bool a, bool b){
 bool t1=NAND(a,b);
 bool t2=NAND(t1, a);
 bool t3=NAND(t1, b);
 return NAND(t2,t3);
}

bool NOR(bool a, bool b){
  bool t1=NAND(a,a);
  bool t2=NAND(b,b);
  bool t3=NAND(t1,t2);
  return NAND(t3,t3);
}

void ivedimas(bool in[], bool A[], bool B[]){
  cout<<"Įveskite 3 kontrolinius skaičius: "<<endl;
   for(int i=0;i<3;i++)
    cin>>in[i];
  cout<<endl;
  cout<<"Įveskite A reikšmes: "<<endl;
  for(int i=0;i<8;i++)
    cin>>A[i];
  cout<<endl;
  cout<<"Įveskite B reikšmes: "<<endl;
  for(int i=0;i<8;i++)
    cin>>B[i];
  cout<<endl;
}
void minusB(bool B[]){
  for(int i=0;i<8;i++){
    B[i]=NOT(B[i]);
  }
  bool vienas[8]={0,0,0,0,0,0,0,1};
  fulladder(B,vienas,B);
}
bool halfadder(bool a, bool b){
  if (XOR(a,b))
    return true;
  else
    return false;
}

bool carry(bool a, bool b){
  if(AND(a,b))
    return true;
  else return false;
}

void fulladder(bool A[], bool B[], bool out[]){
  bool carryout=false;
  bool carry1, carry2;
  bool sum1;
  for (int i = 7; i >= 0; i--){
    carry1=carry(A[i],B[i]);
    sum1=halfadder(A[i],B[i]);
    out[i]=halfadder(sum1,carryout);
    carry2=carry(sum1, carryout);
    carryout=OR(carry1,carry2);
  }
  out[8] = carryout;
  if(carryout==true)
    cout<<"Ivyko peripildymas..."<<endl;
}
void fulladderdaugyba(bool A[], bool S[]){ //blogai, reikia taisyti
  bool carryout=false;
  bool carry1, carry2;
  bool sum1;
  //bool temp[16];
  
  //for(int i=7;i>=0;i--)
  // temp[8+i]=A[i];
  
  for (int i = 15; i >= 0; i--){
    carry1=carry(A[i],S[i]);
    sum1=halfadder(A[i],S[i]);
    S[i]=halfadder(sum1,carryout);
    carry2=carry(sum1, carryout);
    carryout=OR(carry1,carry2);
  }
  if(carryout==true)
    cout<<"Ivyko peripildymas..."<<endl;
}

void AplusB(bool A[],bool B[], bool out[]){
  fulladder(A,B,out);
}
void AminusB(bool A[],bool B[],bool out[]){
  minusB(B);
  fulladder(A,B,out);
}
void daugyba(bool A[], bool B[], bool S[]){
  for(int i=7;i>=0;i--){
    if(B[7]==true){
    fulladderdaugyba(A,S);
    shiftleft(A,A);
    shiftright(B,B);
    }
    else{
    shiftleft(A,A);
    shiftright(B,B);
    }
  }
    
}
void shiftleft(bool A[], bool out[]){
    out[7]=AND(0,A[6]);
    for(int i=6;i>=0;i--){
    if(i!=0){
      out[i]=OR(AND(1,A[i+1]),AND(0,A[i-1]));
    }
      else
        out[i]=AND(1,A[i+1]);
  }}
void shiftright(bool A[], bool out[]){
  out[7]=AND(1,A[6]);
    for(int i=6;i>=0;i--){
    if(i!=0){
      out[i]=OR(AND(0,A[i+1]),AND(1,A[i-1]));
    }
      else
        out[i]=AND(0,A[i+1]);
  }
}
void minus1(bool A[]) {
  for(int i=7;i>=0;i--){
    if(XOR(0,A[i])){
      A[i]=false;
      break;
    }
    else{A[i]=true;}
  }
  }
void lyginumas(bool A[], bool B[]){
    bool x=true;
  for(int i=0;i<8;i++){
    for(int j=i+1;j<8;j++){
      if(NOR(XOR(A[i],B[i]),XOR(A[j],B[j]))==false)
        x=false;
      break;
  }
    if(x==false)
      break;
  }
     if(x==false)
      cout<<"Nelygūs"<<endl;
    else cout<<"Lygūs"<<endl;
}
bool Blygu0(bool A[], bool B[]){
  for(int i=0;i<8;i++) {
  A[i] = false;
}
  bool x=true;
  for(int i=0;i<8;i++){
    for(int j=i+1;j<8;j++){
      if(NOR(XOR(A[i],B[i]),XOR(A[j],B[j]))==false)
        x=false;
      break;
  }
    if(x==false)
      break;
  }
 return x;}

void decoder(bool in[],bool A[],bool B[], bool out[], bool S[]){
  if(AND(AND(NOT(in[0]),NOT(in[1])),NOT(in[2]))){
    AminusB(A,B,out);
    cout<<"A-B = ";
    for(int i=0;i<8;i++)
      cout<<out[i]<<" ";
    cout<<endl;}
  if(AND(AND(NOT(in[0]),NOT(in[1])),in[2])){
    AplusB(A,B,out);
    cout<<"A+B = ";
    for(int i=0;i<8;i++)
      cout<<out[i]<<" ";
    cout<<endl;}
  if(AND(AND(NOT(in[0]),NOT(in[2])),in[1])){
    daugyba(A,B,S);
    cout<<"A*B = ";
    for(int i=0;i<16;i++)
      cout<<S[i]<<" ";
    cout<<endl;}
  if(AND(NOT(in[0]), AND(in[1], in[2]))){
    shiftleft(A,out);
    cout<<"A pashiftintas į kaire = ";
    for(int i=0;i<8;i++)
      cout<<out[i]<<" ";
    cout<<endl;}
  if(AND(in[0], AND(NOT(in[1]), NOT(in[2])))){
    minus1(A);
    cout<<"A-1 = ";
    for(int i=0;i<8;i++)
      cout<<A[i]<<" ";
    cout<<endl;}
  if(AND(AND(in[0],in[2]), NOT(in[1]))){
    if(Blygu0(A,B)==false)
      cout<<"B!=0 - true";
    else cout<<"B!=0 - false";}
}

void ALU(bool A[], bool B[], bool in[], bool out[], bool S[]){
  ivedimas(in,A,B);
  lyginumas(A,B);
  decoder(in,A,B,out,S);
  
}