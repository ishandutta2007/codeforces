#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	int A[20][20];
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0 || j == 0)
				A[i][j] = 1;
			else
				A[i][j] = A[i - 1][j] + A[i][j - 1];
			ans = max(ans, A[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}