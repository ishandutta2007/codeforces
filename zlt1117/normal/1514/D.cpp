#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++;
#define iter set<int>::iterator
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=3e5+5,block=400;
int cnt[maxn];
int n,Q,a[maxn];
int b[maxn],bel[maxn],posl[maxn],posr[maxn],tot;
int temp[maxn],ans[maxn];
struct queries
{
	int id,l,r;
	inline bool operator < (const queries &b)const
	{
		if(bel[l]==bel[b.l])return r<b.r;
		else return bel[l]<bel[b.l];
	}
}q[maxn];
inline void input()
{
	n=gi(),Q=gi();
	FOR(i,1,n)b[i]=a[i]=gi();
	FOR(i,1,Q)q[i].id=i,q[i].l=gi(),q[i].r=gi();
	FOR(i,1,n)bel[i]=(i-1)/block+1;
	while(posr[tot]<n)++tot,posl[tot]=posr[tot-1]+1,posr[tot]=min(n,posl[tot]+block-1);
	sort(q+1,q+Q+1);
	sort(b+1,b+n+1);
	int t=unique(b+1,b+n+1)-b-1;
	FOR(i,1,n)a[i]=lower_bound(b+1,b+t+1,a[i])-b;
}
inline int count(int l,int r,int now)
{
	if(now<=(r-l+2)/2)return 1;
	int res=r-l+1-now;
	if(res*2<=now)return now-res;
	else return now-res;
}
inline int brute(int l,int r)
{
	int ans=0;
	FOR(i,l,r)temp[a[i]]++,ans=max(ans,temp[a[i]]);
	FOR(i,l,r)temp[a[i]]--;
	return ans;
}
int nowans;
int l=1,r=0;
inline void solve()
{
	int last=0;
	FOR(i,1,Q)
	{
		if(bel[q[i].l]==bel[q[i].r]){ans[q[i].id]=count(q[i].l,q[i].r,brute(q[i].l,q[i].r));continue;}
		if(bel[q[i].l]!=last)
		{
			memset(cnt,0,sizeof(cnt));nowans=0;
			l=posr[bel[q[i].l]],r=l-1;
			last=bel[q[i].l];
		}
		while(r<q[i].r)cnt[a[++r]]++,nowans=max(nowans,cnt[a[r]]);
		int res=nowans;
		int nl=l;
		while(nl>q[i].l)cnt[a[--nl]]++,nowans=max(nowans,cnt[a[nl]]);
		ans[q[i].id]=count(q[i].l,q[i].r,nowans);
		while(nl<l)cnt[a[nl]]--,nl++;
		nowans=res;///!!!
	}
	FOR(i,1,Q)printf("%d\n",ans[i]);
}
int main()
{
	input();
	solve();
	return 0;
}