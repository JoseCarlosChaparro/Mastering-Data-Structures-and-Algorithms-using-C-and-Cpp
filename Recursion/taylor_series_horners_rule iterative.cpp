#include <stdio.h>

double e(int, int);

int main(){
    int x = 1, n = 20;
    double s = e(x,n);


    printf("%lf \n", s);
}

double e(int x, int n){
    double s = 1;

    for(int i = n; i>0; i--){
        s = 1 + x*s/i;
    }

    //TAMBIEN SE PUEDE ASI
    // double num = 1, den=1;
    // for(int i = 1; i<=n; i++){
    //     num *= x;
    //     den *= i;
    //     s += num/den;
    // }

    return s;

}