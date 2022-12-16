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

int n,a[N],suf[N];
vi b;

int vis[N],pos;

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    pos=0;
    for(int i=n;i>=1;i--){
        vis[a[i]]=1;
        while(vis[pos]) pos++;
        suf[i]=pos;
    }
    for(int i=0;i<=n;i++) vis[i]=0;
    int p=1,last=1;pos=0;
    for(;p<=n;){
        vis[a[p++]]=1;
        while(vis[pos]) pos++;
        while(p<=n&&pos<suf[last]){
            vis[a[p++]]=1;
            while(vis[pos]) pos++;
        }
        b.pb(pos),pos=0;
        for(int i=last;i<=p;i++) vis[a[i]]=0;
        last=p;
    }
    cout<<b.size()<<'\n';
    for(auto x:b) cout<<x<<' ';
    cout<<'\n';

    b.clear();
    for(int i=0;i<=n;i++) suf[i]=vis[i]=0;
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}