//Dominik Albiniak

#include <stdio.h>
#include <cmath>
#include <algorithm>

int main() {
    int N;
    float max = -1;
    float NV = 0;   
    scanf("%i", &N);
    if (N > 0) {
        float P[N];
        float S[N];
        float aa[N];
        float bb[N];
        for (int i = 0; i < N; i++) {
            scanf("%e%e", &P[i], &S[i]);
            if (P[i] <= 0 || S[i] <= 0) {
                aa[i] = bb[i] = 0;
            } else {
                S[i] /= 2;
                float delta = std::pow(S[i], 2) - 4*P[i];
                if (delta > 0) {
                    float a, b ;
                    b = ((S[i] + std::sqrt(delta))/2);
                    a = P[i]/b; 
                    if (b < a) std::swap(a,b);
                    aa[i] = a;
                    bb[i] = b;
                    if (max < b) max = b;
                } else if (delta == 0) {
                    float a,b;
                    b = S[i]/2;
                    a = P[i]/b;
                    if (b < a) std::swap(a,b);
                    aa[i] = a;
                    bb[i] = b;
                    if (max < b) max = b;
                }    
                else {
                    aa[i] = bb[i] = 0;
                } 
            }
        }
        for(int i = 0; i < N; i++) {
           NV += std::pow(aa[i]/max, 2) + std::pow(bb[i]/max, 2);
           printf("%.10e %.10e\n", bb[i], aa[i]);
        }
        NV = std::sqrt(NV);
        NV *= max;
        printf("%.10e\n", NV);
    }
    return 0;
}