#include<iostream>
using namespace std;

class Circle{
protected:
    int radius;

public:
    Circle(int r = 0) {
        radius = r;
    }
};

class NamedCircle : public Circle{
protected:
    string name;
public:
    NamedCircle(int r, string arr) : Circle(r){
        this->name = arr;
    }
    void show(){
        cout << "반지름이 " << this->radius << "인" << name;
    }
};


int main(){
    NamedCircle waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 원
    waffle.show();
}