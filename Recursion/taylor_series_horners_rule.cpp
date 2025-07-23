#include <stdio.h>

double e(int, int);

int main(){
    int x = 2, n = 20;
    double s = e(x,n);


    printf("%lf \n", s);
}

double e(int x, int n){
    static double s = 1;

    if(n == 0 ){
        return s;
    }

    s = 1 + (x*s/n);

    return e(x, n-1);

}