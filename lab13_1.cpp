#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[] , int N , double B[]){
    double a1=0.0, std = 0.0, gm=1.0 , hm = 0.0 , mean=0.0;
    B[4]=A[0];
    B[5]=A[0];
    int i;
    for(i=0 ; i<N ; i++){
        if(A[i]>B[4]) B[4]=A[i];
        if(A[i]<B[5]) B[5]=A[i];
        a1 +=A[i];
    }
    B[0] = a1/N;
    mean = a1/N;

    for(i=0;i<N;i++){
        std += pow(A[i]-mean,2);
    }
     B[1]=sqrt(std/N);

    for(i=0;i<N;i++){
        gm *= A[i];
    }

    if(gm<0) gm= -gm;
    B[2] = pow(gm,(float)1/N);
    
    for(i=0 ;i<N;i++){
        hm += 1/A[i];
    }
    B[3] = N/hm;

}
