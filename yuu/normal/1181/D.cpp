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
#define taskname "D"
int n, m, qc;
int f[500001];
class query{
public:
    ll k;
    int id;
    void input(int id){
        this->id=id;
        read(k);
    }
};
int ans[500001];
vector <query> q;
vector <int> c;
int sz=0;
int ft[500001];
vector <int> up;
void update(int u){
    sz++;
//    up.pb(u);
    for(; u<=m; u+=u&-u) ft[u]++;
}
int get(int p){
    if(p==0) p=sz;
    int res=0;
    int sum=0;
    DFOR(i, __lg(m), 0){
        int nx=res+mask(i);
        if(nx>m) continue;
        if(sum+ft[nx]<p){
            sum+=ft[nx];
            res=nx;
        }
    }
    return res+1;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(m);
    read(qc);
    {
        int a;
        FOR(i, 1, n){
            read(a);
            f[a]++;
        }
    }
    FOR(i, 1, m) c.pb(i);
    sort(c.begin(), c.end(), [](int a, int b){
        return f[a]<f[b];
    });
//    for(int x: c) bug(x);
    q.resize(qc);
    FFOR(i, 0, qc) q[i].input(i);
    sort(q.begin(), q.end(), [](query A, query B){
        return A.k<B.k;
    });
    ll now=n;
    int w=f[c[0]];
    int done=0;
    for(query x: q){
        while(true){
            while((done<m)&&f[c[done]]==w){
                update(c[done]);
                done++;
            }
            if(done==m) break;
            if(x.k-now>((ll)(f[c[done]]-w))*sz){
                now+=((ll)(f[c[done]]-w))*sz;
                w=f[c[done]];
            }
            else break;
        }
//        bug(now);
//        bug(w);
//        bug(up.size());
//        sort(up.begin(), up.end());
//        FFOR(i, 0, up.size()) cerr<<up[i]<<" \n"[i+1==up.size()];
        ans[x.id]=get((x.k-now)%sz);
    }
    FFOR(i, 0, qc) writeln(ans[i]);
}