#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e3+5;
int n,d;
int cnt;
multiset<int>s;
struct dsu
{
	int fa[maxn],siz[maxn];
	void prework(){for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1,s.insert(1);}
	int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
	void merge(int x,int y)
	{
		x=get(x);y=get(y);
		if(x==y){cnt++;return;}
		s.erase(s.find(siz[x]));
		s.erase(s.find(siz[y]));
		fa[x]=y;siz[y]+=siz[x];
		s.insert(siz[y]);
	}
	int query()
	{
		int ret=0,rk=cnt+1;
		for(auto i=--s.end();;i--)
		{
			ret+=*i;
			rk--;
			if(!rk||i==s.begin())break;
		}
		return ret-1;
	}
}S;
int main()
{
	n=read();d=read();S.prework();
	for(int i=1;i<=d;i++)
	{
		int x=read(),y=read();
		S.merge(x,y);
		printf("%d\n",S.query());
	}
	return 0;
}