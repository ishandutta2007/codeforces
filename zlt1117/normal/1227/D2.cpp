//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2e5+5;
struct node
{
	int val,pos;
	inline bool operator<(const node &b)const
	{
		if(val!=b.val)return val<b.val;
		else return pos>b.pos;
	}
};
priority_queue<node>pq;
set<int>s;
int a[maxn],ans[maxn];
int n,m,k,pos;
vector<PII>vec[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),pq.push(node{a[i],i});
	m=gi();
	FOR(i,1,m)
	{
		k=gi(),pos=gi();
		vec[k].pb(PII(i,pos));
	}
}
int c[maxn];
inline void update(int x)
{
	while(x<=n)
	{
		c[x]++;
		x+=x&-x;
	}
}
inline int query(int x)
{
	int ret=0;
	while(x)
	{
		ret+=c[x];
		x-=x&-x;	
	}
	return ret;
}
inline void solve()
{
	FOR(i,1,n)
	{
		int x=pq.top().pos;
		pq.pop();
		update(x);
		for(auto x:vec[i])
		{
			int id=x.first,pos=x.second;
			int l=1,r=n,ans1=0;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				int val=query(mid);
				if(val>=pos)ans1=mid,r=mid-1;
				else l=mid+1;
			}
			ans[id]=a[ans1];
		}
	}
	FOR(i,1,m)printf("%d\n",ans[i]);
}
int main()
{
//	T=gi();
//	while(T--)
//	{
		init();
		input();
		solve();
//	}
	return 0;
}