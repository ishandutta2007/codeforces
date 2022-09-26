#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int MOD = 1e9 + 7;

map<int,int> ma;
int a[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		a[i] = x;
		ma[x]++;
	}
	ll ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= 31; j++)
		{
			int x = (1<<j) - a[i];
			int y = a[i];
			if(y != x)
			{
				ans += ma[x];
			}
			else
			{
				ans += (ma[x] - 1);
			}
		}
	}
	ans>>=1;
	cout << ans << '\n';
	return 0;
}