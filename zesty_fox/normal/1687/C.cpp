#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010;

int n,m;
i64 a[N];
vi L[N],R[N];

struct Dsu{
    int f[N];
    void init(int n) {iota(f+1,f+n+1,1);}
    int find(int x) {return x==f[x]?f[x]:f[x]=find(f[x]);}
}d;

void solve(){
    n=rdi(),m=rdi();d.init(n);
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<=n;i++) a[i]-=rdi(),a[i]+=a[i-1];
    for(int i=1;i<=m;i++){
        int l=rdi()-1,r=rdi();
        R[l].pb(r),L[r].pb(l);
    }
    queue<int> q;d.init(n+1);
    for(int i=0;i<=n;i++) 
        if(!a[i]) d.f[i]=i+1,q.push(i);
    while(!q.empty()){
        int X=q.front();q.pop();
        for(auto r:R[X]){
            if(d.find(r)!=r){
                for(int x=d.find(X+1);x<=r;x=d.find(x+1)) 
                    q.push(x),d.f[x]=x+1;
            }
        }
        for(auto l:L[X]){
            if(d.find(l)!=l){
                for(int x=d.find(l);x<X;x=d.find(x+1)) 
                    q.push(x),d.f[x]=x+1;
            }
        }
    }
    bool ret=true;
    for(int i=1;i<=n;i++) if(d.find(i)!=n+1) ret=false;
    puts(ret?"YES":"NO");
    for(int i=0;i<=n+1;i++) L[i].clear(),R[i].clear(),a[i]=0,d.f[i]=0;
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