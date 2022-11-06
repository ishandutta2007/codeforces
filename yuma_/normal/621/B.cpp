#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;


int main() {
	int N; cin >> N;
	vector<int>a(2003);
	vector<int>b(2003);
	for (int i = 0; i < N; ++i) {
		int x, y; cin >> x >> y;
		a[x - y + 1000]++;
		b[x + y]++;
	}
	long long int sum = 0;
	for (int i = 0; i < 2003; ++i) {
		sum += a[i] * (a[i] - 1) / 2;
		sum += b[i] * (b[i] - 1) / 2;
	}
	cout << sum << endl;
	return 0;
}