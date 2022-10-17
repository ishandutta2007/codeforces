#include<bits/stdc++.h>
#define ll long long
#define N 100100
#define M 1000000007
using namespace std;

ll n,m,ji,cnt[60],jc[N],nj[N],dp[N],ans[60][60];
char str[N];

inline ll zh(char u){return u<='Z'?u-'A':u-'a'+26;}
inline ll C(ll u,ll v){return jc[u]*nj[v]%M*nj[u-v]%M;}
inline void Add(ll &u,ll v){u=(u+v)%M;}
inline ll po(ll u,ll v)
{
    ll res=1;
    for(;v;)
    {
	if(v&1) res=res*u%M;
	u=u*u%M;
	v>>=1;
    }
    return res;
}

inline void in(ll u)
{
    ll i,j;
    for(i=(n>>1);i>=u;i--)
    {
	Add(dp[i],dp[i-u]);
    }
}

inline void out(ll u)
{
    ll i,j;
    for(i=u;i<=(n>>1);i++)
    {
	Add(dp[i],M-dp[i-u]);
    }
}

int main()
{
    ll i,j,p,q;
    scanf("%s",str+1);
    n=strlen(str+1);
    jc[0]=1;for(i=1;i<=n;i++) jc[i]=jc[i-1]*i%M;
    nj[n]=po(jc[n],M-2);for(i=n-1;i>=0;i--) nj[i]=nj[i+1]*(i+1)%M;
    for(i=1;i<=n;i++) cnt[zh(str[i])]++;
    ji=2*jc[n>>1]*jc[n>>1]%M;for(i=0;i<52;i++) ji=ji*nj[cnt[i]]%M;
//    cout<<" "<<ji<<endl;
    dp[0]=1;
    for(i=0;i<52;i++)
    {
	if(!cnt[i]) continue;
	in(cnt[i]);
    }
    for(i=0;i<52;i++)
    {
	if(!cnt[i]) continue;
	out(cnt[i]);
	for(j=i;j<52;j++)
	{
	    if(!cnt[j]) continue;
	    if(i!=j) out(cnt[j]);
	    ans[i][j]=dp[n>>1]*ji%M;
	    if(i!=j) in(cnt[j]);
	}
	in(cnt[i]);
    }
    cin>>m;
    for(i=1;i<=m;i++)
    {
	scanf("%lld%lld",&p,&q);
	p=zh(str[p]),q=zh(str[q]);
	if(p>q) swap(p,q);
	printf("%lld\n",ans[p][q]);
    }
}