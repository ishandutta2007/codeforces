#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define rd (rand()<<16^rand())
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=5e5+5,maxt=5e5;
int n,k,q,x,y,typ[maxn];
struct state
{
	int x,y,sizx;
	state(int xx=0,int yy=0,int ss=0){x=xx,y=yy,sizx=ss;}
};
int fa[maxn],siz[maxn];
stack<state>stk;
vector<PII>que[maxn];
int ans[maxn];
inline int get(int x){if(x==fa[x])return x;else return get(fa[x]);}
inline void merge(int x,int y)
{
	x=get(x),y=get(y);
	if(x==y)return ;
	if(siz[x]>siz[y])swap(x,y);
	fa[x]=y;
	siz[y]+=siz[x];
	stk.push(state(x,y,siz[x]));
}
inline void del()
{
	int x=stk.top().x,y=stk.top().y,sizx=stk.top().sizx;
	siz[y]-=sizx;fa[x]=x;
}
struct segmentree
{
	static const int maxn=2e6+5;
	#define ls u<<1
	#define rs u<<1|1
	vector<PII>vec[maxn];
	inline void update(int u,int l,int r,int x,int y,int xx,int yy)
	{
		if(x<=l&&y>=r)return vec[u].pb(PII(xx,yy)),void();
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,y,xx,yy);
		if(y>mid)update(rs,mid+1,r,x,y,xx,yy);
	}
	inline void dfs(int u,int l,int r)
	{
		int cnt=stk.size();
		for(auto x:vec[u])merge(x.first,x.second);
		if(l==r)
		{
			for(auto x:que[l])
			ans[x.first]=siz[get(x.second)];
		}
		else
		{
			int mid=(l+r)>>1;
			dfs(ls,l,mid);
			dfs(rs,mid+1,r);
		}
		while(stk.size()>cnt)del(),stk.pop();
	}
}tree;
int a[maxn],b[maxn],cur[maxn];
int temp[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),q=gi(),k=gi();
	int now=1;
	int counter=0;
	FOR(i,1,n)fa[i]=i,siz[i]=1;
	FOR(i,1,q)
	{
		typ[i]=gi();
		if(typ[i]==1)
		{
			a[i]=gi(),b[i]=gi();
			cur[i]=now;
			//tree.update(1,1,q,i,min(maxt,now+k-1),x,y);
		}
		else if(typ[i]==2)
		{
			int x=gi();
			que[i].pb(PII(++counter,x));
		}
		else now++,temp[now]=i;
	}
	FOR(i,1,q)
	{
		if(cur[i]+k>now)tree.update(1,1,q,i,q,a[i],b[i]);
		else tree.update(1,1,q,i,temp[cur[i]+k],a[i],b[i]);
	}
	tree.dfs(1,1,q);
	FOR(i,1,counter)printf("%d\n",ans[i]);
}
inline void solve()
{

}
int main()
{
	init();
	input();
	solve();
	return 0;
}///the relative order should be pay attention