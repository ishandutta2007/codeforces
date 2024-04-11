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
#define taskname "B"
int n, m, q;
string s, t;
int f[1001];
int c[1001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    read(q);
    cin>>s>>t;
    s='0'+s;
    t='0'+t;
    FOR(i, 2, m){
        f[i]=f[i-1];
        while((f[i])&&(t[f[i]+1]!=t[i])) f[i]=f[f[i]];
        if(t[f[i]+1]==t[i]) f[i]++;
    }
    int length=0;
    FOR(i, 1, n){
        if(s[i]==t[length+1]) length++;
        else{
            while((length)&&(t[length+1]!=s[i])) length=f[length];
            if(t[length+1]==s[i]) length++;
        }
        c[i]=c[i-1];
        if(length==m){
            c[i]++;
            length=f[length];
        }
    }
    {
        int l, r;
        FOR(i, 1, q){
            read(l);
            read(r);
            if(r-l+1<m) writeln(0);
            else writeln(c[r]-c[l+m-2]);
        }
    }
}