//Dominik Albiniak
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
class Tree {

    public:
        Tree() {
            cout << "Drzewo Posadzone" << endl;
            wzrost = 0;
            CoodBeCout = false;
        }
        ~Tree() {
            cout << "Drzewo wyciete" << endl;
        }
        void Podlej(int litry) {
            if (++wzrost >= 10) {
                CoodBeCout = true;
            }
        }
        string status() {
            string s = "drzewo ma:";
            char numstr[21];
            sprintf(numstr, "%d", wzrost);
            s += numstr;
            //s += wzrost;
            s += " m";
            return s;
        }
        bool czyDoWycinki() {
            return CoodBeCout;
        }


    private:

        int wzrost; // poziom drzewa
        bool CoodBeCout;

};
class Drwal {
    public:
        Drwal(Tree (&arr)[100]) : t(arr) {
            //*arr = &drzewa;
            cout << "Drwal Zatrudniony"
            << endl;
        }
        ~Drwal() {
            cout << "Drwal zwolniony"
            << endl;
        }
        int wycinka() {
        int count = 0;
        for (int i = 0; i < 100; i++) {
            if (t[i].czyDoWycinki() == true) {
                t[i] = Tree();
                count++;
            }
        }
        return count;
    }
    private:


        Tree (&t)[100];

};

class Lesnik {
    public:
        Lesnik(Tree (&arr)[100]) : t(arr) {
            cout << "Lesnik Zatrudniony" << endl;
            //*arr = *drzewa;
        }
        ~Lesnik() {
            cout << "lesnik zwolniony" << endl;
        }
        void Podlewanie(int litry) {
            int i = 0;
                while (litry) {
                    t[i%100].Podlej(1);
                    litry--;
                    i++;
                }
        }
    private:
        Tree (&t)[100];
};

class Lesnictwo {
    public:
        Lesnictwo(int kapital) {
            tart = new Tartak(kapital);
        }
        void wypiszStan() {
            tart->wypiszStan();
        }
        void Podlewanie(int l) {
            int zapas = tart->returnIleWody();
            if (zapas < l) {
                    cout << "Zbyt Malo Wody" << endl;
                return void();
            }
            tart->_lesnik->Podlewanie(l);
            zapas -= l;
            tart->AktualizujZapasWody(zapas);
        }
        void wycinka() {
            int masakra_drzew_pila_mechaniczna = tart->_drwal->wycinka();
            tart->ZapasDrewna += masakra_drzew_pila_mechaniczna;
        }
        void SprzedajDrewno() {
            tart->SprzedajDrewno();
        }
        void KupWode(int ile) {
            tart->KupWode(ile);
        }
        void WypiszKapital() {
            tart->WypiszKapital();
        }
        int IleDrewna() {
            return tart->ZapasDrewna;
        }
        void DotacjaZMinisterstwa(int kwota) {
            tart->DotacjaZMinisterstwa(kwota);
        }
    private:
        class Tartak {
            public:
                Drwal* _drwal;
                Lesnik* _lesnik;
                int ZapasDrewna;
                Tartak(int kapital){
                    _kapital = kapital;
                    _zapasWody = ZapasDrewna = 0;
                    _drwal = new Drwal(_tries);
                    _lesnik = new Lesnik(_tries);
                    //*_tries = &arr;
                }
                void wypiszStan() {
                    int c = 0;
                    while (c < 100) {
                        string s = _tries[c].status();
                        cout << s << endl;;
                        c++;
                    }
                    cout << "----" << endl;;
                }
                void WypiszKapital() {
                    cout << "Kapital: " << _kapital << endl;
                }
                void SprzedajDrewno() {
                    _kapital += ZapasDrewna;
                    ZapasDrewna = 0;
                }
                void KupWode(int ile) {
                    if (_kapital >= ile) {
                        _kapital -= ile;
                        _zapasWody += ile;
                    } else {
                        cout << "Brak Funduszy" << endl;
                    }
                }
                int returnIleWody() {
                    return _zapasWody;
                }
                void AktualizujZapasWody(int litry) {
                    _zapasWody = litry;
                }
                void DotacjaZMinisterstwa(int kwota) {
                    _kapital += kwota;
                }
            private:
                Tree _tries[100];
                int _kapital;
                int _zapasWody;

        };
        Tartak* tart;
};

