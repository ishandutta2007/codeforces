#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string code, num[10];
	cin >> code;
	for (int i=0; i<10; i++) cin >> num[i];
	for (int i=0; i<(int)code.length(); i+=10) {
		string tt="";
		for (int j=0; j<10; j++) tt+=code[i+j];
		for (int j=0; j<10; j++) {
			if (tt==num[j]) {
				cout << j;
				break;
			}
		}
	}
	cout << endl;
	return 0;
}