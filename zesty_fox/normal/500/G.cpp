#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010,L=19;
const i64 INFl=0x3f3f3f3f3f3f3f3f;

int n;
vi e[N];

inline int lg2(int x) {return !x?-1:__lg(x);}

int f[N][L],dep[N];
void dfs(int x,int fa){
    dep[x]=dep[fa]+1,f[x][0]=fa;
    for(int i=1;i<=lg2(dep[x]);i++) f[x][i]=f[f[x][i-1]][i-1];
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y,x);
    }
}

inline int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=lg2(dep[x]-dep[y]);i>=0;i--)
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=lg2(dep[x]);i>=0;i--)
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}

inline int dist(int x,int y) {return dep[x]+dep[y]-2*dep[lca(x,y)];}
inline bool on(int x,int y,int z) {return dist(x,z)+dist(z,y)==dist(x,y);}

pii intersect(pii a,pii b){
    int lc[4]={lca(a.fi,b.se),lca(a.se,b.fi),lca(a.se,b.se),lca(a.fi,b.fi)};
    sort(lc,lc+4,[&](int x,int y){return dep[x]>dep[y];});
    int x=lc[0],y=lc[1];
    if(on(a.fi,a.se,x)&&on(b.fi,b.se,x)&&on(a.fi,a.se,y)&&on(b.fi,b.se,y)) return {x,y};
    else return {0,0};
}

i64 exgcd(i64 a,i64 b,i64 &x,i64 &y){
    if(!b) {x=1,y=0;return a;}
    i64 d=exgcd(b,a%b,x,y);
    i64 z=x;x=y;y=z-(a/b)*y;
    return d;
}

void calc(i64 L,i64 R,i64 A,i64 P,i64 &x,i64 &y){
    if(!A) {x=0,y=0;return;}
    auto fdiv = [&](i64 x,i64 y){return x>0?x/y:-((-x+y-1)/y);};
    auto cdiv = [&](i64 x,i64 y){return x>0?(x+y-1)/y:x/y;};
    i64 d1=cdiv(L,A),d2=fdiv(R,A);
    if(d1<=d2) {x=d1,y=0;return;}
    i64 L1=(A-R%A)%A,R1=(A-L%A)%A;
    calc(L1,R1,P%A,A,x,y);
    i64 x1=x;x=y+(L1+R)/A+x*(P/A),y=x1;
}

int tim(int x,int y,int c1,int c2){
    int d1=dist(x,c1),d2=dist(x,c2);
    if(d1<=d2) return d1;
    else return 2*dist(x,y)-d1;
}

i64 query(int x1,int y1,int x2,int y2){
    i64 ret=INFl;
    pii p=intersect({x1,y1},{x2,y2});
    if(!p.fi) return -1;
    int d1=dist(x1,y1)*2,d2=dist(x2,y2)*2;
    
    // 
    auto calc1 = [&](int t1,int t2){
        i64 x,y,d=exgcd(d1,-d2,x,y);
        if((t2-t1)%d==0){
            x*=(t2-t1)/d,d=-d;
            i64 t=x*d1+t1,l=(i64)d1*d2/abs(d);
            t=(t%l+l)%l;
            ret=min(ret,t);
        }
    };
    if(p.fi==p.se){
        int t1=dist(x1,p.fi),t2=dist(x2,p.fi);
        calc1(t1,t2),calc1(t1,d2-t2),calc1(d1-t1,t2),calc1(d1-t1,d2-t2);
    }
    else{
        calc1(tim(x1,y1,p.fi,p.se),tim(x2,y2,p.fi,p.se));
        calc1(tim(x1,y1,p.se,p.fi),tim(x2,y2,p.se,p.fi));
    }

    // 
    int dis=dist(p.fi,p.se);
    auto calc2 = [&](int t1,int t2){
        if((t1+t2+dis)%2==0){
            i64 L=t2-t1-dis,R=t2-t1+dis,x,y;
            calc(L,R,d1,d2,x,y);
            if(y*d2+L<=x*d1&&x*d1<=y*d2+R) ret=min(ret,(x*d1+y*d2+t1+t2+dis)/2);
        }
    };
    if(p.fi!=p.se){
        calc2(tim(x1,y1,p.fi,p.se),tim(x2,y2,p.se,p.fi));
        calc2(tim(x1,y1,p.se,p.fi),tim(x2,y2,p.fi,p.se));
    }
    
    return ret>=INFl?-1:ret;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    dfs(1,0);
    int q=rdi();
    while(q--){
        int x1=rdi(),y1=rdi(),x2=rdi(),y2=rdi();
        cout<<query(x1,y1,x2,y2)<<'\n';
    }
    return 0;
}