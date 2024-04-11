#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	ii pt[4];
	for(int i = 0; i < n; i++)
	{
		cin >> pt[i].fi >> pt[i].se;
	}
	sort(pt, pt + n);
	if(n == 4)
	{
		int ans = abs(pt[2].fi -pt[0].fi)*abs(pt[1].se-pt[0].se);
		cout << ans;
		return 0;
	}
	if(n == 1)
	{
		cout << -1;
		return 0;
	}
	if(n == 3)
	{
		if(pt[0].fi == pt[1].fi)
		{
			cout << abs(pt[2].fi - pt[0].fi)*abs(pt[1].se - pt[0].se);
		}
		else
		{
			cout << abs(pt[1].fi - pt[0].fi)*abs(pt[2].se - pt[1].se);
		}
		return 0;
	}	
	if(n == 2)
	{
		if(pt[0].fi == pt[1].fi)
		{
			cout << -1;
		}
		else if(pt[0].se == pt[1].se)
		{
			cout << -1;
		}
		else
		{
			cout << abs(pt[1].fi - pt[0].fi)*abs(pt[1].se - pt[0].se);
		}
		return 0;
	}
	return 0;
}