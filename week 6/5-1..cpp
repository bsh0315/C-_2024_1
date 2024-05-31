#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
    public:

    Rectangle(int w =1, int h =1 );
    Rectangle(int size);
    bool isSquare();
};

// 생성자 구현 추가
Rectangle::Rectangle(int w , int h ) {
    width = w; height = h;
}
Rectangle::Rectangle(int size) {
    width = height = size;
}

bool Rectangle::isSquare() {
    if(width == height) return true;
    else return false;
}

int main() {
Rectangle rect1; 
Rectangle rect2(3, 5);
Rectangle rect3(3,3);
if(rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
if(rect2.isSquare()) cout << "rect2는 정사각형이다." << endl;
if(rect3.isSquare()) cout << "rect3는 정사각형이다." << endl;
}