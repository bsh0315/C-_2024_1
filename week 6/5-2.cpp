#include<iostream>
using namespace std;

class Oval{
    int width;
    int height;
public:
    
    Oval();
    Oval(int w, int h);
    ~Oval();
    int getWidth();
    int getHeight();
    void set(int w, int h);
    void show();
};

Oval::Oval(){
    width = 1;
    height = 1;
}
Oval::Oval(int w, int h){
    width = w;
    height = h;
}

int Oval::getWidth(){
    return width;
}

int Oval::getHeight(){
    return height;
}

void Oval::set(int w, int h){
    width = w;
    height = h;
}
void Oval::show(){
    cout << "width = " << width << ", height = " << height << endl;
}

Oval::~Oval() {
    cout << "Oval 소멸 : " << width << " " << height << endl;
}
int main(){
    Oval a, b(3, 4);
    a.set(10, 20);
    a.show();
    cout << b.getWidth() << ", " << b.getHeight() << endl;


    return 0;
}