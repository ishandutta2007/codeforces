#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using vi=vector<int>;
using pii=pair<int,int>;
using pll=pair<i64,i64>;

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

const int N=10010,MOD=998244353;

vi e[N],_e[N];
int n,m,a[N],seq[N];

void topo(){
    static int in[N];
    for(int x=1;x<=n;x++) in[x]=_e[x].size();
    queue<int> q;int ti=0;
    for(int x=1;x<=n;x++)
        if(!in[x]) q.push(x);
    while(!q.empty()){
        int x=q.front();q.pop();
        seq[++ti]=x;
        for(auto y:e[x])
            if(!(--in[y])) q.push(y);
    }
}

struct Num{
    i64 x;bool v;
    Num(i64 x=0,bool v=0):x(x%MOD),v((x>=MOD)||v){}
    Num operator + (const Num &b) const{
        return {x+b.x,v||b.v};
    }
    Num operator - (i64 b) const{
        if(!v) return x-b;
        else return {(x-b+MOD)%MOD,v};
    }
    bool operator < (i64 b) const{
        return v?false:x<b;
    }
    bool operator < (Num b) const{
        return false;
    }
};

vector<pair<i64,Num>> t[N];
void doit(){
    for(int i=1;i<=n;i++){
        int x=seq[i];
        vector<pair<i64,Num>> tmp;
        if(a[x]) tmp.pb({0,a[x]-1});
        for(auto y:_e[x])
            tmp.insert(tmp.end(),t[y].begin(),t[y].end());
        sort(tmp.begin(),tmp.end());
        i64 L=0;Num sum(0);
        for(auto cur:tmp){
            if(!sum.v&&(!L||sum+Num(L-1)<cur.fi)){
                if(L) t[x].pb({L,sum+Num(L-1)});
                L=cur.fi+1,sum=cur.se-(cur.fi-1);
            }
            else sum=sum+(cur.se-(cur.fi-1));
        }
        if(L) t[x].pb({L,sum+Num(L-1)});
    }
    i64 ans=0;
    if(t[seq[n]].empty()) ans=0;
    else ans=t[seq[n]].back().se.x;
    cout<<(ans%MOD)<<'\n';
}

void clear(){
    for(int i=1;i<=n;i++) t[i].clear(),e[i].clear(),_e[i].clear();
}

void solve(){
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),_e[y].pb(x);
    }
    topo();doit();
    clear();
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