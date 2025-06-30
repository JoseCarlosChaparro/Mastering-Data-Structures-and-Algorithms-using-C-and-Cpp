
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Rectangle {

private:
    int length;
    int breadth;

public:
    Rectangle() {
        length = breadth = 1;
    }

    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    int area();

    int perimter() {
        return 2 * (length + breadth);
    }

    void setLength(int l) {
        length = l;
    }

    void setBreadth(int b) {
        breadth = b;
    }

    int getLength() {
        return length;
    }

    int getBreadth() {
        return breadth;
    }

    ~Rectangle() {
        cout << "Destructor";
    }
};

int Rectangle::area() {
    return length * breadth;
}

int main()
{
    Rectangle r(5, 4);
    int a = 0;

    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimter() << endl;


    return 0;
}