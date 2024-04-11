#include <bits/stdc++.h>

using namespace std;

using i64=long long;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=200010;

int n;
i64 k;
i64 a[N],sum[N];

void solve(){
    n=rdi(),k=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi(),sum[i]=sum[i-1]+a[i];
    i64 ans=0;
    if(k<=n){
        for(int l=1,r=k;r<=n;l++,r++)
            ans=max(ans,sum[r]-sum[l-1]+k*(k-1)/2);
    }
    else{
        ans=sum[n]+n*(k-1+k-n)/2;
    }
    cout<<ans<<endl;
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