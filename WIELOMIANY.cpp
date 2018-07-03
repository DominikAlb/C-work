#include <iostream>
using namespace std;
int nwd(int a,int b) {
        return b == 0 ? a : nwd(b, a % b);
}
int NWD(int A[], int n) {
        if (n == 1) {
            return A[0];
        } else {
            int B[n - 1];
            for (int i = 0; i < n - 1; i++) {
                B[i] = nwd(A[i], A[1+i]);
            }
            NWD(B, n - 1);
        }
}
class WIELOMIAN {
public:
    WIELOMIAN() {
        wielomian = new int[1];
        wielomian[0] = 0;
    }
    WIELOMIAN(int size) {
        this -> size = size + 1;
        wielomian = new int[this->size];

        for (int i = 0; i < this->size; i++) cin >> wielomian[i];

        int value = NWD(wielomian, this->size);

        for (int i = 0; i < this->size; i++) wielomian[i] /= value;
    }
    ~WIELOMIAN() {
        delete[] wielomian;
    }
    //metody:
    WIELOMIAN& operator= (WIELOMIAN wiel) {
        if (size > 0) delete[] wielomian;
        wielomian = new int[wiel.size];
        for (int i = 0; i < wiel.size; i++) {
            wielomian[i] = wiel.wielomian[i];
        }
        size = wiel.size;
        return *this;
    }
    WIELOMIAN& operator+=(WIELOMIAN wiel) {
        if (size > wiel.size) {
            for (int i = 0; i < wiel.size; i++) {
                wielomian[i] += wiel.wielomian[i];
            }
        } else if (wiel.size > size) {
            WIELOMIAN W;
            W = *this;
            delete[] wielomian;
            wielomian = new int[wiel.size];
            for (int i = 0; i < wiel.size; i++) {
                wielomian[i] = wiel.wielomian[i];
            }
            for (int i = 0; i < W.size; i++) {
                wielomian[i] += wiel.wielomian[i];
            }
        } else {
            for (int i = 0; i < size; i++) {
                wielomian[i] += wiel.wielomian[i];
            }
        }
        return *this;
    }
    WIELOMIAN& operator-=(WIELOMIAN wiel) {
        if (size > wiel.size) {
            for (int i = 0; i < wiel.size; i++) {
                wielomian[i] -= wiel.wielomian[i];
            }
        } else if (wiel.size > size) {
            WIELOMIAN W;
            W = *this;
            delete[] wielomian;
            wielomian = new int[wiel.size];
            for (int i = 0; i < wiel.size; i++) {
                wielomian[i] = wiel.wielomian[i];
            }
            for (int i = 0; i < W.size; i++) {
                wielomian[i] -= wiel.wielomian[i];
            }
        } else {
            for (int i = 0; i < size; i++) {
                wielomian[i] -= wiel.wielomian[i];
            }
        }
        return *this;
    }
    WIELOMIAN& operator-() {
        for (int i = 0; i < size; i++) {
                wielomian[i] = -wielomian[i];
        }
        return *this;
    }
    WIELOMIAN& operator*=(WIELOMIAN wiel) {
        WIELOMIAN W = *this;
        delete[] wielomian;
        wielomian = new int[W.size - 1 + wiel.size];
        for (int i = 0; i < W.size; i++) {
            wielomian[i] = W.wielomian[i];
        }
        WIELOMIAN M = *this;
        for (int i = 0; i < W.size; i++) {
            for (int j = 0; j < wiel.size; j++) {
                wielomian[i + j] += wiel.wielomian[j] * M.wielomian[i];
            }
        }
        return *this;
    }
    string operator/=(WIELOMIAN wiel) {
        WIELOMIAN Podziel;
        Podziel = *this;
        Podziel.size = size - wiel.size + 1;
        delete[] Podziel.wielomian;
        Podziel.wielomian = new int[Podziel.size];
        for (int i = 0; i < Podziel.size; i++) {
            Podziel.wielomian[i] = 0;
        }
        int siz = size;
        int n = Podziel.size;
        Podziel.wielomian[n - 1] = wielomian[siz - 1] /  wiel.wielomian[wiel.size - 1];
        for (int i = wiel.size - 1, j = size - 1; i >= 0; i--) {
            wielomian[j--] -= Podziel.wielomian[n - 1] * wiel.wielomian[i];
        }
        while(wielomian[size - 1] == 0) size--;
        WIELOMIAN RESZTA = *this;
        n--;
        while (RESZTA.size == 0 && RESZTA.size < wiel.size && n > 0) {
            Podziel.wielomian[n - 1] = RESZTA.wielomian[RESZTA.size - 1] / wiel.wielomian[wiel.size - 1];
            for (int i = wiel.size - 1, j = RESZTA.size - 1; i >= 0; i--) {
            RESZTA.wielomian[j--] -= Podziel.wielomian[n - 1] * wiel.wielomian[i];
            }
            while(RESZTA.wielomian[size - 1] == 0) RESZTA.size--;
            n--;
        }
        cout << "( ";
        for (int i = 0; i < Podziel.size - 1; i++) {
            cout << Podziel.wielomian[i] << ", ";
        }
        cout << Podziel.wielomian[Podziel.size - 1] << " )";
    }
    string operator%=(WIELOMIAN wiel) {
        WIELOMIAN Podziel;
        Podziel = *this;
        Podziel.size = size - wiel.size + 1;
        delete[] Podziel.wielomian;
        Podziel.wielomian = new int[Podziel.size];
        for (int i = 0; i < Podziel.size; i++) {
            Podziel.wielomian[i] = 0;
        }
        int siz = size;
        int n = Podziel.size;
        Podziel.wielomian[n - 1] = wielomian[siz - 1] /  wiel.wielomian[wiel.size - 1];
        for (int i = wiel.size - 1, j = size - 1; i >= 0; i--) {
            wielomian[j--] -= Podziel.wielomian[n - 1] * wiel.wielomian[i];
        }
        while(wielomian[size - 1] == 0) size--;
        WIELOMIAN RESZTA = *this;
        n--;
        while (RESZTA.size == 0 && RESZTA.size < wiel.size && n > 0) {
            Podziel.wielomian[n - 1] = RESZTA.wielomian[RESZTA.size - 1] / wiel.wielomian[wiel.size - 1];
            for (int i = wiel.size - 1, j = RESZTA.size - 1; i >= 0; i--) {
            RESZTA.wielomian[j--] -= Podziel.wielomian[n - 1] * wiel.wielomian[i];
            }
            while(RESZTA.wielomian[size - 1] == 0) RESZTA.size--;
            n--;
        }
        cout << "( ";
        for (int i = 0; i < RESZTA.size - 1; i++) {
            cout << RESZTA.wielomian[i] << ", ";
        }
        cout << RESZTA.wielomian[RESZTA.size - 1] << " )";
    }
    WIELOMIAN& operator>>=(int ile) {
        for (int i = 0; i < ile; i ++) {
            for (int j = 0; j < size - 1; j++) {
                wielomian[j] = wielomian[j + 1];
            }
        }
        size -= ile;
    }
    WIELOMIAN& operator<<=(int ile) {
        WIELOMIAN W = *this;
        delete[] wielomian;
        wielomian = new int[size + ile];
        for (int i = 0; i < size + ile; i++) {
            wielomian[i] = 0;
        }
        for (int i = 0; i < size ; i++) {
            wielomian[i + ile] = W.wielomian[i];
        }
        return *this;
    }
    WIELOMIAN& operator<<(int ile) {
        WIELOMIAN W = *this;
        delete[] W.wielomian;
        W.wielomian = new int[size + ile];
        for (int i = 0; i < size + ile; i++) {
            W.wielomian[i] = 0;
        }
        for (int i = 0; i < size ; i++) {
            W.wielomian[i + ile] = wielomian[i];
        }
        return W;
    }
    WIELOMIAN& operator>>(int ile) {
        WIELOMIAN W = *this;
        for (int i = 0; i < ile; i ++) {
            for (int j = 0; j < size - 1; j++) {
                W.wielomian[j] = W.wielomian[j + 1];
            }
        }
        W.size -= ile;
        return W;
    }
    WIELOMIAN& operator+(WIELOMIAN wiel) {
        WIELOMIAN W;
        if (size >= wiel.size) {
            W = *this;
            for (int i = 0;i < wiel.size; i++) {
                W.wielomian[i] += wiel.wielomian[i];
            }
        } else {
            W = wiel;
            for (int i = 0;i < size; i++) {
                W.wielomian[i] += wielomian[i];
            }
        }
        return W;
    }
    WIELOMIAN& operator-(WIELOMIAN wiel) {
        WIELOMIAN W;
        if (size >= wiel.size) {
            W = *this;
            for (int i = 0;i < wiel.size; i++) {
                W.wielomian[i] -= wiel.wielomian[i];
            }
        } else {
            W = wiel;
            for (int i = 0;i < size; i++) {
                W.wielomian[i] -= wielomian[i];
            }
        }
        return W;
    }
    WIELOMIAN& operator*(WIELOMIAN wiel) {
        WIELOMIAN W = *this;
        delete[] W.wielomian;
        W.size = size + wiel.size;
        for (int i = 0; i < size; i++) {
            W.wielomian[i] = wielomian[i];
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < wiel.size; j++) {
                W.wielomian[i + j] += wiel.wielomian[j] * M.wielomian[i];
            }
        }
        return W;
    }
    int size;
    int* wielomian;
};
    ostream& operator<<(ostream& os, WIELOMIAN wiel) {
        int* wielomian = wiel.wielomian;
        os << "( ";
        for (int i = 0; i < wiel.size - 1; i++) {
            os << wielomian[i] << ", ";
        }
        os << wielomian[wiel.size - 1] << " )";
    }
    istream& operator>>(istream& is, WIELOMIAN wiel) {
        int size;
        is >> size;
        wiel.size = size + 1;
        wiel.wielomian = new int[wiel.size];
        for (int i = 0; i < wiel.size; i++) is >> wiel.wielomian[i];

        int value = NWD(wiel.wielomian, wiel.size);

        for (int i = 0; i < wiel.size; i++) wiel.wielomian[i] /= value;
        return is;
    }
int main() {
    /*WIELOMIAN x(5);
    cout << x << endl;
    WIELOMIAN y(3);
    cout << y << endl;
    WIELOMIAN R;
    R = ( x + y );
    cout << R << endl;
    WIELOMIAN z(3);
    cout << z << endl;
    R = ( R - (-z) );
    cout << R << endl;*/
    /*WIELOMIAN a(3);
    cout << a << endl;
    WIELOMIAN b(2);
    cout << b << endl;
    //cout << (a * b) << endl;
    b = ++a;
    cout << a << endl;
    cout << b << endl;
    a = b--;
    cout << a << endl;
    cout << b << endl;*/
    cout << WIELOMIAN::przeladowanie << endl;
    WIELOMIAN* wPtr = new WIELOMIAN;
    cout << wPtr->przeladowanie << endl;
    delete wPtr;
    cout << WIELOMIAN::przeladowanie << endl;
}
