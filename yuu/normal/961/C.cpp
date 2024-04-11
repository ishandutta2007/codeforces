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
vector <vector <char> > v[4];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FFOR(i, 0, 4){
        v[i].resize(n);
        FFOR(j, 0, n){
            v[i][j].resize(n);
            for(char &c: v[i][j]){
                while(!isdigit(c=getchar()));
                c-=48;
            }
        }
    }
    sort(v, v+4);
    int ans=1e9;
    do{
        int res=0;
        FFOR(i, 0, 4){
            FFOR(x, 0, n) FFOR(y, 0, n){
                res+=(x+y+builtin_popcount(i))%2!=v[i][x][y];
            }
        }
        ans=min(ans, res);
        res=0;
        FFOR(i, 0, 4){
            FFOR(x, 0, n) FFOR(y, 0, n){
                res+=(x+y+builtin_popcount(i))%2==v[i][x][y];
            }
        }
        ans=min(ans, res);
    }
    while(next_permutation(v, v+4));
    writeln(ans);
}