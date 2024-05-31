#include <iostream>
using namespace std;

class Math{
public:
    int b = 20;
    static int a;
    static int abs(int a) { return a>0?a:-a; }
    static int max(int a, int b) { return (a>b)?a:b; }
    static int min(int a, int b) { return (a>b)?b:a; }

};

 int Math::a = 10;

int main() {
cout << Math::abs(-5) << endl;
cout << Math::max(10, 8) << endl;
cout << Math::min(-3, -8) << endl;
}