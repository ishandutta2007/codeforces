#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef pair<ii, ll> iii;
typedef long double ld;

ld dist(ll ax, ll ay, ll bx, ll by)
{
	ld bigvalue = (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
	ld ans = sqrt(double(bigvalue));
	return ans;
}

ll X[100001];
ll Y[100001];

vector<pair<ld, int> > veca;
vector<pair<ld, int> > vecb;

ld mini(ld x, ld y)
{
	if(x < y) return x;
	else return y;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll ax, ay, bx, by, rx, ry;
	cin >> ax >> ay >> bx >> by >> rx >> ry;
	int n; cin >> n;
	ll x, y;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		X[i] = x;
		Y[i] = y;
		veca.pb(mp((dist(ax, ay, x, y) - dist(rx, ry, x, y)), i));
		vecb.pb(mp((dist(bx, by, x, y) - dist(rx, ry, x, y)), i));
	}
	sort(veca.begin(), veca.end());
	sort(vecb.begin(), vecb.end());
	ld ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans += dist(X[i], Y[i], rx, ry);
	}
	ans *= 2;
	if(n == 1)
	{
		ans += mini(veca[0].fi, vecb[0].fi);
	}
	else
	{
		ld ans1 = ans;
		ld ans2 = ans;
		ans1 += mini(veca[0].fi, vecb[0].fi);
		if(veca[0].se != vecb[0].se)
		{
			ans2 += veca[0].fi;
			ans2 += vecb[0].fi;
		}
		else
		{
			ans2 += mini(veca[0].fi + vecb[1].fi, veca[1].fi + vecb[0].fi);
		}
		ans = min(ans1, ans2);
	}
	cout << fixed << setprecision(15) << ans;
	return 0;
}