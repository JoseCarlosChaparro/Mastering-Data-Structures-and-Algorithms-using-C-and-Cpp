#include <stdio.h>

double factorial(int n){
    if(n>1)
        return factorial(n-1)*n;
    else
        return 1;
}

double Ifactorial(int n){
    int s=1;
    int i;

    for(i=1; i<=n; i++){
        s=s*i;
    }

    return s;
}

double c(int n, int r){
    double c;
    c = factorial(n) / (factorial(r) * factorial(n-r));
    return c;
}

int C[10][10];

int cRecursive(int n, int r){
    if(n == r || r==0 )
        return 1;
    else
        return cRecursive(n-1, r-1) + cRecursive(n-1,r);
}

int cRecursiveMemoization(int n, int r){
    if(r == 0 || n == r)
        return C[n][r] = 1;

    if(C[n - 1][r - 1] == -1)
        C[n - 1][r - 1] = cRecursiveMemoization(n - 1, r - 1);

    if(C[n - 1][r] == -1)
        C[n - 1][r] = cRecursiveMemoization(n - 1, r);

    return C[n][r] = C[n - 1][r - 1] + C[n - 1][r];
}


int main(){
    int r;

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            C[i][j] = -1;
        }
    }

    printf("%d\n", cRecursive(6,4));
    printf("%d\n", cRecursiveMemoization(6,4));
    
    return 0;
}