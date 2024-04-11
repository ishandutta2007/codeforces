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

const int N=2010;

int n,a[N];
void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    int mx=-1e9;
    for(int i=1;i<=n;i++) mx=max(mx,a[i]-a[i%n+1]);
    if(n>1) mx=max({mx,*max_element(a+2,a+n+1)-a[1],a[n]-*min_element(a+1,a+n)});
    cout<<mx<<'\n';
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