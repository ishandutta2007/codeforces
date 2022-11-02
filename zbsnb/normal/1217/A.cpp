#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int t; cin >> t;
	while(t--) {
		int a, b, c; cin >> a >> b >> c;
		a += c;
		int tmp = a - (a + b) / 2;
		if (tmp < 0)tmp = 0;
		cout << min(c + 1, tmp) << endl;
	}
}