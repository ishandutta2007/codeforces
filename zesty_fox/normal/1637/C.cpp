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

const int N=100010;

int n,a[N];

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();

    if(n==3&&(a[2]&1)) return (void)puts("-1");
    bool flg=0;
    for(int i=2;i<n;i++) flg|=(a[i]>1);
    if(!flg) return (void)puts("-1"); 

    ll ans=0,cnt=0;flg=0;
    for(int i=2;i<n;i++){
        if(a[i]&1) cnt++,ans+=a[i]/2;
        else flg=1,ans+=a[i]/2;
    }
    ans+=cnt;
    cout<<ans<<'\n';
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}