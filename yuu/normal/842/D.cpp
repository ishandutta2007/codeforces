#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "D"
int n, m;
int a[300001];
int x;
class trie{
    struct node{
        int lv;
        int c[2];
        int f;
    } d;
    vector <node> v;
    vector <int> u;
    vector <int> xr;
    public: trie(){
        d.lv=1<<20;
        v.pb(d);
        FFOR(i, 0, 20) xr.pb(0);
    }
    void add(int i, int c){
        if(i<20){
            if(v[c].c[u[i]]==0){
                v[c].c[u[i]]=v.size();
                d.lv=v[c].lv/2;
                v.pb(d);
            }
            add(i+1, v[c].c[u[i]]);
            if(c) v[c].f=v[v[c].c[0]].f+v[v[c].c[1]].f;
        }
        else{
            v[c].f=1;
        }
    }
    void add(int n){
        u.clear();
        FOR(i, 1, 20){
            u.pb(n%2);
            n/=2;
        }
        reverse(u.begin(), u.end());
        add(0, 0);
    }
    int get(){
        int res=0;
        int c=0;
        bool good=0;
        FFOR(i, 0, 20){
            if(good){
                res*=2;
                continue;
            }
            if(!v[c].c[xr[i]^0]){// no such node
                good=1;
                res*=2;
                continue;
            }
            if(v[v[c].c[xr[i]^0]].f<v[v[c].c[xr[i]^0]].lv){
                res=res*2;
                c=v[c].c[xr[i]^0];
            }
            else{
                if(!v[c].c[xr[i]^1]){// no such node
                    good=1;
                    res=res*2+1;
                    continue;
                }
                res=res*2+1;
                c=v[c].c[xr[i]^1];
            }
        }
        return res;
    }
    inline void doxor(int x){
        u.clear();
        FOR(i, 1, 20){
            u.pb(x%2);
            x/=2;
        }
        reverse(u.begin(), u.end());
        FFOR(i, 0, 20) xr[i]^=u[i];
    }
} T;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(m);
    FOR(i, 1, n){
        read(a[i]);
        T.add(a[i]);
    }
    FOR(i, 1, m){
        read(x);
        T.doxor(x);
        writeln(T.get());
    }
}