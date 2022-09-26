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

int p[2001];
int a[2001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++) 
	{
		cin >> p[i]; p[i] = abs(p[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(p[i] > p[j]) ans++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		int cnt = ans;
		for(int j = 0; j < n; j++)
		{
			if(j==i) continue;
			if(i<j&&p[i]>p[j]) cnt--;
			if(i>j&&p[i]<p[j]) cnt--;
		}
		p[i]*=-1;
		for(int j = 0; j < n; j++)
		{
			if(j==i) continue;
			if(i<j&&p[i]>p[j]) cnt++;
			if(i>j&&p[i]<p[j]) cnt++;
		}
		if(cnt < ans)
		{
			ans = cnt;
		}
		else
		{
			p[i]*=-1;
		}
	}
	cout << ans;
}