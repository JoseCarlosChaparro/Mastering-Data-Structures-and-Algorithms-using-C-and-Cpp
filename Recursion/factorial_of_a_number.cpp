#include <stdio.h>

int factorial(int n){
    if(n>1)
        return factorial(n-1)*n;
    else
        return 1;
}

int Ifactorial(int n){
    int s=1;
    int i;

    for(i=1; i<=n; i++){
        s=s*i;
    }

    return s;
}

int main(){
    int r;
    
    //r=factorial(5);
    r=Ifactorial(5);

    printf("%d", r);

    return 0;
}