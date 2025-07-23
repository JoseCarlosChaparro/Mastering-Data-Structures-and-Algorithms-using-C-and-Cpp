#include <stdio.h>

int fun(int n){
    printf("%d\n",n);
    if(n>100)
        return n-10;
    else
        return fun(fun(n+11));
}

int main(){
    printf("%d",fun(98));
    return 0;
}