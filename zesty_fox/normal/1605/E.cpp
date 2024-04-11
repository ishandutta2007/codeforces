#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=200010;

int n,a[N],b[N],q;

int v[N],p[N],pcnt,mu[N];
void init(int lim){
    mu[1]=1;
    for(int i=2;i<=lim;i++){
        if(!v[i]) {v[i]=i,p[++pcnt]=i,mu[i]=-1;}
        for(int j=1;j<=pcnt;j++){
            if(p[j]>v[i]||p[j]>lim/i) break;
            v[p[j]*i]=p[j],mu[p[j]*i]=(i%p[j]?-mu[i]:0);
        }
    }
}

ll d[N],sum[N],f[N];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();init(n);
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<=n;i++) b[i]=rdi();

    for(int i=2;i<=n;i++)
        for(int j=i;j<=n;j+=i) d[j]+=(a[i]-b[i])*mu[j/i];
    int cnt=0;ll sum0=0;
    for(int i=2;i<=n;i++){
        if(!mu[i]) {sum0+=abs(d[i]);continue;}
        if(mu[i]<0) d[i]=-d[i];
        f[++cnt]=d[i];
    }

    sort(f+1,f+cnt+1);
    for(int i=1;i<=cnt;i++) sum[i]=sum[i-1]+f[i];
    
    q=rdi();
    while(q--){
        int x=a[1]-rdi();
        int pos=lower_bound(f+1,f+cnt+1,-x)-f;
        ll res=1ll*(cnt-pos+1)*x+sum[cnt]-sum[pos-1]-1ll*(pos-1)*x-sum[pos-1]+abs(x)+sum0;
        printf("%lld\n",res);
    }
    return 0;
}