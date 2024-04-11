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
#define taskname "E"
int n;
int c[1001];
ll f[1001][10001];
ll cost[1001];
ll w, b, x;
int sum[1001];
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(w);
    read(b);
    read(x);
    FOR(i, 1, n){
        read(c[i]);
        sum[i]=sum[i-1]+c[i];
    }
    FOR(i, 1, n) read(cost[i]);
    FOR(i, 0, n) FOR(j, 0, sum[n]) f[i][j]=-mask(60);
    f[0][0]=w;
    FOR(i, 1, n){
        deque <pair <ll, ll> > q;
        FOR(j, 0, sum[i]){
            while(!q.empty()){
                if(q.front().first+c[i]<j) q.pop_front();
                else if(cost[i]*(j-q.front().first)>q.front().second) q.pop_front();
                else break;
            }
            ll add=min(f[i-1][j]+x, w+b*j);
            while(!q.empty()){
                if(q.back().second-cost[i]*(j-q.back().first)<=add) q.pop_back();
                else break;
            }
            q.pb(mp(j, add));
            f[i][j]=q.front().second-cost[i]*(j-q.front().first);
        }
    }
    DFOR(j, sum[n], 0) if(f[n][j]>=0){
        writeln(j);
        return 0;
    }
}