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
#define taskname "B"
string n;
int m;
int f[20][2];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    cin>>n;
    reverse(n.begin(), n.end());
    m=n.size();
    n='0'+n;
    FOR(i, 0, m) f[i][0]=f[i][1]=-1e6;
    f[0][0]=0;
    FOR(i, 1, m){
        n[i]-='0';
        FOR(b, 0, 1){
            FOR(x, 0, 9){
                int y=(((int)n[i])-b-x+100)%10;
                if(x+y+b>=10) f[i][1]=max(f[i][1], f[i-1][b]+x+y);
                else f[i][0]=max(f[i][0], f[i-1][b]+x+y);
            }
        }
    }
    writeln(f[m][0]);
}