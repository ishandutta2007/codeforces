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

const int N=2e5+10;

int n,k,p[N];
i64 s[N];
vi t[N];

map<i64,i64> f[N];
i64 dfs(int x,i64 k){
    if(!k) return 0;
    if(f[x].find(k)!=f[x].end()) return f[x][k];
    i64 ret=k*s[x];
    int d=t[x].size();
    if(!d) return ret;
    i64 bas=k/d,cnt=k%d;
    vector<i64> w;
    for(auto y:t[x]){
        i64 tmp=dfs(y,bas);ret+=tmp;
        if(cnt) w.pb(dfs(y,bas+1)-tmp);
    }
    sort(w.begin(),w.end(),greater<>());
    for(int i=0;i<cnt;i++) ret+=w[i];
    return f[x][k]=ret;
}

void solve(){
    n=rdi(),k=rdi();
    for(int i=2;i<=n;i++){
        p[i]=rdi();
        t[p[i]].pb(i);
    }
    for(int i=1;i<=n;i++) s[i]=rdi();
    cout<<dfs(1,k)<<'\n';
    for(int i=1;i<=n;i++) 
        t[i].clear(),f[i].clear();
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