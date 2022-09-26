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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

char a[2001][2001];
int main()
{
	int n,m,k; scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%s", &a[i][0]);
	}
	ll ans = 0;
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		if(k>m) continue; 
		for(int j=0;j<k;j++)
		{
			cnt+=(a[i][j]=='*');
		}
		if(cnt==0) ans++;
		for(int j=k;j<m;j++)
		{
			cnt+=(a[i][j]=='*')-(a[i][j-k]=='*');
			if(cnt==0) ans++;
		}
	}
	if(k>1)
	{
		for(int j=0;j<m;j++)
		{
			int cnt=0;
			if(k>n) continue; 
			for(int i=0;i<k;i++)
			{
				cnt+=(a[i][j]=='*');
			}
			if(cnt==0) ans++;
			for(int i=k;i<n;i++)
			{
				cnt+=(a[i][j]=='*')-(a[i-k][j]=='*');
				if(cnt==0) ans++;
			}
		}
	}
	cout<<ans<<'\n';
}