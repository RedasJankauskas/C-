#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct parametrai{
    int busena;
    char read;
    char write;
    char move;
    int next;
};
struct parametraidviem{
    int busena;
    char read, read1;
    char write, write1;
    char move, move1;
    int next;
};

void vienajuosta(vector <parametrai> taisykles, string a, int head);

void dvijuostos(vector <parametraidviem> taisykles, string a, string a1, int head, int head1);

void keturiosjuostos(vector <parametrai> taisykles, string &a, int &head, int &steps, bool &x, int &dabartine);



int main(){
  ifstream fin;
    bool y;
    cout<<"Ar norite vienu metu vykdyti kelias Tiuringo mašinas? Įveskite 1 jeigu Taip, 0 jeigu Ne"<<endl;
    cin>>y;
   
if(y){
  cout<<"Vykdoma 1.txt, 2.txt, 3.txt, 4.txt..."<<endl;

  string juosta;
  int head,head1,head2,head3;
  int busena,next;
  char read,write,move;
  fin.open("1.txt");
      
  fin.ignore();
  fin>>juosta;
  string a=" " + juosta + " ";
  fin>>head;

  vector<parametrai> taisykles;
  while (fin>>busena>>read>>write>>move>>next) {
  taisykles.push_back({busena, read, write, move, next});
        }
  fin.close();
      
  fin.open("2.txt");
  fin.ignore();
  fin>>juosta;
  string a1=" " + juosta + " ";
  fin>>head1;
  vector<parametrai> taisykles1;
  while (fin>>busena>>read>>write>>move>>next) {
  taisykles1.push_back({busena, read, write, move, next});
        }
  fin.close();
      
  fin.open("3.txt");
  fin.ignore();
  fin>>juosta;
   string a2=" " + juosta + " ";
  fin>>head2;
  vector<parametrai> taisykles2;
  while (fin>>busena>>read>>write>>move>>next) {
  taisykles2.push_back({busena, read, write, move, next});
        }
  fin.close();
      
  fin.open("4.txt");
  fin.ignore();
  fin>>juosta;
   string a3=" " + juosta + " ";
  fin>>head3;
  vector<parametrai> taisykles3;
  while (fin>>busena>>read>>write>>move>>next) {
  taisykles3.push_back({busena, read, write, move, next});
        }
  fin.close();
  int steps=0, steps1=0,steps2=0,steps3=0;
  int dabartine=0,dabartine1=0,dabartine2=0,dabartine3=0;
  bool x=0, x1=0, x2=0, x3=0;
  while(steps<10000 && steps1<10000 && steps2<10000 && steps3<10000){
    if(x==false){
    keturiosjuostos(taisykles,a,head,steps,x,dabartine);
    }
    if(x1==false){
    keturiosjuostos(taisykles1,a1,head1,steps1,x1,dabartine1);
    }
    if(x2==false){
    keturiosjuostos(taisykles2,a2,head2,steps2,x2,dabartine2);
    }
    if(x3==false){
    keturiosjuostos(taisykles3,a3,head3,steps3,x3,dabartine3);
    }
  
  }}
    else{
    int sk;
    cout<<"Kuri .txt failą vykdyti (1,2,3,4,5,6)?"<<endl;
      cin>>sk;
    if(sk==1)
      fin.open("1.txt");
    else if(sk==2)
      fin.open("2.txt");
    else if(sk==3)
      fin.open("3.txt");
    else if(sk==4)
      fin.open("4.txt");
    else if(sk==5)
      fin.open("5.txt");
    else if(sk==6)
      fin.open("6.txt");
    else{cout<<"Dėja, bet tokio failo nėra :(";}
    

    int n;
    fin>>n;

if (n==1){
  string juosta;
  fin>>juosta;
  string a=" " + juosta + " ";
  int head;
  fin>>head;
  int busena,next;
  char read,write,move;

  vector<parametrai> taisykles;
  while (fin>>busena>>read>>write>>move>>next) {
  taisykles.push_back({busena, read, write, move, next});
        }
  vienajuosta(taisykles,a,head);
}
if (n==2){
  string juosta, juosta1;
  fin>>juosta>>juosta1;
  string a=" "+ juosta + " ";
  string a1=" "+ juosta1 + " ";
  int head, head1;
  fin>>head>>head1;
  int busena, next;
  char read, read1, write, write1, move, move1;
  vector<parametraidviem> taisykles;
  while (fin>>busena>>read>>read1>>write>>write1>>move>>move1>>next) {
  taisykles.push_back({busena, read, read1, write, write1, move, move1, next});
}
  dvijuostos(taisykles,a, a1, head, head1);
}}
}
void vienajuosta(vector <parametrai> taisykles, string a, int head){
        int dabartine=0;
        int steps=0;
        while (steps<10000) {
          string prjuosta=a;
            bool x=0;
            for (int i = 0; i < taisykles.size(); i++) {
            if (taisykles[i].busena == dabartine && taisykles[i].read == a[head]) {
                a[head] = taisykles[i].write;
                if (taisykles[i].move == 'R') {
                    head++;
                }
                else if (taisykles[i].move == 'L') {
                    head--;
                }
                dabartine = taisykles[i].next;
                x = true;
                break;
            }
            else if (taisykles[i].busena == dabartine && taisykles[i].read == '*') {
              
                if(taisykles[i].write!='*')
                a[head] = taisykles[i].write;
                  
                if (taisykles[i].move == 'R') {
                    head++;
                }
                else if (taisykles[i].move == 'L') {
                    head--;
                }
                dabartine = taisykles[i].next;
                x = true;
                break;
            }
        }
            if (x==0) {
                cout<<"Programa sustojo dėl taisyklių neapibrėžtumo" << endl;
              cout<<steps;
                break;
            }
      else{}
        if(a!=prjuosta){
          for(int i=0;i<a.length();i++){
          cout<<a[i];}
           cout<<endl;
        }
          steps++;
          if(steps==10000){
            bool testi;
            cout<<"Programa jau įvykdė 10000 žingsnių, ar norite tęsti? Įrašykite 1 jeigu Taip, 0 jeigu Ne"<<endl;
            cin>>testi;
            if(testi)
              steps=0;
              else{
                cout<<"Programa buvo sustabdyta žmogaus";
                break;
              }
          }
        }
    }
void dvijuostos(vector <parametraidviem> taisykles, string a, string a1, int head, int head1){
  int steps=0;
  int dabartine=0;
    while(steps<=10000){
        string prjuosta=a;
        string prjuosta1=a1;
        bool x=0;
        for(int i=0; i<taisykles.size(); i++){
            if(taisykles[i].busena==dabartine && taisykles[i].read==a[head] && taisykles[i].read1==a1[head1]){
              
                a[head] = taisykles[i].write;
                a1[head1] = taisykles[i].write1;
              
                if(taisykles[i].move=='R'){
                    head++;}
                else if(taisykles[i].move=='L'){
                    head--;}
                if(taisykles[i].move1=='R'){
                    head1++;}
                else if(taisykles[i].move1=='L'){
                    head1--;}
              
                dabartine=taisykles[i].next;
                x=1;
                break;
            }
        }
      
      steps++;
      
        if(x==0){
            cout << "Programa sustojo dėl taisyklių neapibrėžtumo" << endl;
            break;
        }
        if(a!=prjuosta){
          for(int i=0;i<a.length();i++){
          cout<<a[i];}
          cout<<endl;
        }
      if(a1!=prjuosta1){
          for(int i=0;i<a1.length();i++){
          cout<<a1[i];}
          cout<<endl;
        }

      if(steps==10000){
            bool testi;
            cout<<"Programa jau įvykdė 10000 žingsnių, ar norite tęsti? Įrašykite 1 jeigu Taip, 0 jeigu Ne"<<endl;
            cin>>testi;
            if(testi)
              steps=0;
              else{
                cout<<"Programa buvo sustabdyta žmogaus";
                break;
              }
          }
    }
}
void keturiosjuostos(vector <parametrai> taisykles, string &a, int &head, int &steps, bool &x, int &dabartine){
          string prjuosta=a;
            bool y=0;
            for (int i = 0; i < taisykles.size(); i++) {
            if (taisykles[i].busena == dabartine && taisykles[i].read == a[head]) {
                a[head] = taisykles[i].write;
                if (taisykles[i].move == 'R') {
                    head++;
                }
                else if (taisykles[i].move == 'L') {
                    head--;
                }
                dabartine = taisykles[i].next;
                y = true;
                break;
            }
            else if (taisykles[i].busena == dabartine && taisykles[i].read == '*') {
              
                if(taisykles[i].write!='*')
                a[head] = taisykles[i].write;
                  
                if (taisykles[i].move == 'R') {
                    head++;
                }
                else if (taisykles[i].move == 'L') {
                    head--;
                }
                dabartine = taisykles[i].next;
                y=true;
                break;
            }
        }
            if (y==0) {
                cout<<"Programa sustojo dėl taisyklių neapibrėžtumo, įrašykite bet kokį simbolį, kad tęstumėte." << endl;
              string m;
              cin>>m;
    x=true;
            }
        if(a!=prjuosta){
          for(int i=0;i<a.length();i++){
          cout<<a[i];}
           cout<<endl;
        }
          steps++;
          if(steps==10000){
            bool testi;
            cout<<"Programa jau įvykdė 10000 žingsnių, ar norite tęsti? Įrašykite 1 jeigu Taip, 0 jeigu Ne"<<endl;
            cin>>testi;
            if(testi)
              steps=0;
              else{
                steps=0;
                x=true;
                cout<<"Programa buvo sustabdyta žmogaus";
              }
          }
        }