#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=505,TS=1010;
struct thing
{
	int in,out,w,s,v;
}t[N]={};
int n,S,f[N][TS]={};
bool checked[N]={};
void init()
{
	scanf("%d%d",&n,&S);
	for(int i=1,in,out,w,s,v;i<=n;++i)
	{
		scanf("%d%d%d%d%d",&in,&out,&w,&s,&v);
		t[i]=(thing){in,out,w,s,v};
	}
	++n,t[n]=(thing){0,n+n,0,S,0};
}
void dp(int s)
{
	checked[s]=true;
	for(int i=1;i<=n;++i)
		if(s!=i && t[i].in>=t[s].in && t[i].out<=t[s].out && !checked[i])
			dp(i);
	int last[N+N]={},num[N]={},next[N]={},total_edge=0,g[N+N]={};
	for(int i=1;i<=n;++i)
		if(s!=i && t[i].in>=t[s].in && t[i].out<=t[s].out)
		{
			next[++total_edge]=last[t[i].out];
			last[t[i].out]=total_edge;
			num[total_edge]=i;
		}
	for(int i=0;i<=t[s].s && i+t[s].w<=S;++i)
	{
		fill(g+t[s].in+1,g+t[s].out+1,0);
		for(int j=t[s].in+1;j<=t[s].out;++j)
		{
			g[j]=g[j-1];
			for(int k=last[j];k;k=next[k])
			{
				int now=num[k];
				g[j]=max(g[t[now].in]+f[now][i],g[j]);
			}
		}
		f[s][i+t[s].w]=g[t[s].out]+t[s].v;
	}
	for(int i=t[s].w+1;i<=S;++i)
		f[s][i]=max(f[s][i],f[s][i-1]);
}
void work()
{
	for(int i=1;i<=n;++i)
		if(!checked[i])
			dp(i);
	printf("%d\n",f[n][t[n].s]);
}
int main()
{	
	init();
	work();
	return 0;
}