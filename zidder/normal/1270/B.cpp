#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>
#include <unordered_set>
#include <map>

#define ll long long
#define dbl long double

using namespace std;

const long long MOD = 998244353;
const int N = 200000 + 5;
int t;

void solve(int testid) {
	int n;
	cin >> n;
	int prev = -1;
	bool ok = false;
	for (size_t i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if (prev == -1) {
			prev = x;
			continue;
		}
		if (ok)
			continue;
		if (abs(prev - x) > 1) {
			ok = true;
			cout << "Yes" << endl;
			cout << i << " " << i + 1 << endl;
		}
		prev = x;
	}
	if (!ok) {
		cout << "No" << endl;
	}
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
/*

*/