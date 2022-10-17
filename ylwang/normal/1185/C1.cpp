#include <bits/stdc++.h>

using namespace std;

const int T = 100;

int main() {
	int n, m;
	cin >> n >> m;
	
	int sum = 0;
	vector<int> t(n), count(T + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	
	for (int i = 0; i < n; i++) {
		int d = sum + t[i] - m, k = 0;
		if (d > 0) {
		    for (int j = T; j > 0; j--) {
				int x = j * count[j];
				if (d <= x) {
					k += (d + j - 1) / j;
					break;
				}
				k += count[j];
				d -= x;
			}
		}
		sum += t[i];
		count[t[i]]++;
		cout << k << " ";
	}
}