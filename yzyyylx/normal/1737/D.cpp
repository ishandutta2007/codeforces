#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 510
#define M 250010
using namespace std;

ll T,n,m,ans,A[M],B[M],C[M],mm[N][N];

inline void Min(ll &u,ll v){if(v<u) u=v;}
int main()
{
	ll i,j,k,p,q,o;
	cin>>T;
	while(T--)
	{
		ans=INF;
		memset(mm,0x3f,sizeof(mm));
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&p,&q,&o);
			A[i]=p,B[i]=q,C[i]=o;
			Min(mm[p][q],1),Min(mm[q][p],1);
		}
		for(i=1;i<=n;i++) mm[i][i]=0;
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					Min(mm[i][j],mm[i][k]+mm[k][j]);
				}
			}
		}
		for(i=1;i<=m;i++)
		{
			ll t=min(mm[1][A[i]]+mm[B[i]][n],mm[1][B[i]]+mm[A[i]][n]);
			for(j=1;j<=n;j++)
			{
				Min(t,mm[1][j]+mm[j][n]+mm[A[i]][j]+1);
				Min(t,mm[1][j]+mm[j][n]+mm[B[i]][j]+1);
			}
			Min(ans,C[i]*(t+1));
		}
		printf("%lld\n",ans);
	}
}