#include <iostream>
#include <cmath>
using namespace std;

class Circle {
protected:
    int radius;
public:
    Circle(int r = 0) : radius(r) {}
    double getArea() const {
        return 3.14 * radius * radius;
    }
};

class NamedCircle : public Circle {
protected:
    string name;
public:
    void setRN(int r, string arr) {
        radius = r;
        name = arr;
    }
    void show() const;
    string getName() const {
        return this->name;
    }
};

void NamedCircle::show() const {
    cout << "반지름이 " << radius << "인 " << name << endl;
}

int main() {
    NamedCircle pizza[5];
    double maxArea = 0;
    string maxName;

    for (int i = 0; i < 5; ++i) {
        int r = 0;
        string arr;
        cout << i + 1 << " >> ";
        cin >> r >> arr;
        pizza[i].setRN(r, arr);
    }

    maxArea = pizza[0].getArea();
    maxName = pizza[0].getName();

    for (int i = 1; i < 5; ++i) {
        if (maxArea < pizza[i].getArea()) {
            maxArea = pizza[i].getArea();
            maxName = pizza[i].getName();
        }
    }

    cout << "가장 면적이 큰 피자는 " << maxName << "입니다." << endl;
    return 0;
}
