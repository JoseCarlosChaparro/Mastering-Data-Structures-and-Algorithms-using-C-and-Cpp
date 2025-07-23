#include <stdio.h> 

int optimizedExponent(int m, int n){
    if(n==0)
        return 1;
    if(n%2 == 0)
        return optimizedExponent(m*m, n/2);
    else
        return m*optimizedExponent(m*m, (n-1)/2);
}

int Ifactorial(int n){
    int s=1;
    int i;

    for(i=1; i<=n; i++){
        s=s*i;
    }

    return s;
}

int Isum(int n){
    int s=0;
    int i;

    for(i=1; i<=n; i++){
        s=s+i;
    }

    return s;
}

double taylor(int x, int n){
    if(n==0)
        return 1;
    else
        return taylor(x,n-1) + (optimizedExponent(x,n)/Ifactorial(n));
}

double e(int x, int n){
    static double p=1, f=1;
    double r;

    if( n == 0){
        return 1;
    }else{
        r = e(x, n-1);
        p = p * x;
        f = f * n;
        return r + p/f;
    }
}

int main(){
    // int r;

    // r=optimizedExponent(5,2);

    // printf("%d", r);

    // int r2;
    
    // r=Ifactorial(5);

    // printf("%d", r);

    int x=1, n=10;
    double r1, r2;


    r1 = taylor(x,n);
    r2 = e(x,n);

    printf("taylor: %lf\n", r1);
    printf("e: %lf ", r2);

    return 0;
}