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
#define taskname "F"
#define prev Kafuu
#define next Chino
const ll base=999727999;
const ll q=131;
int n, m;
string s;
ll f[200001];
ll r[200001];
ll h[200001];
int next[200001][26];
int prev[200001][26];
ll hc[26];
ll power(ll a, ll b){
    if(b==0) return 1;
    ll t=power(a, b/2);
    t=(t*t)%base;
    if(b%2) t=(t*a)%base;
    return t;
}
void solve(int x, int y, int len){
    multiset <ll> A, B;
    FFOR(i, 0, 26){
        int last=(s[x+len-1]==i)?(x+len-1):prev[x+len-1][i];
        if(last<x) continue;
        A.insert(((h[last]+base-((prev[x][i]>=0)?h[prev[x][i]]:0))*r[x])%base);
    }
    FFOR(i, 0, 26){
        int last=(s[y+len-1]==i)?(y+len-1):prev[y+len-1][i];
        if(last<y) continue;
        B.insert(((h[last]+base-((prev[y][i]>=0)?h[prev[y][i]]:0))*r[y])%base);
    }
    puts((A==B)?"YES":"NO");
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    cin>>s;
    for(char &c: s) c-='a';
    f[0]=1;
    FOR(i, 1, n) f[i]=(f[i-1]*q)%base;
    r[n]=power(f[n], base-2);
    DFOR(i, n-1, 0) r[i]=(r[i+1]*q)%base;
    FFOR(i, 0, n){
        h[i]=(hc[s[i]]+f[i])%base;
        hc[s[i]]=h[i];
    }
    FFOR(i, 0, 26) prev[0][i]=-1;
    FFOR(i, 1, n){
        FFOR(j, 0, 26) prev[i][j]=prev[i-1][j];
        prev[i][s[i-1]]=i-1;
    }
    FFOR(i, 0, 26) next[n-1][i]=n;
    DFOR(i, n-2, 0){
        FFOR(j, 0, 26) next[i][j]=next[i+1][j];
        next[i][s[i+1]]=i+1;
    }
    {
        int x, y, len;
        FOR(i, 1, m){
            read(x);
            read(y);
            read(len);
            x--;
            y--;
            solve(x, y, len);
        }
    }
}