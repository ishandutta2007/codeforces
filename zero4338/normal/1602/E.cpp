#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=2e6+5;
int n,m,a[maxn],b[maxn],id[maxn];
ll ans;
struct segment
{
	struct node{int mi,tag;}t[maxn<<2];
	void pushdown(int u){if(t[u].tag)put(u*2,t[u].tag),put(u*2+1,t[u].tag),t[u].tag=0;}
	void update(int u){t[u].mi=min(t[u*2].mi,t[u*2+1].mi);}
	void put(int u,int v){t[u].tag+=v,t[u].mi+=v;}
	void build(int u=1,int l=0,int r=n)
	{
		t[u].tag=0;t[u].mi=l;
		int mid=(l+r)>>1;
		if(l==r)return;
		build(u*2,l,mid),build(u*2+1,mid+1,r);
	}
	void change(int lc,int u=1,int l=0,int r=n)
	{
		if(lc<=l)return put(u,-1);pushdown(u);int mid=(l+r)>>1;
		if(lc<=mid)change(lc,u*2,l,mid);change(lc,u*2+1,mid+1,r);update(u);
	}
}tr1;
struct fenwick
{
	int a[maxn];
	void change(int x){for(;x<=n;x+=x&-x)++a[x];}
	int query(int x){int ret=0;for(;x;x&=x-1)ret+=a[x];return ret;}
	void clr(){for(int i=1;i<=n;++i)a[i]=0;}
}tr2;
int main(){
	T=read();
	while(T--)
	{
		n=read();m=read();
		for(int i=1;i<=n;i++)a[i]=read(),id[i]=i;
		sort(id+1,id+n+1,[&](int x,int y){return a[x]!=a[y]?a[x]<a[y]:x<y;});for(int i=1;i<=m;++i)b[i]=read();
		id[n+1]=0,a[0]=2e9;
		sort(b+1,b+m+1);
		tr1.build(1,0,n);
		ll ans=0;
		tr2.clr();
		for(int i=n;i>=1;i--)ans+=tr2.query(id[i]),tr2.change(id[i]);
		for(int i=1,p=1,h=0;i<=m;i++)
		{
			if(b[i]!=b[i-1])
			{
				while(a[id[p]]==b[i-1])tr1.change(id[p++]),++h;
				while(a[id[p]]<b[i])tr1.change(id[p]),tr1.change(id[p++]),++h;
				for(int j=p;a[id[j]]==b[i];++j)tr1.change(id[j]);
			}
			ans+=h+tr1.t[1].mi;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}