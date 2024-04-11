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

int a[16];
int b[16];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("AMAEXPER.in", "r", stdin);
	int n;
	cin >> n;
	for(int i =0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i =0; i < n; i++)
	{
		cin >> b[i];
	}
	ld ans = 0;
	ll l = 720720;
	ll cnt = 0;
	for(int i = 0; i < l; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i%a[j] == b[j])
			{
				cnt++;
				break;
			}
		}
	}
	ans = ld(cnt)/ld(l);
	cout << fixed << setprecision(20) << ans;
	return 0;
}