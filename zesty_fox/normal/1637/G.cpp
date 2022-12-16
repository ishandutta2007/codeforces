// LUOGU_RID: 95196258
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

const int N=5e4+10;

vector<pii> res;
int p[N],pos[N],n;

void op(int x,int y){
    res.pb({p[x],p[y]});
    tie(p[x],p[y])=make_pair(p[x]+p[y],abs(p[x]-p[y]));
}

void process(int pos[],int n){
    if(n<=2) return;
    if(!(n&(n-1))) return process(pos,n-1);
    int p=1<<__lg(n);
    for(int i=1;i<=n-p;i++) op(pos[p+i],pos[p-i]);
    process(pos,2*p-n-1);
    reverse(pos+2*p-n,pos+p),process(pos+2*p-n-1,n-p);
}

void m2(int x,int p) {op(x,p),op(x,p);}

void solve(){
    n=rdi();
    if(n==2) {puts("-1");return;}
    for(int i=1;i<=n;i++) p[i]=pos[i]=i;
    process(pos,n);
    int to=(1<<(__lg(n-1)+1));
    int p1,p2;
    for(int v=1;v<to;v<<=1){
        p1=find(p+1,p+n+1,v)-p;
        if(p1<=n){
            p2=find(p+p1+1,p+n+1,v)-p;
            if(p2<=n) break;
        }
    }
    op(p1,p2);
    for(int i=1;i<=n;i++){
        if(i==p2) continue;
        while(p[i]<to) m2(i,p2);
    }
    op(p2,(p2==n?p2-1:p2+1));
    cout<<res.size()<<'\n';
    for(auto [x,y]:res) cout<<x<<' '<<y<<'\n';
    res.clear();
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}