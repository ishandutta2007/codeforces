#include<bits/stdc++.h>
using namespace std;
const int N=200020,M=200020;
int n,m,last[N]={},next[M+M]={},end[M+M]={},total_edge=0;
int a[3][N]={},t[3]={},d[N]={},fa[N]={},c[N][2]={},dfn[N]={},tot=0;
bool flag=false,v[N]={};
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u=0,v=0;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
}
void get_way(int S,int T,int num)
{
	int tmp=0;
	if(d[S]<d[T])
		tmp=t[num]+1,swap(S,T);
	for(int i=S;i!=T;i=fa[i])
		a[num][++t[num]]=i;
	a[num][++t[num]]=T;
	if(tmp)
		reverse(a[num]+tmp,a[num]+t[num]+1);
}
void print_way(int s1,int t1,int s2,int t2,int common)
{
	//cout<<"s1="<<s1<<" t1="<<t1<<" s2="<<s2<<" t2="<<t2<<endl;
	if(d[s1]<d[s2])
		swap(s1,s2),swap(t1,t2);
	//cout<<"S="<<common<<" T="<<s1<<endl;
	get_way(common,s1,0);
	get_way(common,t1,1);
	a[1][++t[1]]=s1;
	get_way(common,t2,2);
	get_way(s2,s1,2);
}
void cactus(int p)
{
	//cout<<"p="<<p<<endl;
	static bool v[N]={};
	if(v[p] || flag)
		return;
	v[p]=true;
	dfn[p]=++tot;
	for(int i=last[p];i;i=next[i])
	{
		int j=end[i];
		if(j==fa[p])
			continue;
		if(!v[j])
		{
			fa[j]=p;
			d[j]=d[p]+1;
			cactus(j);
			if(flag)
				return;
		}
		else
			if(dfn[j]<dfn[p])
			{
				int S=j,T=p;
				for(int now=T; now!=S; now=fa[now])
					if(c[now][0])
					{
						print_way(S,T,c[now][0],c[now][1],now);
						flag=true;
						return;
					}
					else
						c[now][0]=S,c[now][1]=T;
			}
	}
}
void work()
{
	for(int i=1;i<=n;++i)
		cactus(i);
	if(!flag)
		puts("NO");
	else
	{
		puts("YES");
		printf("%d",t[0]);
		for(int i=1;i<=t[0];++i)
			printf(" %d",a[0][i]);
		printf("\n%d",t[1]);
		for(int i=1;i<=t[1];++i)
			printf(" %d",a[1][i]);
		printf("\n%d",t[2]);
		for(int i=1;i<=t[2];++i)
			printf(" %d",a[2][i]);
		printf("\n");
	}
}
int main()
{	
	init();
	work();
	return 0;
}