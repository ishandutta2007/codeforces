#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=4e5+5;
	int sum[maxn][4];
	inline void clear()
	{
		memset(sum,0,sizeof(sum));
	}
	inline void pushup(int u)
	{
		FOR(i,0,3)sum[u][i]=sum[ls][i]+sum[rs][i];
	}
	inline void update(int u,int l,int r,int x,int v)
	{
		if(l==r)return memset(sum[u],0,sizeof(sum[u])),sum[u][v]=1,void();
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,v);
		else update(rs,mid+1,r,x,v);
		pushup(u);
	}
	inline int query(int u,int l,int r,int x,int y,int t)
	{
		if(x<=l&&y>=r)return sum[u][t];
		int mid=(l+r)>>1,ret=0;
		if(x<=mid)ret=query(ls,l,mid,x,y,t);
		if(y>mid)ret+=query(rs,mid+1,r,x,y,t);
		return ret;
	}
}tree[10];
const int maxn=1e5+5;
char s[maxn];
int Q,n;
struct query
{
	int typ,x,l,r;
	char c;
	string t;
}q[maxn];
int ans[maxn],mp[10000];
inline void init()
{
	
}
inline void input()
{	
	scanf("%s",s+1);
	n=strlen(s+1);Q=gi();
	FOR(i,1,Q)
	{
		q[i].typ=gi();
		if(q[i].typ==1)q[i].x=gi(),cin>>q[i].t,q[i].c=q[i].t[0];
		else
		{
			q[i].l=gi(),q[i].r=gi();
			cin>>q[i].t;
		}
	}
	mp['A']=0,mp['T']=1,mp['G']=2,mp['C']=3;
}
inline void solve()
{
	FOR(i,1,10)
	{
		FOR(j,0,i-1)tree[j].clear();
		FOR(j,1,n)tree[j%i].update(1,1,n,j,mp[(int)s[j]]);
		FOR(j,1,Q)
		{
			if(q[j].typ==1)tree[q[j].x%i].update(1,1,n,q[j].x,mp[(int)q[j].c]);
			else if(sz(q[j].t)==i)
			{
				int l=q[j].l,r=q[j].r;
				FOR(k,0,sz(q[j].t)-1)
				{
					ans[j]+=tree[(l+k)%i].query(1,1,n,l,r,mp[(int)q[j].t[k]]);
				}
			}
		}
	}
	FOR(i,1,Q)if(q[i].typ==2)printf("%d\n",ans[i]);
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}