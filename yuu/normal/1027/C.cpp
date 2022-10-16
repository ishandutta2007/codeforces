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
#define taskname "C"
int n;
int f[10001];
int last[10001];
int testc=0;
vector <int> s;
vector <int> v;
void solve(){
    testc++;
    read(n);
    s.clear();
    {
        int a;
        FOR(i, 1, n){
            read(a);
            if(last[a]<testc){
                last[a]=testc;
                f[a]=1;
                s.pb(a);
            }
            else f[a]++;
        }
    }
    v.clear();
    for(int a: s) if(f[a]>=2){
        v.pb(a);
        if(f[a]>=4){
            FFOR(i, 0, 4){
                write(a);
                putchar(" \n"[(i+1)==4]);
            }
            return;
        }
    }
    sort(v.begin(), v.end());
    ll a=v[0], b=v[1], c, d;
    FFOR(i, 1, v.size()){
        c=v[i];
        d=v[i-1];
        if((a*a+b*b)*(c*d)>(c*c+d*d)*(a*b)){
            a=c;
            b=d;
        }
    }
    FFOR(i, 0, 2){
        write(a);
        putchar(' ');
        write(b);
        putchar(" \n"[i]);
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    int t;
    read(t);
    while(t--) solve();
}