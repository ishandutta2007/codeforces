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

//only push if the move is <= 30
//second mask denotes used <= 30 moves
unordered_map<ll,int> dp;

ll hsh(int a, int mask)
{
	return (mask*100LL+a);
}

int solve(int x, int mask)
{
	if(dp.find(hsh(x,mask))!=dp.end()) return dp[hsh(x,mask)];
	if(x==0) return 0;
	int cnt[x+1];
	memset(cnt,0,sizeof(cnt));
	for(int i = 1; i <= x; i++)
	{
		if(i>30)
		{
			cnt[solve(x-i,mask)]++;
		}
		else if(!(mask&(1<<i)))
		{
			cnt[solve(x-i,mask^(1<<i))]++;
		}
	}
	int grundy = 0;
	for(int i=0;i<=x;i++)
	{
		if(cnt[i]>0) grundy++;
		else break;
	}
	return (dp[hsh(x,mask)]=grundy);
}

int dd[61];

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i = 1; i <= 60; i++) dd[i]=solve(i,0);
	int n; scanf("%d",&n);
	int grundy = 0;
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		grundy^=dd[x];
	}
	if(grundy>0) printf("NO");
	else printf("YES");
}