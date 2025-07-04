// C and C++ Concepts
// Template class
#include <iostream>

using namespace std;

template <class T>
class Arithmetic{
    private: 
        T a;
        T b;
    public:
        Arithmetic(T a, T b);
        T add();
        T sub();
        T getA();
        T getB();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b){
    (*this).a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add(){
    T c;
    c = a+b;
    return c;
}

template <class T>
T Arithmetic<T>::sub(){
    T c;
    c=a-b;
    return c;
}

template <class T>
T Arithmetic<T>::getA(){
    return this->a;
}

template <class T>
T Arithmetic<T>::getB(){
    return this->b;
}

int main(){

    Arithmetic<int> ar(10,5);
    cout<<ar.add()<<endl;
    cout<<ar.sub()<<endl;

    Arithmetic<float> ar1(1.5,1.2);
    cout<<ar1.add()<<endl;
    cout<<ar1.sub()<<endl;

    Arithmetic<char> ar2('A','B');
    cout<<ar2.add()<<endl;
    cout<<ar2.sub()<<endl;

    cout<<sizeof(int)<<endl;
    cout<<sizeof(double)<<endl;


    return 0;
}