//Dominik Albiniak
#include <iostream>
using namespace std;
void defaultA(int N, long double A[], int M) {
    for (int i = 0;i < N*M; i++) A[i] = 0;
} 
void setA(int N, long double A[], int M) {
    for (int i = M/2,k = 0; i >= 0; i--, k++) {
        for (int j = 0; j < N - i; j++) {
            cin >> A[k*N+j];
        }
    }
    for (int i = M/2+1, k = 1; i < M; i++, k++) { //TODO
        for (int j = 0; j < N - k; j++) {
            cin >> A[i*N+j];
        }
    }
}
void setX(long double *X, int N) {
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
}
void setY(long double *Y, int N) {
    for (int i = 0; i < N; i++) {
        cin >> Y[i];
    }
}
void Test(long double A[], int N, int M) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) { 
            cout << A[i*N+j] << " ";
        }
        cout << endl;
    }
}
void OmDPlusU(int N, long double A[], long double *x, double omega, long double *sum, int M, long double y[]) {
    for (int i = 0; i < N; i++) sum[i] = y[i];
    //(1 - omega) * A[N*M/2+i] * x[i];
    for (int i = 0; i < N; i++) {
        for (int j = M/2-1; j >= 0 && (M/2)-j+i < N; j--) {
            //cout << "A[" << j*N+i << "] * x[" << (M/2)-j + i << "] = " << A[j*N+i] << " * " <<  x[M/2 - j + i] << endl;
            sum[i] -= A[j*N+i] * x[(M/2) - j + i];
        }
    }
    sum[0] = (sum[0] * omega) / A[N*(M/2)];
    x[0] = (1 - omega)*x[0] + sum[0];
    //cout << endl;
}
void DPlusOmL(int N, long double A[], double omega, long double *x, long double *sum, int M) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = (M/2)+1, k = 1+i; j < M && k < N; j++, k++) {
            //cout << "A[" << j*N+i << "] * x[" << i << "] = " << A[j*N+i] << " * " <<   x[i] << endl;
            sum[k] -= A[j*N+i] * x[i];
        }
        sum[i+1] = (sum[i+1] * omega) / A[N*(M/2)+i+1];
        x[i+1] = (1-omega)*x[i+1] + sum[i+1];
    }
    //cout << endl;

}
void showAnswer(long double *x, int N) {
    cout.precision(16);
    cout << scientific;
    for (int i = 0; i < N; i++) { 
        cout << x[i] << " ";
    }
    //cout << "showAnswer  X: " << x << endl;
}
void SOR(int N, long double A[], int M, long double *x, long double *y, double omega, int L) {
    long double sum[N];
    //cout << "SOR sum: " << sum << " X: " << x << " Y: " << y << endl;
    for (int l = 0; l < L; l++) {
        OmDPlusU(N, A, x, omega, sum, M, y);
        DPlusOmL(N, A, omega, x, sum, M);
    }
    showAnswer(x, N);
    
}

int main() {

    int N, M, L;
    double omega;
    cin >> N;
    cin >> M;
    long double X[N];
    long double Y[N];
    long double A[N*M];
    defaultA(N, A, M);
    setA(N, A, M);
    
    setY(Y, N);
    setX(X, N);
    cin >> omega;
    cin >> L;
    //cout << "Main  X: " << X << " Y: " << Y << endl;
    //Test(A, N, M);
    SOR(N, A, M, X, Y, omega, L);
    //
    
    return 0;
}