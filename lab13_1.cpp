#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[]) {
    B[0] = 0; B[1] = 0, B[2] = 1, B[3] = 0;
    double min = A[0], max = A[0];
    for (int i = 0; i < N; ++i) {
        B[0] += A[i];
        B[1] += (A[i]*A[i]) / N;
        B[2] *= A[i];
        B[3] += 1/A[i];
        if (A[i] > max) max = A[i];
        if (A[i] < min) min = A[i];
    }
    B[0] /= N;
    B[1] = sqrt(B[1] - pow(B[0],2));
    B[2] = pow(B[2], 1.0/N);
    B[3] = N / B[3];
    B[4] = max;
    B[5] = min;
}