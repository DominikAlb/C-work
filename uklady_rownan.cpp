//Dominik Albiniak
#include <iostream>
#include <cmath>
//#include <limits>
double wyznaczMiejsceZerowe(double (*f)(double), double a, double b,
                            int M, double eps, double delta)    {

    double c = 0;
    //double prev = std::numeric_limits<double>::max();
    double fa = f(a);
    double fb = f(b);
    int j = 2;
    //std::cout << fa << " " << fb << std::endl;
    if (std::abs(fa) < std::abs(fb)) {
        std::swap(a,b);
        std::swap(fa, fb);
    }
    if(fa == 0) return a;
    if(fb == 0) return b;
    double prevB = 200;
    while (true) {     
        c = (b + a)/2;
        double fc = f(c); j++;
        //std::cout << "bisekcja: " << c << std::endl;
        if (std::abs(fc)<= eps || std::abs(b - a)/4 <= delta) { 
            //std::cout << "bijekcja: " << j << " ";
            return c;
        }
        if (fa*fc < 0) {
            b = c;
            fb = fc;
        }
        else {
            a = c;
            fa = fc;
        }
        //std::cout << prevB << " " << c << " " << std::abs(prevB - c) << std::endl;
        if (std::abs(fc) <= 1e-1 || std::abs(prevB - c) <= 25e-2) break;
        prevB = c;
    }
    if (std::abs(fa) < std::abs(fb)) {
        std::swap(a,b);
        std::swap(fa, fb);
    }
    while (true) {
        c = b - fb*((b - a)/(fb - fa));
        double fc = f(c); j++;
        //std::cout << fa << " " << fb << " " << fc <<  std::endl;
        if (std::abs(fc)<= eps || std::abs(b - a)/4 <= delta) { 
            //std::cout << "sieczna: " << j << " ";
            return c;
        }
        a = b;
        fa = fb;
        b = c;
        fb = fc;
    }
    return c;
}
/*
using namespace std;

double wielomian(double x){ 	return (((x-6)*x+11)*x)-6;	}
double wielomianSinExp(double x)
{	return ((((x-6)*x+11)*x)-4 + sin(15*x))*exp(-x*x);	}
double kwadrat(double x){	return (x*x-2);	 }
double kwadrat100(double x){  return 1e100*(x*x-2);	}
double kwadrat_10(double x){ 	return 1e-10*(x*x-2);	}

int main(){
	cout.precision(16);                                               // Spodziewany wynik 
	cout << wyznaczMiejsceZerowe(wielomian, 0, 4, 20, 1e-15, 1e-14) << endl;      // 1 lub 2 lub 3
	cout << wyznaczMiejsceZerowe(wielomian, 0, 40, 20, 1e-15, 1e-14) << endl;     // 1 lub 2 lub 3
	cout << wyznaczMiejsceZerowe(wielomian, 1, 2, 2, 1e-15, 1e-14) << endl;       // 1 lub 2   
	cout << wyznaczMiejsceZerowe(wielomian, -150, 1.9, 20, 1e-15, 1e-14) << endl; // 1
	cout << wyznaczMiejsceZerowe(wielomian, 1.5, 2.99, 20, 1e-15, 1e-14) << endl; // 2
	cout << wyznaczMiejsceZerowe(wielomian, 2.01, 40, 20, 1e-15, 1e-14) << endl;  // 3
	cout << wyznaczMiejsceZerowe(wielomian, 1.5, 6, 20, 1e-15, 1e-14) << endl;    // 1 lub 2 lub 3

	cout << wyznaczMiejsceZerowe(wielomianSinExp, -1, 3, 60, 1e-60, 1e-14) << endl;  // 0.43636925909804245
	cout << wyznaczMiejsceZerowe(wielomianSinExp, -3, 3, 60, 1e-160, 1e-14) << endl; // 0.43636925909804245
	
	cout << wyznaczMiejsceZerowe(kwadrat, 0, 4, 15, 1e-11, 1e-14) << endl;          // 1.414213562373095
	cout << wyznaczMiejsceZerowe(kwadrat100, 0, 4, 15, 1e-11, 1e-14) << endl;       // 1.414213562373095
	cout << wyznaczMiejsceZerowe(kwadrat_10, 0, 4, 10, 1e-10, 1e-14) << endl;       // każdy punkt z przedziału [1, 1.73205]
 	cout << wyznaczMiejsceZerowe(kwadrat_10, 0, 4, 15, 1e-160, 1e-14) << endl;      // 1.414213562373095
 	return 0;
}*/