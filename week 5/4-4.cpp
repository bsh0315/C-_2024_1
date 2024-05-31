#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    string find_s;
    string replace_s;

    cout << "여러줄의 문자열을 입력하세요 : ";
    getline(cin, s, '&');
    cin.ignore();

    cout << "찾을 거" << endl;

    getline(cin, find_s);

    cout << "바꿀 내용" << endl;
    getline(cin, replace_s);
   
    size_t pos = 0; //size_t는 usigned long 과 동일함. int 써도 됨.
    while (1) {
        pos = s.find(find_s, pos);
        if (pos == string::npos) { //string::npos는 -1을 의미함.
            break;
        }
        s.replace(pos, find_s.length(), replace_s);
        pos += replace_s.length();
    }

    cout << "변환된 문자열: " << s << endl;

    return 0;
}