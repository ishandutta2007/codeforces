#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=1000010,INF=0x3f3f3f3f;

int n,m,a[N],minx[N],flg[N];

void solve(){
    n=rdi(),m=rdi();ll sum=0;
    for(int i=1;i<=n;i++) a[i]=rdi(),sum+=abs(a[i]);
    int len=0;
    for(int i=1;i<=m;i++) len=__gcd(len,rdi());

    for(int i=0;i<len;i++) minx[i]=INF,flg[i]=0;
    for(int i=1;i<=n;i++){
        int typ=i%len;
        if(a[i]<0) flg[typ]^=1;
        minx[typ]=min(minx[typ],abs(a[i]));
    }

    ll sum1=0,sum2=0;
    for(int i=0;i<len;i++){
        if(flg[i]) sum1+=minx[i];
        else sum2+=minx[i];
    }
    cout<<sum-2*min(sum1,sum2)<<'\n';
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}