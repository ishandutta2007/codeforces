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

int a[200001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	ll ans = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(i > 0)
		{
			ans += ll(abs(a[i] - a[i - 1]));
		}
		else
		{
			ans += ll(abs(a[i]));
		}
	}
	cout << ans;
	return 0;
}