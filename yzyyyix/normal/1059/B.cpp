#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 1010
#define M
using namespace std;

ll m,n,L,a,num[N],len[N],ans;
bool mm[N][N],ok[N][N];
char str[N];

int main()
{
	ll i,j,ii,jj;
	cin>>m>>n;
	for(i=1; i<=m; i++)
	{
		scanf("%s",str+1);
		for(j=1; j<=n; j++)
		{
			if(str[j]=='#') mm[i][j]=1;
		}
	}
	for(i=1; i<=m-2; i++)
	{
		for(j=1; j<=n-2; j++)
		{
			for(ii=i; ii<=i+2; ii++)
			{
				for(jj=j; jj<=j+2; jj++)
				{
					if(ii==i+1&&jj==j+1) continue;
					if(!mm[ii][jj]) break;
				}
				if(jj<=j+2) break;
			}
			if(ii>i+2)
			{
				for(ii=i; ii<=i+2; ii++)
				{
					for(jj=j; jj<=j+2; jj++)
					{
						if(ii==i+1&&jj==j+1) continue;
						ok[ii][jj]=1;
					}
				}
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(mm[i][j]&&!ok[i][j])
			{
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
}