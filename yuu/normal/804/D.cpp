#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
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
#define taskname "F"
typedef long double ld;
vector <int> temp;
struct tree{
    int n;
    vector <bool> done;
    vector <int> f[2];
    vector <int> p;
    vector <int> d;
    vector <ld> sum;
    vector <vector <int> > g;
    ld best;
    tree(int n){
        this->n=n;
        while(n>=0){
            done.pb(0);
            f[0].pb(0);
            f[1].pb(0);
            d.pb(0);
            p.pb(0);
            g.pb(temp);
            n--;
        }
    }
    inline void add_edge(int u, int v){
        g[u].pb(v);
        g[v].pb(u);
    }
    void dfs(int u){
        done[u]=1;
        for(int v: g[u]){
            if(!done[v]){
                p[v]=u;
                dfs(v);
                if(f[0][u]<f[0][v]+1){
                    f[1][u]=f[0][u];
                    f[0][u]=f[0][v]+1;
                }
                else if(f[1][u]<f[0][v]+1){
                    f[1][u]=f[0][v]+1;
                }
            }
        }
    }
    void cal(int u){
        done[u]=1;
        if(u!=1){
            if(f[0][u]==f[0][p[u]]-1)
                d[u]=max(d[p[u]]+1, f[1][p[u]]+1);
            else
                d[u]=max(d[p[u]]+1, f[0][p[u]]+1);
        }
        for(int v: g[u])
            if(!done[v])
                cal(v);
        d[u]=max(d[u], f[0][u]);
    }
    void init(){
        dfs(1);
        FOR(i, 1, n)
            done[i]=0;
        cal(1);
        sort(d.begin()+1, d.end());
        best=d.back();
        sum.pb(0);
        FOR(i, 1, n)
            sum.pb(sum.back()+d[i]);
    }
};
vector <tree> T;
vector <int> g[100001];
bool done[100001];
int of[100001];
int s;
int n, m, q, u, v;
vector <int> cc;
vector <pair <int, int> > ce;
map <pair <int, int>, ld> M;
void dfs(int u){
    of[u]=T.size();
    cc.pb(u);
    done[u]=1;
    for(int v: g[u]){
        if(!done[v]){
            ce.pb(mp(u, v));
            dfs(v);
        }
    }
}
inline int find_pos(int u){
    return (lower_bound(cc.begin(), cc.end(), u)-cc.begin())+1;
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(m);
    read(q);
    FOR(i, 1, m){
        read(u);
        read(v);
        g[u].pb(v);
        g[v].pb(u);
    }
    while(s<n){
        if(!done[s+1]){
            cc.clear();
            dfs(s+1);
            T.pb(tree(cc.size()));
            sort(cc.begin(), cc.end());
            while(!ce.empty()){
                u=find_pos(ce.back().first);
                v=find_pos(ce.back().second);
                T.back().add_edge(u, v);
                ce.pop_back();
            }
            T.back().init();
        }
        s++;
    }
    while(q--){
        read(u);
        read(v);
        u=of[u];
        v=of[v];
        if(u==v)
            puts("-1");
        else{
            if(T[u].n>T[v].n) swap(u, v);
            else if(T[u].n==T[v].n&&u>v) swap(u, v);
            ld ans=0;
            if(M.find(mp(u, v))!=M.end()){
                ans=M[mp(u, v)];
            }
            else{
                ld best=max(T[u].best, T[v].best);
                FOR(i, 1, T[u].n){
                    if(T[u].d[i]+T[v].d[1]+1>=best){
                        ans=ans+T[v].sum[T[v].n]*(T[u].n-i+1)+(T[u].sum[T[u].n]-T[u].sum[i-1])*T[v].n+(ld)(T[u].n-i+1)*T[v].n;
                        break;
                    }
                    else{
                        int j=T[v].n;
                        int l=1, r=T[v].n;
                        while(l<=r){
                            m=(l+r)/2;
                            if(T[v].d[m]+T[u].d[i]<best){
                                j=m;
                                l=m+1;
                            }
                            else r=m-1;
                        }
                        ans=ans+best*j+(T[v].n-j)*(T[u].d[i]+1)+(T[v].sum[T[v].n]-T[v].sum[j]);
                    }
                }
                M[mp(u, v)]=ans;
            }
            cout<<setprecision(10)<<fixed<<ans/((ld)(T[u].n)*(ld)(T[v].n))<<'\n';
        }
    }
}