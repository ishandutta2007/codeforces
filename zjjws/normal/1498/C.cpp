#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define rep_(i,a,b) for(int i=(a);i<(b).size();++i)
#define F(a) rep(a,1,n)
#define M(a,b) memset(a,b,sizeof a)
#define DC int T;cin>>T;while(T--)
#define ll long long
#define Z(a,b) sort(a+1,a+b+1)
using namespace std;
const unsigned _mod=998244353;
const unsigned mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(auto &x){x=0;int f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y>0){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
ll n,m,f[1010][1010],sum[1010][1010];
int main()
{
    DC
    {
        cin>>n>>m;
        ll k=1;
        rep(i,1,n+1) f[k][i]=1;
	    rep(i,1,n+1) sum[k][i]=(i!=1?sum[k][i-1]:0)+f[k][i],sum[k][i]-=(sum[k][i]>=mod)*mod;
	    rep(i,k+1,m)
	    {
	    	rep(j,0,n<<1) f[i][j/2+1]=sum[i-1][n]-sum[i-1][n-j/2]+mod+1,f[i][j/2+1]-=(f[i][j/2+1]>=mod)*mod,f[i][j/2+1]-=(f[i][j/2+1]>=mod)*mod,j++;
	    	rep(j,0,n<<1) sum[i][j/2+1]=(f[i][j/2+1]+sum[i][j/2])%mod,sum[i][j/2+1]-=(sum[i][j/2+1]>=mod)*mod,j++;
	    }
	    cout<<f[m][n+(n!=0)]<<'\n';
    }
    return 0;    
}