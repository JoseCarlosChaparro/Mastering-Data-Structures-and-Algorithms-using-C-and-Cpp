#include <stdio.h>
#include <time.h>

double factorial(int n){
    if(n > 1)
        return factorial(n - 1) * n;
    else
        return 1;
}

double Ifactorial(int n){
    int s = 1;
    for(int i = 1; i <= n; i++){
        s *= i;
    }
    return s;
}

double c(int n, int r){
    double num, den;

    num = factorial(n);
    den = factorial(r)* factorial(n-r);
    return num/den;
}

int C[50][50];

int cRecursive(int n, int r){
    if(n == r || r == 0)
        return 1;
    return cRecursive(n - 1, r - 1) + cRecursive(n - 1, r);
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

void resetMemoTable(){
    for(int i = 0; i < 50; i++)
        for(int j = 0; j < 50; j++)
            C[i][j] = -1;
}

int main(){
    //TENER EN CUENTA EL OVERFLOW DE LAS FUNCIONES QUE RETORNAN INT
    int n = 35, r = 17;
    clock_t start, end;
    double ms;

    // Tiempo c factorial
    start = clock();
    double res = c(n, r);
    end = clock();
    ms = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("c(%d,%d) = %lf, Time = %.3f ms\n", n, r, res, ms);

    // Tiempo cRecursive
    start = clock();
    int res1 = cRecursive(n, r);
    end = clock();
    ms = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("cRecursive(%d,%d) = %d, Time = %.3f ms\n", n, r, res1, ms);

    // Tiempo cRecursiveMemoization
    resetMemoTable();
    start = clock();
    int res2 = cRecursiveMemoization(n, r);
    end = clock();
    ms = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("cRecursiveMemoization(%d,%d) = %d, Time = %.3f ms\n", n, r, res2, ms);

    return 0;
}
