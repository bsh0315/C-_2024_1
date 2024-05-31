


#include<iostream>
using namespace std;

class Shape {
private:
	string name;
public:

	Shape(string name) { 
		this->name = name;
		cout << "shape 클래스 생성자 호출" << endl;
	}
	string getName() { return name; }
	virtual double getArea() = 0;
	virtual ~Shape() { cout << "Shape 클래스 소멸자 호출" << endl; }
	
    /*****************
     * ~Shape 소멸자에서 virtual을 쓴 경우의 소멸자 출력
     * 
    Oval 클래스 소멸자 호출
    Shape 클래스 소멸자 호출
    Rect 소멸자 호출
    Shape 클래스 소멸자 호출
    Triangular 클래스 소멸자 호출
    Shape 클래스 소멸자 호출
    ****************/

    /*****************
     * ~Shape 소멸자에서 virtual을 쓰지 않은 경우의 소멸자 출력
     * 
    Shape 클래스 소멸자 호출
    Shape 클래스 소멸자 호출
    Shape 클래스 소멸자 호출
    ****************/

};

class Oval : public Shape {
private:
	int x, y;
public:
	Oval(string arr, int x, int y) : Shape(arr) { 
		this->x = x; this->y = y; 
		cout << "Oval 클래스 생성자 호출" << endl;
	}
	virtual double getArea() { return 3.14 * x * y; }
	~Oval() { cout << "Oval 클래스 소멸자 호출" << endl; }
};

class Rect : public Shape {
private:
	int x, y;
public:
	Rect(string arr, int x, int y) : Shape(arr) { 
		this->x = x; this->y = y;
		cout << "Rect 클래스 생성자 호출" << endl;
	}
	virtual double getArea() { return  x * y; }
	~Rect() { cout << "Rect 소멸자 호출" << endl; }
};

class Triangular : public Shape {
private:
	int x, y;
public:
	Triangular(string arr, int x, int y) : Shape(arr) { 
		this->x = x; this->y = y; 
		cout << "Triangular 클래스 생성자 호출" << endl;
	}
	virtual double getArea() { return  (x * y) / 2.0; }
	~Triangular() { cout << "Triangular 클래스 소멸자 호출" << endl; }
};

int main() {
	Shape* p[3];
	p[0] = new Oval("빈대떡", 10, 20);
	p[1] = new Rect("찰떡", 30, 40);
	p[2] = new Triangular("토스트", 30, 40);
	for (int i = 0; i < 3; i++)
		cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;
	for (int i = 0; i < 3; i++) delete p[i];
}