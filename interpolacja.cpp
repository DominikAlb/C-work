//Dominik Albiniak
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long double Arr[];

void Hermeite(Arr X, Arr Y, Arr T, int N, int M) {
    long double R[M][M];
    R[0][0] = Y[0];
    for (int i = 1; i < M; i++) {
        if (X[i] == X[i-1]) { 
            R[i][i] = R[i-1][i-1];
        } else {
            R[i][i] = Y[i];
        }
    }
    for (int i = 1; i < M; i++) {
        for (int j = 0; j < M - i; j++) {
            if (X[i + j] != X[j]) {
                R[j][j+i] = ( R[j+1][i+j] - R[j][i+j-1] ) / ( X[i+j] - X[j] );
                continue;
            }
            if (X[j-1] != X[j]) {
                R[j][i+j] = Y[j+i] / tgamma(i+1);
            } else {
                R[j][i+j] = R[j-1][i+j-1];
            }
        }
    }
    cout << fixed;
    cout.precision(17);
    for (int i = 0 ; i < M; i++) cout << R[0][i] << " ";
    cout << endl;
    for (int i = 0; i < N; i++) {
        long double answer = R[0][M-1];
        for (int j = M-2; j >= 0; j--) {
            answer *= (T[i] - X[j]);
            answer += R[0][j];
        }
        
        cout << answer << " ";
    }
}
int main()
{
    int M, N;
    cin >> M >> N;
    long double X[M];
    long double Y[M];
    long double T[N];
    for (int i = 0; i < M; i++)  cin >> X[i];
    for (int i = 0; i < M; i++)  cin >> Y[i];
    for (int i = 0; i < N; i++)  cin >> T[i];
    Hermeite(X, Y, T, N, M);
    return 0;
}