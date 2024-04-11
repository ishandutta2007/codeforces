#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
template <typename CT, typename T> inline void reset_container(CT &c, int sz, T v){c.resize(sz); for(auto &x: c) x=v;}
#define taskname "G"
int n, q;
vector <int> g[200001];
int first[200001];
int last[200001];
//int ver[200001];
ll ra[200001];
ll rb[200001];
ll a[200001];
ll b[200001];
int cnt=0;
void dfs(int u){
    cnt++;
    first[u]=cnt;
//    ver[cnt]=u;
    a[cnt]=ra[u];
    b[cnt]=abs(rb[u]);
    for(int v: g[u]){
        rb[v]+=rb[u];
        ra[v]+=ra[u];
        dfs(v);
    }
    last[u]=cnt;
}
class line{
public:
    ll a, b;
    ///y=ax+b
    line(ll a, ll b): a(a), b(b){}
    ll at(ll x){
        return a*x+b;
    }
    ll first_less(line L){
        ///a<L.a
        ///a*x+b<=L.a*x+L.b
        ///(L.a-a)*x>=(b-L.b)
//        assert(a<L.a);
        ll x=(b-L.b)/(L.a-a);
        while((L.a-a)*x<(b-L.b)) x++;
        return x;
    }
    bool operator ==(line P){
        return (a==P.a)&&(b==P.b);
    }
};
//const int sz=200000;
const int sz=101;
//const int sz=1;
class CHT{
public:
    vector <line> L;
    vector <pair <ll, line>> F;
    ll get(ll x){
//        bug(F.size());
        int low=0, high=F.size()-1, mid, res;
        while(low<=high){
            mid=(low+high)/2;
            if(F[mid].first<=x){
                res=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return F[res].second.at(x);
    }
    void build(){
        sort(L.begin(), L.end(), [](line A, line B){
            return (A.a<B.a)||(A.a==B.a&&A.b>B.b);
        });
        for(auto l: L){
            while((!F.empty())&&(l.at(F.back().first)>=F.back().second.at(F.back().first))) F.pop_back();
            if(F.empty()) F.pb(mp(0, l));
            else{
                if((F.back().second.a==l.a)&&(F.back().second.b>=l.b)) continue;
                ll nx=F.back().second.first_less(l);
                F.pb(mp(nx, l));
            }
        }
    }
    void clear(){
        F.clear();
        L.clear();
    }
    void insert(line A){
        L.pb(A);
    }
} f[200000/sz+100];
int start[200000/sz+100];
int finish[200000/sz+100];
ll w[200000/sz+100];
int block[200001];
vector <line> lines[200001];
//void get_lines(int i){
//    ///a[i]*b[i]
//    lines[i].clear();
//    if(a[i]>=0){
//        lines.pb(line(b[i], a[i]*b[i]));
//    }
//    else{
//        lines.pb(line(-b[i], -a[i]*b[i]));
//        lines.pb(line(b[i], a[i]*b[i]);
//    }
//}
void update_block(int x){
    FOR(i, start[x], finish[x]){
        a[i]+=w[x];
    }
    w[x]=0;
    f[x].clear();
    FOR(i, start[x], finish[x]){
        f[x].insert(line(b[i], a[i]*b[i]));
        if(a[i]<0) f[x].insert(line(-b[i], -a[i]*b[i]));
    }
    f[x].build();
}
//ll get_block(int x){
//    return f[x].get(w[x]);
//}
void update(int u, int v, int x){
    FOR(i, u, v){
        if(block[i]!=block[u]) break;
        a[i]+=x;
    }
    update_block(block[u]);
    if(block[u]==block[v]) return;
    DFOR(i, v, u){
        if(block[i]!=block[v]) break;
        a[i]+=x;
    }
    update_block(block[v]);
    FFOR(i, block[u]+1, block[v]) w[i]+=x;
}
ll get(int u, int v){
    ll ans=0;
    FOR(i, u, v){
        if(block[i]!=block[u]) break;
        ans=max(ans, abs(a[i]+w[block[i]])*b[i]);
    }
    if(block[u]==block[v]) return ans;
    DFOR(i, v, u){
        if(block[i]!=block[v]) break;
        ans=max(ans, abs(a[i]+w[block[i]])*b[i]);
    }
    FFOR(i, block[u]+1, block[v]){
        ans=max(ans, f[i].get(w[i]));
    }
    return ans;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(q);
    FOR(i, 2, n){
        int p;
        read(p);
        g[p].pb(i);
    }
    FOR(i, 1, n) read(ra[i]);
    FOR(i, 1, n) read(rb[i]);
    dfs(1);
    block[0]=0;
    FOR(i, 1, n) if((i-1)%sz==0) block[i]=block[i-1]+1; else block[i]=block[i-1];
    FOR(i, 1, n) if(start[block[i]]==0) start[block[i]]=i;
    DFOR(i, n, 1) if(finish[block[i]]==0) finish[block[i]]=i;
    FOR(i, 1, block[n]) update_block(i);
    FOR(i, 1, q){
        int o, v, x;
        read(o);
        read(v);
        if(o==1){
            read(x);
            update(first[v], last[v], x);
        }
        else{
            writeln(get(first[v], last[v]));
        }
    }

}