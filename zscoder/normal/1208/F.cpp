#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi vis;
int cnt[2222222];
bool visited[2222222];
int a[1111111];
const int LG = 22;

void dfs(int bit)
{
	if(visited[bit]) return ;
	if(cnt[bit]>=2) return ;
	cnt[bit]++;
	visited[bit]=1;
	vis.pb(bit);
	for(int i=LG-1;i>=0;i--)
	{
		if(bit&(1<<i))
		{
			dfs((bit^(1<<i)));
		}
	}
}

int main()
{
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	int ans=0;
	for(int i=n-1;i>=0;i--)
	{
		if(i<=n-3)
		{
			int res=0; int cur=0;
			for(int j=LG-1;j>=0;j--)
			{
				if(a[i]&(1<<j))
				{
					res|=(1<<j); continue;
				}
				if(cnt[(cur|(1<<j))]>=2)
				{
					res|=(1<<j); cur|=(1<<j);
				}
				else
				{
					continue;
				}
			}
			ans=max(ans,res);
		}
		dfs(a[i]);
		for(int v:vis) visited[v]=0;
		vis.clear();
	}
	printf("%d\n", ans);
}