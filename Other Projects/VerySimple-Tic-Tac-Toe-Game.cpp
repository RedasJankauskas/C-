#include <iostream>
using namespace std;

class Zaidimas {
protected:
    char pozicijos[3][3];
    char simbolis = 'X';
    int eil, stulp, langelis;
    bool k;
    string laimetojas;

public:
    void pradedam() {
        cout << "KRYZIUKAI NULIUKAI -- REDAS J" << endl;
        cout << endl;
        cout << "Pasirinkite, ar norite zaisti pries kompiuteri, ar drauga. Irasykite 0, jei pries kompiuteri, 1, jei pries drauga."<<endl;
      cin>>k;
        cout << endl;
        cout << "PRADEDAM! pirmas ejimas - jusu!!" << endl;
        cout << endl;
    }

    void skaiciai() {
        int k = 0;
        for (int i = 0; i < 3; i++) {
            if (i == 0)
                k = 0;
            else if (i == 1)
                k = 3;
            else
                k = 6;
            for (int j = 0; j < 3; j++) {
                pozicijos[i][j] = static_cast<char>(k + j + 49);
            }
        }
    }

    void lenta() {
        cout << "     |     |     " << endl;
        cout << "  " << pozicijos[0][0] << "  |  " << pozicijos[0][1] << "  |  " << pozicijos[0][2] << "  " << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << pozicijos[1][0] << "  |  " << pozicijos[1][1] << "  |  " << pozicijos[1][2] << "  " << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << pozicijos[2][0] << "  |  " << pozicijos[2][1] << "  |  " << pozicijos[2][2] << "  " << endl;
        cout << "     |     |     " << endl;
    }

    bool nepilna() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (pozicijos[i][j] != 'X' && pozicijos[i][j] != 'O')
                    return true;
            }
        }
        return false;
    }

    bool laimejo() {
        for (int i = 0; i < 3; i++) {
            if (pozicijos[i][0] == pozicijos[i][1] && pozicijos[i][0] == pozicijos[i][2])
                return true;
            if (pozicijos[0][i] == pozicijos[1][i] && pozicijos[0][i] == pozicijos[2][i])
                return true;
        }

        if (pozicijos[0][0] == pozicijos[1][1] && pozicijos[0][0] == pozicijos[2][2])
            return true;
        if (pozicijos[0][2] == pozicijos[1][1] && pozicijos[0][2] == pozicijos[2][0])
            return true;

        return false;
    }

    void zaidziam() {
        lenta();
        while (nepilna() && !laimejo()) {
            if(k==true)
              prieszaideja();
            else{prieskompiuteri();}
            lenta();
        }

        if (laimejo()) {
            if (simbolis == 'O'){
              if(k==1)
                laimetojas = "Zaidejas 1";
              else laimetojas="JUS!";}
            else{
              if(k==1)
                laimetojas = "Zaidejas 2";
              else laimetojas="KOMPIUTERIS!";}
            cout << laimetojas << " laimejo!" << endl;
        } else {
            cout << "Lygiosios!" << endl;
        }
    }

    virtual void prieszaideja() = 0;
    virtual void prieskompiuteri() = 0;
};

class grajus : public Zaidimas {
public:
    grajus() : Zaidimas() {}

    void prieszaideja() {
        if (simbolis == 'X') {
            cout << "Iveskite i kuri langeli norite irasyti X." << endl;
            cin >> langelis;
        } else if (simbolis == 'O') {
            cout << "Iveskite i kuri langeli norite irasyti O." << endl;
            cin >> langelis;
        }
        switch (langelis) {
        case 1:
            eil = 0;
            stulp = 0;
            break;
        case 2:
            eil = 0;
            stulp = 1;
            break;
        case 3:
            eil = 0;
            stulp = 2;
            break;
        case 4:
            eil = 1;
            stulp = 0;
            break;
        case 5:
            eil = 1;
            stulp = 1;
            break;
        case 6:
            eil = 1;
            stulp = 2;
            break;
        case 7:
            eil = 2;
            stulp = 0;
            break;
        case 8:
            eil = 2;
            stulp = 1;
            break;
        case 9:
            eil = 2;
            stulp = 2;
            break;
        default:
            cout << "NETEISINGAS IVEDIMAS"<<endl;
            break;
        }
        if (simbolis == 'X' && pozicijos[eil][stulp] != 'X' && pozicijos[eil][stulp] != 'O') {
            pozicijos[eil][stulp] = 'X';
            simbolis = 'O';
        } else if (simbolis == 'O' && pozicijos[eil][stulp] != 'X' && pozicijos[eil][stulp] != 'O') {
            pozicijos[eil][stulp] = 'O';
            simbolis = 'X';
        } else {
            cout << "Langelis jau uzipldytas, pasirinkite kita!" << endl;
            prieszaideja();
        }}


    void prieskompiuteri(){
      if (simbolis == 'X') {
            cout << "Iveskite i kuri langeli norite irasyti X." << endl;
            cin >> langelis;
      }
      else if (simbolis == 'O') {
            cout << "Kompiuterio eile, jis pasirenka ";
            do {
            langelis = rand() % 9 + 1;
        } while (pozicijos[(langelis - 1) / 3][(langelis - 1) % 3] == 'X' || pozicijos[(langelis - 1) / 3][(langelis - 1) % 3] == 'O');
        
        cout << langelis <<" langeli"<<endl;}
      switch (langelis) {
        case 1:
            eil = 0;
            stulp = 0;
            break;
        case 2:
            eil = 0;
            stulp = 1;
            break;
        case 3:
            eil = 0;
            stulp = 2;
            break;
        case 4:
            eil = 1;
            stulp = 0;
            break;
        case 5:
            eil = 1;
            stulp = 1;
            break;
        case 6:
            eil = 1;
            stulp = 2;
            break;
        case 7:
            eil = 2;
            stulp = 0;
            break;
        case 8:
            eil = 2;
            stulp = 1;
            break;
        case 9:
            eil = 2;
            stulp = 2;
            break;
        default:
            cout << "NETEISINGAS IVEDIMAS"<<endl;
            break;
        }
        if (simbolis == 'X' && pozicijos[eil][stulp] != 'X' && pozicijos[eil][stulp] != 'O') {
            pozicijos[eil][stulp] = 'X';
            simbolis = 'O';
        } else if (simbolis == 'O' && pozicijos[eil][stulp] != 'X' && pozicijos[eil][stulp] != 'O') {
            pozicijos[eil][stulp] = 'O';
            simbolis = 'X';
        } else {
            cout << "Langelis jau uzipldytas, pasirinkite kita!" << endl;
            prieskompiuteri();
        }

            
    }
};

int main() {
    grajus z;
    z.pradedam();
    z.skaiciai();
    z.zaidziam();
    return 0;
}
