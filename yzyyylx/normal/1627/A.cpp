#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 110
#define M 
using namespace std;
 
ll T,n,m,A,B;
char mm[N][N];
 
int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&m,&n,&A,&B);
		for(i=1;i<=m;i++) scanf("%s",mm[i]+1);
		if(mm[A][B]=='B') puts("0");
		else
		{
			for(i=1;i<=m;i++) if(mm[i][B]=='B') break;
			if(i<=m) puts("1");
			else
			{
				for(i=1;i<=n;i++) if(mm[A][i]=='B') break;
				if(i<=n) puts("1");
				else
				{
					for(i=1;i<=m;i++)
					{
						for(j=1;j<=n;j++)
						{
							if(mm[i][j]=='B') break;
						}
						if(j<=n) break;
					}
					if(i<=m) puts("2");
					else puts("-1");
				}
			}
		}
	}
}