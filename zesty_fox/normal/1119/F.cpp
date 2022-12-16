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

const int N=250010;

int n,deg[N];
vector<pii> e[N];

struct Heap{
    int siz;i64 sum;
    priority_queue<i64> q,_q;
    void _upd() {while(!q.empty()&&!_q.empty()&&q.top()==_q.top()) q.pop(),_q.pop();}
    void push(i64 x) {q.push(x),++siz,sum+=x;}
    void pop() {_upd();--siz,sum-=q.top(),q.pop();}
    i64 top() {_upd();return q.top();}
    void erase(i64 x) {_q.push(x),--siz,sum-=x;}
    bool empty() {return !siz;}
    int size() {return siz;}
}h[N];

int vis[N];
i64 f[N][2];
void dfs(int x,int fa,int lim){
    vis[x]=lim;
    for(auto cur:e[x]){
        int y=cur.fi;
        if(y==fa) continue;
        if(deg[y]<=lim) break;
        dfs(y,x,lim);
    }
    int cnt=deg[x]-lim;i64 sum=0;
    vector<i64> buf1,buf2;
    while(!h[x].empty()&&h[x].size()>cnt) h[x].pop();
    for(auto cur:e[x]){
        int y=cur.fi,w=cur.se;
        if(y==fa) continue;
        if(deg[y]<=lim) break;
        i64 val=f[y][1]+w-f[y][0];
        if(val<=0) --cnt,sum+=f[y][1]+w;
        else h[x].push(val),sum+=f[y][0],buf1.pb(val);
    }
    while(!h[x].empty()&&h[x].size()>cnt) buf2.pb(h[x].top()),h[x].pop();
    f[x][0]=sum+h[x].sum;
    while(!h[x].empty()&&h[x].size()>cnt-1) buf2.pb(h[x].top()),h[x].pop();
    f[x][1]=sum+h[x].sum;
    for(auto v:buf2) h[x].push(v);
    for(auto v:buf1) h[x].erase(v);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();i64 sum=0;
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi(),w=rdi();
        e[x].pb({y,w}),e[y].pb({x,w});
        ++deg[x],++deg[y],sum+=w;
    }
    for(int i=1;i<=n;i++)
        sort(e[i].begin(),e[i].end(),[&](pii a,pii b){return deg[a.fi]>deg[b.fi];});
    static int seq[N];
    iota(seq+1,seq+n+1,1),sort(seq+1,seq+n+1,[&](int x,int y){return deg[x]<deg[y];});
    for(int lim=0,pos=1;lim<n;lim++){
        if(!lim) {cout<<sum<<' ';continue;}
        while(pos<=n&&deg[seq[pos]]<=lim){
            int x=seq[pos];
            for(auto cur:e[x]){
                int y=cur.fi,w=cur.se;
                if(deg[y]<=lim) break;
                h[y].push(w);
            }
            ++pos;
        }
        i64 res=0;
        for(int i=pos;i<=n;i++){
            int x=seq[i];
            if(vis[x]<lim) dfs(x,0,lim),res+=f[x][0];
        }
        cout<<res<<' ';
    }
    return 0;
}