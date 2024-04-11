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
using ll=long long;
using ld=long double;
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
#define taskname "348C"
const int mahou=333;
int n, m, q;
ll a[100001];
ll x[100001];
ll b[100001];
ll upd[100001];
vector <int> heavy;
vector <int> s[100001];
int w[100001][100000/mahou+13];
bool have[100001];
void prepare(int u){
    FOR(i, 1, n) have[i]=0;
    for(int x: s[heavy[u]]) have[x]=1;
    FOR(i, 1, m) for(int v: s[i]) w[i][u]+=have[v];
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    read(q);
    FOR(i, 1, n) read(a[i]);
    {
        int k;
        FOR(i, 1, m){
            read(k);
            s[i].resize(k);
            for(auto &x: s[i]) read(x);
            if(s[i].size()>mahou) heavy.pb(i);
        }
    }
    FFOR(i, 0, heavy.size()) prepare(i);
    FOR(i, 1, m) for(int x: s[i]) b[i]+=a[x];
    {
        char c;
        int k;
        ll y;
        FOR(que, 1, q){
            while(true){
                c=getchar();
                if(c=='?'||c=='+') break;
            }
            read(k);
            if(c=='?'){
                ll res=0;
                if(s[k].size()<=mahou){
                    for(auto &p: s[k]) res+=a[p];
                    FFOR(i, 0, heavy.size()) res+=upd[heavy[i]]*w[k][i];
                }
                else res=b[k];
                writeln(res);
            }
            else{
                read(y);
                FFOR(i, 0, heavy.size()) b[heavy[i]]+=y*w[k][i];
                upd[k]+=y;
                if(s[k].size()<=mahou) for(auto &p: s[k]) a[p]+=y;
            }
        }
    }
}