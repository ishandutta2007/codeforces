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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int a[1000001];
ii b[1000001];
int cnt[10000001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", a+i);
		cnt[a[i]]++;
	}
	ll sum = 0;
	for(int i = 0; i <= 10000000; i++)
	{
		cnt[i]-=k;
		sum+=cnt[i];
	}
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &b[i].fi);
		b[i].se = i+1;
	}
	sort(b,b+m);
	int ptr = m - 1;
	vi vec;
	ll avi = ll(1e18);
	for(int i = 10000000; i >= 0; i--)
	{
		int ct = 0;
		while(ptr>=0&&b[ptr].fi==i)
		{
			ct++;
			ptr--;
		}
		int las = ptr+1;
		ll tsum = sum;
		ll t2 = avi;
		while(tsum<0&&avi>0&&ct>0)
		{
			vec.pb(b[las].se);
			las++;
			tsum++;
			ct--;
			avi--;
		}
		if(sum>0)
		{
			printf("-1"); return 0;
		}
		avi=min(avi,-tsum);
		sum-=cnt[i];
	}
	printf("%d\n", int(vec.size()));
	for(int i=0;i<vec.size();i++)
	{
		printf("%d ", vec[i]);
	}
}