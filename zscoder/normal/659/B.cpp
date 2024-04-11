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

vector<pair<ii, string> > vec;
bool comp(pair<ii, string> a, pair<ii, string> b)
{
	if(a.fi.fi != b.fi.fi) return a.fi.fi < b.fi.fi;
	else if(a.fi.se != b.fi.se) return a.fi.se > b.fi.se;
	else return a.se < b.se;
}
vector<pair<int,string> > l[10001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; int a, b; int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		cin >> a >> b;
		vec.pb(mp(mp(a, b), s));
	}
	sort(vec.begin(), vec.end(), comp);
	for(int i = 0; i < n; i++)
	{
		//cout << vec[i].fi.fi << " " << vec[i].fi.se << " " << vec[i].se << endl;
		l[vec[i].fi.fi].pb(mp(vec[i].fi.se, vec[i].se));
	}
	for(int i = 1; i <= m; i++)
	{
		if(l[i].size() >= 3 && l[i][1].fi == l[i][2].fi)
		{
			cout << "?\n";
		}
		else
		{
			cout << l[i][0].se << " " << l[i][1].se << "\n";
		}
	}
	return 0;
}