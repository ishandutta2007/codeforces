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
const int maxn=2e5+5;
struct segmentree
{
	static const int maxn=8e6+5;
	int sum[maxn],ls[maxn],rs[maxn],tot;
	inline void pushup(int u){sum[u]=sum[ls[u]]+sum[rs[u]];}
	inline void update(int &u,int l,int r,int x,int v)
	{
		int t=u;u=++tot;
		if(l==r)return sum[u]=v,void();
		int mid=(l+r)>>1;
		ls[tot]=ls[t],rs[tot]=rs[t];
		if(x<=mid)update(ls[u],l,mid,x,v);
		else update(rs[u],mid+1,r,x,v);
		pushup(u);
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(!u)return 0;
		if(x<=l&&y>=r)return sum[u];
		int mid=(l+r)>>1,ret=0;
		if(x<=mid)ret+=query(ls[u],l,mid,x,y);
		if(y>mid)ret+=query(rs[u],mid+1,r,x,y);
		return ret;
	}
}tree;
set<int>S;
int ans[maxn];
int t[maxn],l[maxn],r[maxn],x[maxn],n,Q;
inline void init()
{

}
int rt[maxn];
inline void input()
{
	memset(ans,-1,sizeof(ans));
	n=gi(),Q=gi();
	FOR(i,1,n)tree.update(rt[0],1,n,i,1);
	set<int>S;FOR(i,1,n)S.insert(i);
	FOR(i,1,Q)
	{
		t[i]=gi();
		if(t[i]==0)l[i]=gi(),r[i]=gi();
		x[i]=gi();rt[i]=rt[i-1];
		if(t[i]==0&&x[i]==0)
		{
			auto it=S.lower_bound(l[i]);
			while(it!=S.end())
			{
				if((*it)<=r[i])tree.update(rt[i],1,n,(*it),0),S.erase(it++);
				else break;
			}
		}
		if(t[i]==1)if(tree.query(rt[i],1,n,x[i],x[i])==0)ans[i]=0;
	}
}
vector<int>sick[maxn];
inline void solve()
{
	FOR(i,1,Q)
	{
		if(t[i]==0&&x[i]==1)
		{
			int l=i,r=Q,ans=n,L=::l[i],R=::r[i];
			if(tree.query(rt[Q],1,n,L,R)!=1)continue;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(tree.query(rt[mid],1,n,L,R)==1)ans=mid,r=mid-1;
				else l=mid+1;
			}
			int ret=R;
			while(L<=R)
			{
				int mid=(L+R)>>1;
				if(tree.query(rt[ans],1,n,L,mid))ret=mid,R=mid-1;
				else L=mid+1;
			}
			sick[ans].pb(ret);
		}
	}
	set<int>sicks;
	FOR(i,1,Q)
	{
		for(int x:sick[i])sicks.insert(x);//,cerr<<i<<' '<<x<<endl;
		if(t[i]==1)
		{
			if(sicks.count(x[i]))ans[i]=1;
			if(ans[i]==-1)puts("N/A");
			else if(ans[i]==0)puts("NO");
			else puts("YES");
		}
	}
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