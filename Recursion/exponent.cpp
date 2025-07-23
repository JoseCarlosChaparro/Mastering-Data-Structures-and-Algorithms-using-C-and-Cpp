#include <stdio.h> 

int exponent(int m, int n){
    if(n>0)
        return exponent(m, n-1)*m;
    else
        return 1;
}

int Iexponent(int m, int n){
    int s=1;
    int i;

    for(i=1; i<=n; i++){
        s=s*m;
    }

    return s;
}

int optimizedExponent(int m, int n){
    if(n==0)
        return 1;
    if(n%2 == 0)
        return optimizedExponent(m*m, n/2);
    else
        return m*optimizedExponent(m*m, (n-1)/2);
}

int main(){
    int r;
    
    //r=exponent(5,2);
    //r=Iexponent(5,2);
    r=optimizedExponent(5,2);

    printf("%d", r);

    return 0;
}