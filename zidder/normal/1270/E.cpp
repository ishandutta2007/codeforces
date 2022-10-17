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
int m2(int x) {
	return (x % 2 + 2) % 2;
}

vector<int> solvev(vector<pair<int, int> >& ps) {
	vector<int> ansa;

	for (size_t i = 0; i < ps.size(); i++)
	{
		if (m2(ps[i].first + ps[i].second)) {
			ansa.push_back(i);
		}
	}
	if (ansa.size() == ps.size() || ansa.empty()) {
		ansa.clear();
		map<pair<int, int>, vector<int> > mp;
		for (size_t i = 0; i < ps.size(); i++)
		{
			mp[make_pair(m2(ps[i].first), m2(ps[i].second))].push_back(i);
		}
		for (size_t i = 0; i < ps.size(); i++)
		{
			ps[i].first /= 2;
			ps[i].second /= 2;
		}
		for (auto p : mp)
			ansa = p.second;
	}
	if (ansa.size() == ps.size())
		ansa.clear();
	return ansa;
}
void solve(int testid) {
	int n;
	cin >> n;
	vector<pair<int, int> > ps;
	for (size_t i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		x += 10000000;
		y += 10000000;
		ps.emplace_back(x, y);
	}
	vector<int> ansa;
	while (ansa.empty()) {
		ansa = solvev(ps);
	}
	cout << ansa.size() << endl;
	for (size_t i = 0; i < ansa.size(); i++)
	{
		cout << ansa[i] + 1 << " ";
	}
	cout << endl;
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