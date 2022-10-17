#include<bits/stdc++.h>
#define ll long long
#define S 410
#define N 100100
#define M 998244353
using namespace std;

ll n,m,s,num[N],ad[S],pos[N],last[N],dp[N],ans[S],cnt[N];
int sum[S][N];

inline ll get(ll u){return u/s+1;}
template<class T,class TT>inline void Add(T &u,TT v){u=((ll)u+v)%M;}

inline void chg(ll u,ll v)
{
    ll t=get(u);
    Add(sum[t][cnt[u]],M-dp[u]);
    if(cnt[u]+ad[t]<=m) Add(ans[t],M-dp[u]);
    cnt[u]+=v;
    Add(sum[t][cnt[u]],dp[u]);
    if(cnt[u]+ad[t]<=m) Add(ans[t],dp[u]);
}

inline void add(ll u,ll v,ll w)
{
    if(u>v) return;
//    cerr<<u<<' '<<v<<" "<<w<<endl;
    ll i,p=get(u),q=get(v);
    if(p==q)
    {
	for(i=u;i<=v;i++)
	{
	    chg(i,w);
	}
	return;
    }
    for(i=u;get(i)==p;i++) chg(i,w);
    for(i=v;get(i)==q;i--) chg(i,w);
    for(i=p+1;i<q;i++)
    {
	if(w>0) if(m-ad[i]>=0) Add(ans[i],M-sum[i][m-ad[i]]);
	ad[i]+=w;
	if(w<0) if(m-ad[i]>=0) Add(ans[i],sum[i][m-ad[i]]);
    }
}

int main()
{
    ll i,j,t;
    cin>>n>>m;
    s=sqrt(n);
    for(i=1;i<=n;i++)
    {
	scanf("%lld",&num[i]);
    }
    dp[0]=sum[1][0]=ans[1]=1;
    for(i=1;i<=n;i++)
    {
	last[i]=pos[num[i]];
	add(last[last[i]],last[i]-1,-1);
	add(last[i],i-1,1);
//	printf(" ");for(j=1;j<=get(n);j++) cout<<ans[j]<<' ';puts("");
	for(t=get(i),j=i-1;j>=0&&get(j)==t;j--) if(cnt[j]+ad[t]<=m) Add(dp[i],dp[j]);
	for(j=t-1;j>=1;j--) Add(dp[i],ans[j]);
	Add(sum[t][0],dp[i]);
	if(ad[t]<=m) Add(ans[t],dp[i]);
	pos[num[i]]=i;
//	cerr<<i<<" "<<dp[i]<<endl;
    }
    cout<<dp[n];
}