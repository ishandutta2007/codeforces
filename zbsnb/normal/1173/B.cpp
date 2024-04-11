
#include<iostream>
using namespace std;

int main() {
	int n; cin >> n;
	cout << n / 2 + 1 << endl;
	cout << "1 1" << endl;
	for (int i = 2; i <= n; i++) {
		cout << (i - 1) / 2 + 1 << " " << i / 2 + 1 << endl;
	}
}