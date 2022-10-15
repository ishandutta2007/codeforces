#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
int n,q;
struct op{int typ,l,r,x,pos;}p[maxn];
vector<tuple<int,int,bool>>ch[maxn];
struct dsu
{
	int fa[maxn];
	void prework(){iota(fa+1,fa+n+2,1);}
	int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
	void merge(int x,int y){fa[get(x)]=get(y);}
}S;
int cur[maxn],pre[maxn];
int mp[21][maxn],mv[21][maxn];
int minp(int x,int y){return cur[x]<cur[y]?x:y;}
int querymp(int l,int r)
{
	int k=log2(r-l+1);
	return minp(mp[k][l],mp[k][r-(1<<k)+1]);
}
int querymv(int l,int r)
{
	int k=log2(r-l+1);
	return max(mv[k][l],mv[k][r-(1<<k)+1]);
}
int main()
{
	n=read();q=read();
	for(int i=1;i<=q;i++)
	{
		bool t=read();
		if(!t){p[i].l=read();p[i].r=read();p[i].x=read();}
		if(t)p[i].pos=read();
	}
	S.prework();
	for(int i=1;i<=q;i++)
		if(p[i].x==0&&p[i].l)
			for(int j=S.get(p[i].l);j<=p[i].r;j=S.get(j))
			{
				cur[j]=i;
				S.merge(j,j+1);
			}
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+(cur[i]>0);
	for(int i=1;i<=n;i++)mp[0][i]=i;
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			mp[i][j]=minp(mp[i-1][j],mp[i-1][j+(1<<(i-1))]);
	
	for(int i=1;i<=n;i++)mv[0][i]=cur[i];
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			mv[i][j]=max(mv[i-1][j],mv[i-1][j+(1<<(i-1))]);
	
	for(int i=1;i<=q;i++)
	{
		if(p[i].l)
		{
			if(p[i].x==0)ch[i].push_back({p[i].l,p[i].r,0});
			else
				if(pre[p[i].r]-pre[p[i].l-1]==p[i].r-p[i].l)
					ch[max(i,querymv(p[i].l,p[i].r))].push_back({querymp(p[i].l,p[i].r),querymp(p[i].l,p[i].r),1});
		}
	}
	S.prework();
	fill_n(cur+1,n,-1);
	for(int i=1;i<=q;i++)
	{
		for(auto &j:ch[i])
			for(int k=S.get(get<0>(j));k<=get<1>(j);k=S.get(k))
			{
				cur[k]=get<2>(j);
				S.merge(k,k+1);
			}
		if(p[i].pos)
			puts(cur[p[i].pos]==-1?"N/A":cur[p[i].pos]?"YES":"NO");
	}
	return 0;
}