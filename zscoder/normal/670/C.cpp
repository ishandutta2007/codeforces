#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

map<ll, ll> ma;
ll a[200001];
ll b[200001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	ll x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		ma[x]++;
	}
	int m; cin >> m;
	for(int i =0; i < m; i++)
	{
		cin >> a[i];
	}
	for(int i =0; i < m; i++)
	{
		cin >> b[i];
	}
	int bestidx = 0;
	int freqaudio = 0;
	int freqsub = 0;
	for(int i = 0; i < m; i++)
	{
		if(ma[a[i]] > freqaudio)
		{
			freqaudio = ma[a[i]];
			freqsub = ma[b[i]];
			bestidx = i;
		}
		else if(ma[a[i]] >= freqaudio)
		{
			if(ma[b[i]] > freqsub)
			{
				freqsub = ma[b[i]];
				freqaudio = ma[a[i]];
				bestidx = i;
			}
		}
	}
	cout << bestidx + 1;
	return 0;
}