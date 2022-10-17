#include<bits/stdc++.h>
#define N 1005
#define M 3005
using namespace std;

int m,n,fa[N],ans;

struct Bn
{
	int from,to,mn,mx;
}bn[M];

bool cmp(Bn u,Bn v)
{
	if(u.mx==v.mx) return u.mn<v.mn;
	return u.mx>v.mx;
}

int getfa(int u)
{
	if(fa[u]==u) return u;
	else return fa[u]=getfa(fa[u]);
}

int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&bn[i].from,&bn[i].to,&bn[i].mn,&bn[i].mx);
	}
	sort(bn+1,bn+m+1,cmp);
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			fa[j]=j;
		}
		
		for(j=1;j<=m;j++)
		{
			if(bn[j].mn<=bn[i].mn&&bn[j].mx>=bn[i].mn)
			{
				fa[getfa(bn[j].from)]=getfa(bn[j].to);
				if(getfa(1)==getfa(n))
				{
					ans=max(ans,bn[j].mx-bn[i].mn+1);
					break;
				}
			}
		}
	}
	if(ans!=0)
	cout<<ans;
	else
	cout<<"Nice work, Dima!";
}