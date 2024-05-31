#include<iostream>
using namespace std;

class Book {
char *title; // 제목 문자열
int price; // 가격
public:
Book(char* title, int price);
~Book();
void set(char* title, int price);
void show() { cout << title << ' ' << price << "원" << endl; }
};
Book::Book(char* title, int price){
    
}
Book::~Book(){
    if(title != NULL){
        delete [] title;
    }
}
void Book::set(char* title, int price){

}

int main() {
Book cpp("명품C++", 10000);
Book java = cpp;
java.set("명품자바", 12000);
cpp.show();
java.show();
}