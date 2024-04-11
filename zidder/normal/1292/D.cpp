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
const ll E9 = 1000 * 1000ll * 1000;
const ll E18 = E9 * E9;
int t;

struct int128 {
  ll a, b;
  int128(ll aa){
      a = aa;
      b = 0;
  }
  int128 const operator +(int128 o){
      int128 res(0);
      res.a = a + o.a;
      res.b = b + o.b;
      if (o.a + a < 0){
          res.b++;
          res.a -= E18;
      }
      return res;
  }
  int128 const operator -(int128 o){
      int128 res(0);
      res.a = a - o.a;
      res.b = b - o.b;
      if (res.a < 0){
          res.b--;
          res.a += E18;
      }
      return res;
  }
  int128 const operator *(int128 o){
      int128 res(a / 2);
      if (a == 0)
          return res;
      res = res * o;
      res = res + res;
      if (a%2)
          res = res + o;
      return res;
  }
};

vector<int> k;
vector<int> ps;
vector<int> mp(5001), fdc(5001), dc(5001);
vector<unordered_map<int, int> > _cinf(5001);
 
int cinf(int n, int p) {
	if (_cinf[n].count(p))
		return _cinf[n][p];
	return (_cinf[n][p] = n < p ? 0 : p < 2 ? 0 : n / p + cinf(n / p, p));
}
void clear_(vector<pair<int, int> >& cs) {
	for (int i = 0; i < cs.size(); i++)
	{
		if (cs[i].first == 1) {
			swap(k[i], k.back());
			swap(cs[i], cs.back());
			k.pop_back();
			cs.pop_back();
			i--;
			continue;
		}
	}
}
void solve(int testid) {
	for (size_t i = 1; i <= 5000; i++)
	{
		bool prime = true;
		for (size_t j = 1; j < ps.size(); j++)
		{
			if (i % ps[j] == 0) {
				prime = false;
				break;
			}
		}
		if (prime)
			ps.push_back(i);
	}
 
	for (size_t i = 1; i <= 5000; i++)
	{
		mp[i] = ps[(upper_bound(ps.begin(), ps.end(), i) - ps.begin()) - 1];
	}
	for (size_t i = 1; i <= 5000; i++)
	{
		for (size_t j = 1; j < ps.size(); j++)
		{
			if (ps[j] * i > 5000)
				break;
			dc[ps[j] * i] = dc[i] + 1;
		}
		fdc[i] = fdc[i - 1] + dc[i];
	}
 
	int n;
	cin >> n;
	vector<pair<int, int> > cs;
	vector<int> mm(5001);
	int128 ans(0);
	for (size_t i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		x += (x==0);
		mm[x]++;
	}
	for (size_t i = 1; i <= 5000; i++)
	{
		if (mm[i] == 0)
			continue;
		int x = i;
		k.push_back(x);
		cs.emplace_back(mp[x], 1);
		ans = ans + int128(fdc[x]) * int128(mm[i]);
	}
	clear_(cs);
	while (true) {
		unordered_map<int, int> qw;
		int choose = -1;
		for (size_t i = 0; i < cs.size(); i++)
		{
			qw[cs[i].first] += mm[k[i]];
			if (qw[cs[i].first] * 2 > n)
				choose = cs[i].first;
		}
		if (choose == -1) {
			break;
		}
		int dt = (qw[choose] * 2 - n);
		int ms = 500;
		for (size_t i = 0; i < cs.size(); i++)
		{
			if (cs[i].first == choose) {
				ms = min(cs[i].second, ms);
			}
		}
		ans = ans - int128(ms * dt);
		for (size_t i = 0; i < cs.size(); i++)
		{
			if (cs[i].first == choose) {
				cs[i].second -= ms;
				if (cs[i].second == 0) {
					cs[i].first = mp[cs[i].first - 1];
					cs[i].second = cinf(k[i], cs[i].first);
				}
			}
			else {
				cs[i].first = 1;
			}
		}
		clear_(cs);
	}
	if (ans.b)
	    cout << ans.b;
	cout << ans.a << endl;
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