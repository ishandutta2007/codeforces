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

void solve(int tid) {
	int n;
	cin >> n;
	map<int, int> mp;
	for (size_t i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		mp[x]++;
	}
	vector<pair<int, int> > counts;
	for (auto p : mp)
		counts.emplace_back(p.second, p.first);
	sort(counts.begin(), counts.end());
	vector<int> prefsum(1, 0);
	for (size_t i = 0; i < counts.size(); i++)
		prefsum.push_back(counts[i].first + prefsum[i]);
	int ms = 0, ml = 0;
	for (size_t ln = 1; ln <= counts.size() && ln * ln <= n; ln++)
	{
		int nind = upper_bound(counts.begin(), counts.end(), make_pair((int)ln, 0)) - counts.begin();
		int cnt = (prefsum[nind] + (counts.size() - nind) * ln);
		cnt = cnt / ln * ln;
		if (cnt >= ln * ln && cnt > ms) {
			ms = cnt;
			ml = ln;
		}
	}
	assert(ms > 0);
	cout << ms << endl;
	cout << ml << " " << ms / ml << endl;
	vector<vector<int> > v(ml, vector<int>(ms / ml));
	int sx = 0, x = 0, y = 0;
	for (int lind = counts.size() - 1; lind >= 0 && sx < ms / ml; lind--) {
		int cnt = min(counts[lind].first, ml);
		while (cnt-- > 0 && sx < ms / ml) {
			v[y][x] = counts[lind].second;
			x++;
			x %= (ms / ml);
			y++;
			if (y == ml) {
				y = 0;
				x = ++sx;
			}
		}
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
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