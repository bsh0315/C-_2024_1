#include<iostream>
using namespace std;
class Circle {
    int radius; // 원의 반지름 값
    public:
    void setRadius(int radius); // 반지름을 설정한다.
    double getArea(); // 면적을 리턴한다.
};

void Circle::setRadius(int radius){
    this -> radius = radius;
}

double Circle::getArea(){
    return 3.14*radius*radius;
}

int main(){
    Circle arr[3];
    int count = 0;
    for(int i =0; i< sizeof(arr)/sizeof(Circle);++i){
        int num = 0;
        cin >> num;
        arr[i].setRadius(num);
        cout << "원 " <<i+1<< "의 반지름" << num << endl;

        if(arr[i].getArea() > 100){
            ++count;
        }
    }
    cout << "면적이 100보다 큰 원 " << count << "개입니다." << endl;
    return 0;
}