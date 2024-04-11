#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, p;
		cin >> n >> p;
		//build two cycle
		bool e[40][40] = { };
		for (int i = 0; i < n; ++i) {
			int a = i, b = (i + 1) % n;
			cout << a + 1 << " " << b + 1 << endl;
			e[a][b] = e[b][a] = true;
		}
		for (int i = 0; i < n; ++i) {
			int a = i, b = (i + 2) % n;
			cout << a + 1 << " " << b + 1 << endl;
			e[a][b] = e[b][a] = true;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (p == 0)
					continue;
				if (e[i][j])
					continue;
				cout << i + 1 << " " << j + 1 << endl;
				--p;
			}
		}
	}
}