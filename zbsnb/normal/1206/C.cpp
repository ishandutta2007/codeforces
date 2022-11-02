#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	if (n % 2 == 1) {
		cout << "YES" << endl;
		cout << "1" << " ";
		for (int i = 1; i <= n / 2; i++) {
			cout << 4 * i << " " << 4 * i + 1 << " ";
		}
		cout << "2" << " ";
		for (int i = 1; i <= n / 2; i++) {
			cout << 4 * i - 1 << " " << 4 * i + 2 << " ";
		}
		cout << endl;
	}
	else {
		cout << "NO" << endl;
	}
}