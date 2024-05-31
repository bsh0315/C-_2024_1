#include<iostream>
using namespace std;
class Book{
    const char* ptr;
    int price;
    int page;
public:
    Book(const char* arr, int price , int page);
};

Book::Book(const char* arr, int price , int page){
    this->ptr = arr;
    this->price = page;
    this->page = page;
}

int main(){
    Book a("청춘", 20000, 300), b("미래", 30000, 500);
    a += 500; // 책 a의 가격 500원 증가
    b -= 500; // 책 b의 가격 500원 감소
    a.show();
    b.show();
    return 0;
}