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
#define taskname "F2"
int n, m;
deque <int> pos[200001];
int k[200001];
int c[200001];
int sum=0;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(m);
    FOR(i, 1, n){
        read(c[i]);
        pos[c[i]].pb(i);
    }
    FOR(i, 1, m){
        read(k[i]);
        sum+=k[i];
    }
    int s=0;
    FOR(i, 1, m) if(pos[i].size()<k[i]){
        puts("-1");
        return 0;
    }
    else if(k[i]) s=max(s, pos[i][k[i]-1]);
    int ans=s-sum;
    FOR(i, 1, n){
        pos[c[i]].pop_front();
        if(pos[c[i]].size()<k[c[i]]) break;
        if(k[c[i]]) s=max(s, pos[c[i]][k[c[i]]-1]);
        ans=min(ans, s-i-sum);
    }
    writeln(ans);
}