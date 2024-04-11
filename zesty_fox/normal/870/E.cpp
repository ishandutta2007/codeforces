// LUOGU_RID: 90802602
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int N=4e5+10,MOD=1e9+7;

struct Dsu{
    int f[N],siz[N],cnte[N];
    void init(int n){
        for(int i=1;i<=n;i++)
            f[i]=i,siz[i]=1,cnte[i]=0;
    }
    int find(int x) {return x==f[x]?f[x]:f[x]=find(f[x]);}
    void merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y) {cnte[x]++;return;}
        f[y]=x,siz[x]+=siz[y],cnte[x]+=cnte[y]+1;
    }
}d;

int n,X[N],Y[N];

vi lsh;
int tot;
void discrete(){
    for(int i=1;i<=n;i++) lsh.pb(X[i]),lsh.pb(Y[i]);
    sort(lsh.begin(),lsh.end());
    lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end()),tot=lsh.size();
    auto upd = [&](int &x) {x=lower_bound(lsh.begin(),lsh.end(),x)-lsh.begin()+1;};
    for(int i=1;i<=n;i++) upd(X[i]),upd(Y[i]);
}

i64 pw2[N];
void solve(){
    pw2[0]=1;
    for(int i=1;i<=2*n;i++)
        pw2[i]=pw2[i-1]*2%MOD;
    discrete();d.init(tot*2);
    for(int i=1;i<=n;i++)
        d.merge(X[i],Y[i]+tot);
    i64 ans=1;
    for(int i=1;i<=2*tot;i++){
        if(d.find(i)!=i||d.siz[i]<=1) continue;
        ans=ans*(d.cnte[i]>=d.siz[i]?pw2[d.siz[i]]:(pw2[d.siz[i]]-1))%MOD;
    }
    cout<<ans<<endl;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++) X[i]=rdi(),Y[i]=rdi();
    solve();
    return 0;
}