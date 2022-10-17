#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 1010
#define M 
using namespace std;

ll T,n,m,ans,mm[N][N];
bool num[N][N];

ll gcd(ll u,ll v){return v?gcd(v,u%v):u;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
inline ll cg(char u){return u-'a'+1;}
inline void work(ll u,ll v)
{
	if(u>1) num[u-1][v]^=1;
	if(u<n) num[u+1][v]^=1;
	if(v>1) num[u][v-1]^=1;
	if(v<n) num[u][v+1]^=1;
}
inline bool judge(ll u,ll v)
{
	if(u>1 && num[u-1][v]) return 0;
	if(u<n && num[u+1][v]) return 0;
	if(v>1 && num[u][v-1]) return 0;
	if(v<n && num[u][v+1]) return 0;
	return 1;
}
int main()
{
	ll i,j,p,q,pp,qq;
	cin>>T;
	while(T--)
	{
		ans=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) num[i][j]=0,scanf("%lld",&mm[i][j]);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(j<n && judge(i,j) &&judge(i,j+1))
				{
					ans^=mm[i][j],ans^=mm[i][j+1];
					work(i,j),work(i,j+1);
				}
				if(i<n && judge(i,j) && judge(i+1,j))
				{
					ans^=mm[i][j],ans^=mm[i+1][j];
					work(i,j),work(i+1,j);
				}
			}
		}
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(!num[i][j]) puts("gg");
		printf("%lld\n",ans);
	}
}