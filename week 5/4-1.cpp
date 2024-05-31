#include<iostream>
#include<string>
using namespace std;

int main(){
    string name[5];
    for(int i =0; i< 5; ++i){
        cout << "이름 >> ";
        getline(cin, name[i]);
    }

    int max = 0;

    for(int i = 0; i< 5; ++i){
        if(name[i] > name[max]){
            max = i;
        }
    }

    cout << "사전에서 가장 뒤에 나오는 문자열은 " << name[max];

    return 0;
}