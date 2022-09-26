#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

vector<pair<ll,ll> > lines;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	ll x1, x2;
	cin>>x1>>x2;
	lines.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin>>lines[i].fi>>lines[i].se;
	}
	for(int i = 0; i < n; i++)
	{
		ll x, y;
		x = lines[i].fi; y = lines[i].se;
		lines[i].fi = x*x1 + y;
		lines[i].se = x*x2 + y;
		//if(x < 0) swap(lines[i].fi, lines[i].se);
	}
	sort(lines.begin(), lines.end());
	ll maxy = -ll(1e18); ll tmpmaxy = lines[0].se;
	for(int i = 1; i < n; i++)
	{
		if(lines[i].fi == lines[i-1].fi)
		{
			tmpmaxy = max(tmpmaxy, lines[i].se);
			if(lines[i].se < maxy)
			{
				cout << "YES";
				return 0;
			}
		}
		else
		{
			maxy = max(tmpmaxy, maxy);
			tmpmaxy = lines[i].se;
			if(lines[i].se < maxy)
			{
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}