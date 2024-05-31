#include<iostream>
using namespace std;

class Oval {
private:
	int width;
	int height;
public:
	~Oval();
	Oval();
	Oval(int w, int h);
	int getWidth();
	int getHeight();
	void set(int , int );
	void show();
};

Oval::Oval() {
	width = 0; 
	height = 0;
}

Oval::Oval(int w, int h) {
	width = w;
	height = h;
}

int Oval::getWidth() {
	return width;
}

int Oval::getHeight() {
	return height;
}

void Oval::show() {
	cout << width << height << endl;
}

void Oval::set(int w, int h) {
	width = w;
	height = h;
}

Oval::~Oval(){
	cout << "Oval 삭제, width : " << width << " height : " << height << endl;
}

int main() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl;
	return 0;

}