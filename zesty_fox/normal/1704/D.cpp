#include <bits/stdc++.h>
#include <iterator>
#include <numeric>

using namespace std;

using i64=long long;
using i128=__int128_t;
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

const int N=100010;

int n,m;
pair<i128,int> sum[N];
vector<i64> c[N];
void solve(){
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++){
        c[i].clear();
        for(int j=1;j<=m;j++) c[i].pb(rdi64());
    }
    for(int i=1;i<=n;i++){
        i128 s=0;sum[i]={0,i};
        for(auto x:c[i]) s+=x,sum[i].fi+=s;
    }
    sort(sum+1,sum+n+1);
    cout<<sum[1].se<<' '<<(i64)(sum[2].fi-sum[1].fi)<<'\n';
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