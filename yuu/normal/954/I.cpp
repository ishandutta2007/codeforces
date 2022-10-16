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
#define taskname "I"
string s, t;
string a, b;
int ans[125001];
int n, m;
int gr[256];
char value[256];
int f[125001];
void make(int cost){
    DFOR(i, 'f', 'a') value[gr[i]]=i;
    a=b="";
    for(char c: s) a+=value[gr[c]];
    for(char c: t) b+=value[gr[c]];
    f[1]=0;
    FOR(i, 2, m){
        f[i]=f[i-1];
        while((f[i]>0)&&(b[f[i]+1]!=b[i])) f[i]=f[f[i]];
        if(b[f[i]+1]==b[i]) f[i]++;
    }
    int pos=0;
    FOR(i, 1, n){
        if(b[pos+1]==a[i]) pos++;
        else{
            while((pos>0)&&(b[pos+1]!=a[i])) pos=f[pos];
            if(b[pos+1]==a[i]) pos++;
        }
        if(pos==m){
            ans[i]=min(ans[i], cost);
            pos=f[pos];
        }
    }
}
void backtrack(char c, int high){
    if(c=='g') make('f'-'a'+1-high);
    else{
        FOR(i, 1, high+1){
            gr[c]=i;
            backtrack(c+1, max(high, i));
        }
    }
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    cin>>s>>t;
    n=s.size();
    m=t.size();
    FOR(i, 1, n) ans[i]=5;
    s='0'+s;
    t='0'+t;
    backtrack('a', 0);
    FOR(i, m, n) write(ans[i]), putchar(' ');
}