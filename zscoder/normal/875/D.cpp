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

int st[19][200011];
int a[200011];
int n;
	
void init()
{
	for(ll j = 0; j < 19; j++)
	{
		for(ll i = 0; i < 200010; i++)
		{
			st[j][i] = 0;
			if(i + (1<<j) - 1 < 200010)
			{
				if(j == 0) st[j][i] = a[i];
				else st[j][i] = (st[j-1][i]|st[j-1][i + (1<<(j-1))]);
			}
		}
	}
}
	
int query(int l, int r)
{
	int k = 31 - __builtin_clz(r-l);
	if(l==r) k=0;
	return (st[k][l]|st[k][r - (1<<k) + 1]);
}

vi x;
int b[200011];
vi pos[200011];

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", a+i);
		x.pb(a[i]);
	}
	sort(x.begin(),x.end());
	x.erase(unique(x.begin(),x.end()),x.end());
	for(int i=0;i<n;i++)
	{
		b[i]=lower_bound(x.begin(),x.end(),a[i])-x.begin();
		pos[b[i]].pb(i);
	}
	init();
	ll res = 0;
	for(int i=0;i<n;i++)
	{
		int lo = 0; int hi = i - 1;
		int ans1 = i;
		while(lo<=hi)
		{
			int mid=(lo+hi)>>1;
			if(query(mid,i)<=a[i])
			{
				ans1=mid;
				hi=mid-1;
			}
			else
			{
				lo=mid+1;
			}
		}
		lo = i + 1; hi = n - 1;
		int p=b[i];
		int ub=upper_bound(pos[p].begin(),pos[p].end(),i)-pos[p].begin();
		if(ub<int(pos[p].size()))
		{
			hi = pos[p][ub] - 1;
		}
		int ans2 = i;
		while(lo<=hi)
		{
			int mid=(lo+hi)>>1;
			if(query(i,mid)<=a[i])
			{
				ans2=mid;lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
		res += ll(i - ans1)*ll(ans2 - i);
		res += ans2 - i;
		res += i - ans1;
	}
	res = (ll(n)*ll(n-1))/2 - res;
	printf("%lld\n", res);
}