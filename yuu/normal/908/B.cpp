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
int n, m;
string s;
pair <int, int> moves[]={mp(-1, 0), mp(0, -1), mp(0, 1), mp(1, 0)};
pair <int, int> start;
char a[51][51];
void operator += (pair <int, int> &a, pair <int, int> b){
    a.first+=b.first;
    a.second+=b.second;
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    cin>>n>>m;
    FOR(i, 1, n) FOR(j, 1, m) cin>>a[i][j];
    cin>>s;
    for(char &c: s) c-=48;
    FOR(i, 1, n) FOR(j, 1, m) if(a[i][j]=='S') start=mp(i, j);
    int ans=0;
    do{
        pair <int, int> now=start;
        for(char c: s){
            now+=moves[c];
            if(now.first<1||now.first>n) break;
            if(now.second<1||now.second>m) break;
            if(a[now.first][now.second]=='#') break;
            if(a[now.first][now.second]=='E'){
                ans++;
                break;
            }
        }
    }
    while(next_permutation(moves, moves+4));
    write(ans);
}