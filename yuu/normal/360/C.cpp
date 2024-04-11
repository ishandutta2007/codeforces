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
#define taskname "360C"
int n, k;
const ll base=1000000007;
ll f[2001][2001][2];
string s;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    cin>>n>>k>>s;
    f[s.size()][0][0]=1;
    DFOR(i, s.size(), 1){
        int big='z'-s[i-1];
        int small=s[i-1]-'a';
        FOR(j, 0, k){
            f[i][j][0]%=base;
            f[i][j][1]%=base;
            FOR(x, 1, i){
                if(j+(s.size()-i+1)*x>k) break;
                f[i-x][j+(s.size()-i+1)*x][1]=(f[i-x][j+(s.size()-i+1)*x][1]+(f[i][j][0]+f[i][j][1])*big)%base;
            }
            f[i-1][j][0]=(f[i-1][j][0]+(f[i][j][0]+f[i][j][1])*small)%base;
            f[i-1][j][0]=(f[i-1][j][0]+f[i][j][0])%base;
        }
    }
    writeln((f[0][k][0]+f[0][k][1]+base*base)%base);
}