#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		cout << 10 * (s[0] - '1') + s.size() * (s.size() + 1) / 2 << endl;
	}
}