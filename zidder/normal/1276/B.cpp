#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>
#include <map>
 
#define ll long long
#define dbl long double
 
using namespace std;
int t;
 
 
const long long MOD = 998244353;
 
void cnt(int from, int to, vector<vector<int> >& g, vector<bool>& visited) {
	visited[from] = true;
	if (from == to)
		return;
	for (int nxt : g[from]) {
		if (visited[nxt])
			continue;
		cnt(nxt, to, g, visited);
	}
}
 
void solve(int tid) {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<vector<int> > g(n + 1);
	for (size_t i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<bool> visiteda(n + 1, false);
	cnt(a, b, g, visiteda);
	vector<bool> visitedb(n + 1, false);
	cnt(b, a, g, visitedb);
	long long cntb = n, cnta = n;
	for (size_t i = 1; i <= n; i++)
	{
		cntb -= visiteda[i];
		cnta -= visitedb[i];
	}
	cout << cnta * cntb << endl;
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