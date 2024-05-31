#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	vector<string> arr;
	string max;

	cout << "이름을 5개 입력하라" << endl;

	for (int i = 0; i < 5; ++i) {
		string input;
		cout << i+1 << ">> ";
		getline(cin, input, '\n');
		arr.push_back(input);
	}

	max = arr[0];

	for (int i = 1; i < 5; ++i) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	cout << "사전에서 가장 뒤에 나오는 이름은 " << max << endl;

	return 0;
}