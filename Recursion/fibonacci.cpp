#include <stdio.h>
#include <stdlib.h>

int fibo(int n);
int fiboIterative(int n);
int fiboOptimized(int n);

int F[10];

int main(){
    int n = 7;

    for(int i = 0; i < 10; i++){
        F[i] = -1;
    }

    printf("%d\n", fibo(10));
    printf("%d\n", fiboOptimized(10));
    printf("%d\n", fiboIterative(10));

    return 0;
}

int fibo(int n){
    if( n == 0 ){
        return 0;
    }else if( n == 1){
        return 1;
    }else{
        return fibo(n-2) + fibo(n-1);
    }
}

int fiboIterative(int n){
    int fibo = 0, prev = 0, current = 1;

    if(n == 0){
        return 0;
    }else if( n == 1){
        return 1;
    }
    
    for(int i=1; i < n; i++){
        fibo = prev + current;
        prev = current;
        current = fibo;
    }

    return fibo;
}



int fiboOptimized(int n){
    if( n <= 1){
        F[n] = n;
        return F[n];
    }else{
        if(F[n-2] == -1){
            F[n-2] = fibo(n-2);
        }
        if(F[n-1] == -1){
            F[n-1] = fibo(n-1);
        }
        F[n] = F[n-2] + F[n-1];
        return F[n];
    }
}