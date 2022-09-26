#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int a[101];
vector<ii> moves;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < m; i++)
	{
		int minidx = -1; int maxidx = -1;
		int mini = 100000; int maxi = -1;
		for(int j = 0; j < n; j++)
		{
			if(a[j] < mini)
			{
				mini = a[j];
				minidx = j;
			}
			if(a[j] > maxi)
			{
				maxi = a[j];
				maxidx = j;
			}
		}
		if(maxidx == minidx) break;
		else 
		{
			moves.pb(mp(maxidx, minidx));
			a[maxidx]--; a[minidx]++;
		}
	}
	int minidx = -1; int maxidx = -1;
	int mini = 100000; int maxi = -1;
	for(int j = 0; j < n; j++)
	{
		if(a[j] < mini)
		{
			mini = a[j];
			minidx = j;
		}
		if(a[j] > maxi)
		{
			maxi = a[j];
			maxidx = j;
		}
	}
	cout << maxi - mini << ' ' << moves.size() << '\n';
	for(int i = 0; i < moves.size(); i++)
	{
		cout << moves[i].fi+1 << ' ' << moves[i].se+1 << '\n';
	}
}