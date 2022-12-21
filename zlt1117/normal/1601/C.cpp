#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define gc getchar()
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=1e6+5;
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=4e6+5;
	int minv[maxn],tag[maxn];
	inline void pushdown(int u)
	{
		if(tag[u])
		{
			tag[ls]+=tag[u];
			tag[rs]+=tag[u];
			minv[ls]+=tag[u];
			minv[rs]+=tag[u]; 
			tag[u]=0;
		}
	}
	inline void pushup(int u)
	{
		minv[u]=min(minv[ls],minv[rs]);
	}
	inline void update(int u,int l,int r,int x,int y,int v)
	{
		if(x<=l&&y>=r)return minv[u]+=v,tag[u]+=v,void();
		pushdown(u);
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,y,v);
		if(y>mid)update(rs,mid+1,r,x,y,v);
		pushup(u);
	}
}tree;
int a[maxn],b[maxn],c[maxn],n,m;
ll ans;
vector<pair<int,int>>v;
inline void merge_sort(int l,int r)
{
    int p1,p2,p,mid;
    if(l==r)return ;
    mid=(l+r)>>1;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    p1=l,p2=mid+1,p=0;
    while(p1<=mid||p2<=r)
    {
        if(p1<=mid&&(p2>r||a[p1]<=a[p2]))
        {
            c[++p]=a[p1];
       		p1++;
        }
        else
        {
            c[++p]=a[p2];
            p2++;
            ans+=mid-p1+1;
        }
    }
    for(int i=1;i<=p;++i)a[l+i-1]=c[i];
}
inline void init()
{
	ans=0;
	FOR(i,1,n)a[i]=b[i]=c[i]=0;
	memset(tree.tag,0,sizeof(int)*(4*n+1));
	memset(tree.minv,0,sizeof(int)*(4*n+1));
	v.clear();
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,m)b[i]=gi();
}
inline void solve()
{
	v.clear();
	sort(b+1,b+m+1);
	FOR(i,1,n)v.pb({a[i],i});
	sort(v.begin(),v.end());
	int p1=0,p2=0,sum=0;
	FOR(i,1,n)tree.update(1,1,n,i,n,1);
	FOR(i,1,m)
	{
		while(p1<n&&v[p1].first<b[i])sum++,p1++;
		while(p2<n&&v[p2].first<b[i])tree.update(1,1,n,v[p2].second,n,-2),p2++;
		while(p2<n&&v[p2].first<=b[i])tree.update(1,1,n,v[p2].second,n,-1),p2++;
		int nowans=0;
		nowans=min(nowans,tree.minv[1])+sum;
		ans+=nowans;
		if(i==m||b[i+1]!=b[i])while(p1<n&&p1<p2)sum++,tree.update(1,1,n,v[p1].second,n,-1),p1++;
	}
	merge_sort(1,n);
	printf("%lld\n",ans);
}
int main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}