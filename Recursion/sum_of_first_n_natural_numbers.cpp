#include <stdio.h>

int sum(int n){
    if(n>0)
        return sum(n-1)+n;
    else
        return 0;
}

int Isum(int n){
    int s=0;
    int i;

    for(i=1; i<=n; i++){
        s=s+i;
    }

    return s;
}

int main(){
    int r;
    
    //r=sum(5);
    r=Isum(5);

    printf("%d", r);

    return 0;
}