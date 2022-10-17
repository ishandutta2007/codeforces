#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#define ll long long
#define dbl long double

using namespace std;

const long long MOD = 998244353;
const int N = 200000 + 5;
int t;

void solve(int testid) {
	int n, q;
	cin >> n >> q;
	int cnt = 0, c1 = 0;
	vector<vector<int> > grid(2, vector<int>(n));
	for (size_t i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		grid[x][y] ^= 1;
		if (grid[x][y]) {
			if (x == y && x == 0 || x == 1 && y == n - 1)
				c1++;
			else {
				cnt += grid[1 - x][y];
				if (y)
					cnt += grid[1 - x][y - 1];
				if (y + 1 < n)
					cnt += grid[1 - x][y + 1];
			}
		}
		else {
			if (x == y && x == 0 || x == 1 && y == n - 1)
				c1--;
			else {
				cnt -= grid[1 - x][y];
				if (y)
					cnt -= grid[1 - x][y - 1];
				if (y + 1 < n)
					cnt -= grid[1 - x][y + 1];
			}
		}
		if (cnt == 0 && c1 == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}

int main() {
	t = 1;
	// cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		solve(i + 1);
	}
	return 0;
}
/*

*/