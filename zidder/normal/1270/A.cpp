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
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	bool ok = false;
	for (size_t i = 0; i < k1; i++)
	{
		int x;
		cin >> x;
		ok |= x == n;
	}
	for (size_t i = 0; i < k2; i++)
	{
		int x;
		cin >> x;
	}
	if (ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
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