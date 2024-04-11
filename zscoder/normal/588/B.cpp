#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n; cin >> n;
	for(ll i = 2; i*i <= n; i++)
	{
		while(n%(i*i) == 0)
		{
			n /= i;
		}
	}
	cout << n;
	return 0;
}