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

const int N=4e5+10;

struct Dsu{
    int f[N];
    void init(int n) {iota(f+1,f+n+1,1);}
    int find(int x) {return x==f[x]?f[x]:f[x]=find(f[x]);}
    void merge(int x,int y) {f[find(y)]=find(x);}
}d;

int n,ma[N];
char s[N];

void dfs(int l,int r){
    if(l>r) return;
    for(int i=l;i<=r;){
        d.merge(i,l);
        dfs(i+1,ma[i]-1);
        i=ma[i]+1;
    }
}

void solve(){
    n=rdi();
    scanf("%s",s+1);
    d.init(2*n);
    static int st[N];int tp=0;
    for(int i=1;i<=2*n;i++){
        if(s[i]=='(') st[++tp]=i;
        else ma[i]=st[tp],ma[st[tp]]=i,d.merge(i,ma[i]),--tp;
    }
    dfs(1,2*n);int ans=0;
    for(int i=1;i<=2*n;i++) ans+=d.find(i)==i;
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