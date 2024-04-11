#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
int n;
vector<long long> w;
vector<vector<pair<int, long long>>> e;
vector<bool> visited;

pair<long long, long long> dfs(int v) {
	visited[v] = true;
	long long mx1 = 0, mx2 = 0, mx = 0;
	for (size_t i = 0; i < e[v].size(); i++)
	{
		if (visited[e[v][i].first])
			continue;
		pair<long long, long long> z = dfs(e[v][i].first);
		if (z.second > mx)
			mx = z.second;
		z.first -= e[v][i].second;
		if (z.first >= mx1) {
			mx2 = mx1;
			mx1 = z.first;
		}
		else {
			if (z.first > mx2)
				mx2 = z.first;
		}
	}
	long long wew = mx1 + mx2 + w[v];
	return make_pair(max(mx1, mx2) + w[v], max(mx, wew));
}

int main() {
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		long long x;
		cin >> x;
		w.push_back(x);
		e.push_back(vector<pair<int, long long>>());
	}
	for (size_t i = 0; i < n - 1; i++)
	{
		long long x, y, c;
		cin >> x >> y >> c;
		e[x - 1].push_back(make_pair(y - 1, c));
		e[y - 1].push_back(make_pair(x - 1, c));
	}
	visited = vector<bool>(n, false);
	cout << dfs(0).second;
	return 0;
}