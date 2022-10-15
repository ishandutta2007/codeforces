#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int t;
void yes() {
	cout << "Yes" << endl;
	if (t == 1)
		exit(0);
}

void no() {
	cout << "No" << endl;
	if (t == 1)
		exit(0);
}

void solve(int test_id) {
	int n;
	cin >> n;
	int maxl = 0, minr = 1000000000;
	for (size_t i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		maxl = max(maxl, l);
		minr = min(minr, r);
	}
	if (maxl <= minr)
		cout << 0 << endl;
	else
		cout << maxl - minr << endl;
}

int main() {
	t = 1;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		solve(i + 1);
	}
	return 0;
}