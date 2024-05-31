#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    vector<string> name;

    // Loop to get 5 strings from user
    for (int i = 0; i < 5; ++i) {
        string input;
        cout << i + 1 << ">> ";
        getline(cin, input);
        name.push_back(input);  // Store each input string in the vector
    }

    int max = 0;

    // Loop to find the lexicographically greatest string
    for (int i = 0; i < 5; ++i) {
        if (name[i] > name[max]) {
            max = i;
        }
    }

    // Output the lexicographically greatest string
    cout << "사전에서 가장 뒤에 나오는 문자열은 " << name[max] << ";"; // Added semicolon at the end

    return 0;
}
