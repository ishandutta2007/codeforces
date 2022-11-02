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
#define taskname "F"
int n;
int a[4];
string s[4];
int f[mask(12)];
int g[mask(12)];
int h[1001];
const int smax=mask(12);
int pos[4][4];
vector <int> transforms;
vector <int> cost;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FFOR(i, 0, 4) read(a[i]);
    {
        int cnt=0;
        DFOR(r, 2, 0) FFOR(c, 0, 4){
            pos[r][c]=cnt;
            cnt++;
        }
    }
    FFOR(b, 0, 4) FOR(sz, 0, b){
        if(sz==4) continue;
        transforms.pb(smax-1);
        cost.pb(a[sz]);
        FOR(c, b-sz, b) FOR(r, 0, sz) transforms.back()^=mask(pos[r][c]);
    }
    FFOR(i, 0, smax) f[i]=1e9;
    f[0]=0;
    FFOR(i, 0, 4) cin>>s[i];
    FFOR(r, 0, n){
        int v=0;
        FFOR(i, 0, 4) if(s[i][r]=='*') v^=mask(i);
        v<<=8;
        FFOR(i, 0, smax){
            g[i]=f[i];
            f[i]=1e9;
        }
        for(int i=0; i<smax; i+=mask(4)) f[(i>>4)|v]=g[i];
        DFOR(i, smax-1, 0) if(f[i]!=1e9) FFOR(j, 0, transforms.size()) f[i&transforms[j]]=min(f[i&transforms[j]], f[i]+cost[j]);
        f[0]=min(f[0], ((r>=4)?h[r-4]:0)+a[3]);
        h[r]=f[0];
    }
    writeln(h[n-1]);
}