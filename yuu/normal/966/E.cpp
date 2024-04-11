#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
typedef long long ll;
typedef long double ld;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "E"
int n, m;
int p[100001];
int t[100001];
vector <int> g[100001];
bool done[100001];
int f[100001];
vector <int> chain[100001];
int from_chain[100001];
int chain_count;
void dfs(int u){
    f[u]=1;
    for(int v: g[u]){
        dfs(v);
        f[u]+=f[v];
    }
    FFOR(i, 1, g[u].size()) if(f[g[u][i]]>f[g[u][0]]) swap(g[u][i], g[u][0]);
}
int bucket=400;
void make_chain(int u, int from){
    chain[from].pb(u);
    from_chain[u]=from;
    if(g[u].empty()) return;
    if(chain[from].size()<bucket) make_chain(g[u][0], from);
    else make_chain(g[u][0], ++chain_count);
    FFOR(i, 1, g[u].size()) make_chain(g[u][i], ++chain_count);
}
int ans=0;
bool vac[100001];
class Achain{
public:
    vector <int> v;
    int count=0;
    int id;
    int res=0;
    void reconstruct(){
        for(int u: chain[id]) t[u]+=count;
        count=0;
        ans-=res;
        v.clear();
        for(int u: chain[id]) if(!vac[u]) v.pb(t[u]);
        sort(v.begin(), v.end());
        res=0;
        while((res<v.size())&&(v[res]<0)) res++;
        ans+=res;
    }
    void change(int s){
        count+=s;
        ans-=res;
//        while((res<v.size())&&(v[res]+count<0)) res++;
//        while((res>0)&&(v[res-1]+count>=0)) res--;
        int l=0, r=((int)v.size())-1, m;
        res=-1;
        while(l<=r){
            m=(l+r)/2;
            if(v[m]+count<0){
                res=m;
                l=m+1;
            }
            else r=m-1;
        }
        res++;
        ans+=res;
    }
} A[100001];
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(m);
    FOR(i, 2, n){
        read(p[i]);
        g[p[i]].pb(i);
    }
    FOR(i, 1, n) read(t[i]);
    dfs(1);
    make_chain(1, ++chain_count);
    FOR(i, 1, chain_count){
        A[i].id=i;
        A[i].reconstruct();
    }
    {
        int v;
        FOR(i, 1, m){
            read(v);
            if(v>0){
                vac[v]=1;
                A[from_chain[v]].reconstruct();
                while(v){
                    if(v!=chain[from_chain[v]].back()){
                        t[v]--;
                        if(v==chain[from_chain[v]][0]) A[from_chain[v]].reconstruct();
                        v=p[v];
                    }
                    else{
                        A[from_chain[v]].change(-1);
                        v=p[chain[from_chain[v]][0]];
                    }
                }
            }
            else{
                v=-v;
                vac[v]=0;
                A[from_chain[v]].reconstruct();
                while(v){
                    if(v!=chain[from_chain[v]].back()){
                        t[v]++;
                        if(v==chain[from_chain[v]][0]) A[from_chain[v]].reconstruct();
                        v=p[v];
                    }
                    else{
                        A[from_chain[v]].change(1);
                        v=p[chain[from_chain[v]][0]];
                    }
                }
            }
            write(ans);
            putchar(' ');
        }
    }
}