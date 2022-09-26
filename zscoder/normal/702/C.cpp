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
vi a;
vi b;

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0); 
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		int x; scanf("%d", &x); a.pb(x);
	}
	for(int i = 0; i < m; i++)
	{
		int x; scanf("%d", &x); b.pb(x);
	}
	int maxans = 0;
	for(int i = 0; i < n; i++)
	{
		int l = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		int dist = 2e9+1;
		if(l < b.size())
		{
			dist = min(dist, b[l] - a[i]);
		}
		if(l - 1 >= 0)
		{
			dist = min(dist, a[i] - b[l - 1]);
		}
		maxans = max(maxans, dist);
	}
	printf("%d", maxans);
	return 0;
}