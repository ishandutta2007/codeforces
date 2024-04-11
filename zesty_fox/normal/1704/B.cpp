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

int n,x,a[N];
void solve(){
    n=rdi(),x=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    int L=-1e9,R=2e9,ans=0;
    for(int i=1;i<=n;i++){
        int l=a[i]-x,r=a[i]+x;
        L=max(L,l),R=min(R,r);
        if(L>R) L=l,R=r,ans++;
    }
    cout<<ans<<'\n';
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