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

const int N=1e5+10;

int n;
pii a[N];
i64 ans;
void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i].se=rdi();
    for(int i=1;i<=n;i++) a[i].fi=rdi();
    vi v[2];
    for(int i=1;i<=n;i++) v[a[i].se].pb(a[i].fi);
    sort(v[0].begin(),v[0].end(),greater<int>()),sort(v[1].begin(),v[1].end(),greater<int>());
    int siz[2]={(int)v[0].size(),(int)v[1].size()};i64 ans=0;
    for(int st=0;st<2;st++){
        i64 sum=0;
        if(v[st].empty()) continue;
        sum+=v[st].back(),siz[st]--;
        int p[2]={0,0},lst=st;
        while(p[0]<siz[0]||p[1]<siz[1]){
            if(p[lst^1]==siz[lst^1]) sum+=v[lst][p[lst]++];
            else lst^=1,sum+=v[lst][p[lst]++]*2;
        }
        siz[st]++;
        ans=max(ans,sum);
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