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
#define taskname "G"
#define next Touma
int next[3200][26];
int p[3200];
string s, t;
int m;
int f[3200];
int g[3200];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    cin>>s>>t;
    if(t.size()>s.size()){
        puts("0");
        return 0;
    }
    m=t.size();
    t='0'+t;
    for(char &c: s) if(c!='?') c-='a';
    for(char &c: t) c-='a';
    FOR(i, 2, m){
        p[i]=p[i-1];
        while((p[i])&&(t[p[i]+1]!=t[i])) p[i]=p[p[i]];
        if(t[p[i]+1]==t[i]) p[i]++;
    }
    FOR(i, 0, m){
        FFOR(c, 0, 26){
            if(i==m) next[i][c]=p[i];
            else next[i][c]=i;
            while((next[i][c])&&(t[next[i][c]+1]!=c)) next[i][c]=p[next[i][c]];
            if(t[next[i][c]+1]==c) next[i][c]++;
        }
    }
    FOR(i, 1, m) f[i]=-1e6;
    for(char c: s){
        FOR(i, 0, m) g[i]=f[i];
        FOR(i, 0, m) f[i]=-1e6;
        if(c=='?') FOR(i, 0, m) FFOR(j, 0, 26) f[next[i][j]]=max(f[next[i][j]], g[i]);
        else FOR(i, 0, m) f[next[i][c]]=max(f[next[i][c]], g[i]);
        f[m]++;
    }
    int ans=0;
    FOR(i, 0, m) ans=max(ans, f[i]);
    writeln(ans);
}