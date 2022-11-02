#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

const int MAX_N = 1000 + 10;

int n, t[MAX_N], c[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t[i] >> c[i];
	}

	int tot = 0;
	int mxSize = 0, last = 0;

	int prev = 0;

	for (int i = 0; i < n; ++i) {
		int cur = t[i];
		int pass = cur - prev;
		prev = cur;

		tot = max(0, tot - pass);

		tot += c[i];
		mxSize = max(mxSize, tot);
	}

	last = t[n - 1] + tot;

	cout << last << " " << mxSize << endl;
}