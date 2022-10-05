%:pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#define xxx 5200
using namespace std; 
struct edge{
	long long from,to,waste;
}e[xxx];
struct road{
	long long to,was;
};
vector<road>r[xxx];
vector<road>ch[xxx];
long long n,root[3],heart[3],siz[xxx],tot,used[xxx];
long long ans=1e18,sum[3],star[3];
bool die[5002][5002];

void build(long long x)
{
	used[x]=1;
	siz[x]=1;
	long long y;
	ch[x].clear();
	for (long long i=0;i<r[x].size();i++)
	{
		y=r[x][i].to;
		if (die[x][y]||used[y]) continue;
		ch[x].push_back((road){y,r[x][i].was});
		build(y);
		siz[x]+=siz[y];
	}
}

long long sumup(long long x,long long type)
{
	long long turn=0;long long y;
	for (long long i=0;i<ch[x].size();i++)
	{
		y=ch[x][i].to;
		turn+=ch[x][i].was*siz[y]*(type==1?tot-siz[y]:1);
		turn+=sumup(y,type);
	}
	return turn;
}

long long findheart(long long x)
{
	for (long long i=0;i<ch[x].size();i++)
		if (siz[ch[x][i].to]*2>tot)
			return findheart(ch[x][i].to);
	return x;
}

int main()
{
	scanf("%I64d",&n);
	long long x,y,z;
	long long tem;
	for (long long i=1;i<n;i++)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		e[i]=(edge){x,y,z};
		r[x].push_back((road){y,z});
		r[y].push_back((road){x,z});
	}
	for (long long i=1;i<n;i++)
	{
		die[e[i].from][e[i].to]=1;
		die[e[i].to][e[i].from]=1;
		root[1]=e[i].from;
		root[2]=e[i].to;
		for (long long j=1;j<=2;j++)
		{
			memset(used,0,sizeof(used));build(root[j]);
			tot=siz[root[j]];
			root[j]=findheart(root[j]);
			memset(used,0,sizeof(used));build(root[j]);
			tot=siz[root[j]];
			sum[j]=sumup(root[j],1);
			star[j]=sumup(root[j],2);
		}
		tem=siz[root[1]]*siz[root[2]]*e[i].waste+sum[1]+sum[2]+star[1]*siz[root[2]]+star[2]*siz[root[1]];
		ans=min(ans,tem);
		die[e[i].from][e[i].to]=0;
		die[e[i].to][e[i].from]=0;
	}
	printf("%I64d",ans);
}