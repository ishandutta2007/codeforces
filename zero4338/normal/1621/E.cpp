#include<bits/stdc++.h>
#define int long long
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
const int maxn=1e5+5;
int n,m;
int a[maxn];
vector<int>b[maxn];ll sum[maxn];
int num[maxn<<2],cnt;
int id(int x){return lower_bound(num+1,num+cnt+1,x)-num;}
struct segment
{
	#define L(u) u<<1
	#define R(u) u<<1|1
	struct node{int mi,tag;}t[maxn<<3];
	void update(int u){t[u].mi=min(t[L(u)].mi,t[R(u)].mi)+t[u].tag;}
	void change(int nl,int nr,int x,int u=1,int l=1,int r=cnt)
	{
		if(l>=nl&&r<=nr){t[u].tag+=x;t[u].mi+=x;return;}
		int mid=(l+r)>>1;
		if(mid>=nl)change(nl,nr,x,L(u),l,mid);
		if(mid+1<=nr)change(nl,nr,x,R(u),mid+1,r);
		update(u);
	}
	void clear(int u=1,int l=1,int r=cnt)
	{
		t[u].mi=t[u].tag=0;
		if(l==r)return;
		int mid=(l+r)>>1;
		clear(L(u),l,mid);clear(R(u),mid+1,r);
	}
}tr;
signed main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		generate_n(a+1,n,read);
		cnt=0;
		for(int i=1;i<=n;i++)num[++cnt]=a[i];
		for(int i=1;i<=m;i++)
		{
			b[i].resize(read());sum[i]=0;
			generate(b[i].begin(),b[i].end(),read);
			for(int &j:b[i])sum[i]+=j;
		}
		for(int i=1;i<=m;i++)
		{
			for(int &j:b[i])
			{
				ll now=(sum[i]-j-1)/(b[i].size()-1)+1;
				num[++cnt]=now;
			}
			ll now=(sum[i]-1)/b[i].size()+1;
			num[++cnt]=now;
		}
		sort(num+1,num+cnt+1);cnt=unique(num+1,num+cnt+1)-(num+1);
		tr.clear();
		for(int i=1;i<=n;i++)
			tr.change(1,id(a[i]),1);
		for(int i=1;i<=m;i++)
			tr.change(1,id((sum[i]-1)/b[i].size()+1),-1);
		for(int i=1;i<=m;i++)
		{
			tr.change(1,id((sum[i]-1)/b[i].size()+1),1);
			for(int &j:b[i])
			{
				ll now=(sum[i]-j-1)/(b[i].size()-1)+1;
					
				tr.change(1,id(now),-1);
				putchar(tr.t[1].mi>=0?'1':'0');
				tr.change(1,id(now),1);
				
			}
			tr.change(1,id((sum[i]-1)/b[i].size()+1),-1);
		}
		putchar('\n');
	}
	return 0;
}