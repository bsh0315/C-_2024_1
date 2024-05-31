#include<iostream>
using namespace std;

class Circle {
private:
int radius; 
public:
Circle() { radius = 1; }
Circle(int radius) { this->radius = radius; }
void swap(Circle &A, Circle &B);
double getArea() { return 3.14*radius*radius; }
};

void Circle::swap(Circle &A, Circle &B){
    Circle temp = A;
    A = B;
    B = temp;
}

int main(){
    Circle A(10), B(20);

    cout << "A의 면적 =" << A.getArea() << "  B의 면적 = " << B.getArea() << endl;
    swap(A,B);
    cout << "A의 면적 =" << A.getArea() << "  B의 면적 = " << B.getArea() << endl;
}