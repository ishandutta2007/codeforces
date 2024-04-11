#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;
const int MOD = 1e9 + 7;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
set<ii> s;
int aa[100001];
int bb[100001];
int cc[100001];
map<int, int> ma;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int x;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		ma[x]++;
	}
	for(map<int,int>::iterator it = ma.begin(); it != ma.end(); it++)
	{
		s.insert(mp(it->se, it->fi));
	}
	set<ii>::iterator it;
	ii a, b, c;
	while(s.size() >= 3)
	{
		it = s.end(); it--;
		a = *it;
		it--;
		b = *it;
		it--;
		c = *it;
		it--;
		aa[cnt] = a.se;
		bb[cnt] = b.se;
		cc[cnt] = c.se;
		s.erase(a);
		if(a.fi > 1) s.insert(ii(a.fi - 1, a.se));
		s.erase(b);
		if(b.fi > 1) s.insert(ii(b.fi - 1, b.se));
		s.erase(c);
		if(c.fi > 1) s.insert(ii(c.fi - 1, c.se));
		cnt++;
	}
	cout << cnt << "\n";
	for(int i = 0; i < cnt; i++)
	{
		if(aa[i] < cc[i]) swap(aa[i], cc[i]);
		if(bb[i] < cc[i]) swap(cc[i], bb[i]);
		if(aa[i] < bb[i]) swap(aa[i], bb[i]);
		cout << aa[i] << " " << bb[i] << " " << cc[i] << "\n";
	}
	return 0;
}