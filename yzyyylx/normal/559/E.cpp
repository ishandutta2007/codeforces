#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<map>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 3010
using namespace std;

ll n,num[N],l[N],r[N],b[N*3],id[N*3],dp[N][N*3],bb,cnt,ans;
struct Ny
{
	ll pos,l,r;
	bool operator < (const Ny &u) const
	{
		return pos<u.pos;
	}
} ny[N];
map<ll,ll>mm;

inline void Max(ll &u,ll v)
{
	if(v>u) u=v;
}

int main()
{
	memset(dp,-0x3f,sizeof(dp));
	memset(dp[0],0,sizeof(dp[0]));
	ll i,j,last,mx;
	cin>>n;
	for(i=1; i<=n; i++)
	{
		scanf("%lld%lld",&ny[i].pos,&ny[i].l);
		ny[i].r=ny[i].l;
		ny[i].l=ny[i].pos-ny[i].l;
		ny[i].r=ny[i].pos+ny[i].r;
		b[++bb]=ny[i].l;
		b[++bb]=ny[i].pos;
		b[++bb]=ny[i].r;
	}
	sort(b+1,b+bb+1);
	for(i=1;i<=bb;i++)
	{
		if(i==1 || b[i]!=b[i-1])
		{
			b[++cnt]=b[i];
			mm[b[i]]=cnt;
		}
	}
	sort(ny+1,ny+n+1);
	for(i=1; i<=n; i++) num[i]=mm[ny[i].pos],l[i]=mm[ny[i].l],r[i]=mm[ny[i].r],id[num[i]]=i;
	for(i=1;i<=n;i++)
	{
		memcpy(dp[i],dp[i-1],sizeof(dp[i]));
		for(j=l[i]+1;j<=num[i];j++) Max(dp[i][j],dp[i][j-1]+b[j]-b[j-1]);
		mx=dp[i-1][num[i]];
		for(j=num[i]+1;j<=r[i];j++)
		{
			Max(dp[i][j],mx+b[j]-b[num[i]]);
			if(id[j] && l[id[j]]<=num[i])
			{
				Max(mx,dp[i-1][l[id[j]]]+b[num[i]]-b[l[id[j]]]);
			}
		}
		for(j=1;j<=cnt;j++) Max(dp[i][j],dp[i][j-1]);
	}
	cout<<dp[n][cnt];
}