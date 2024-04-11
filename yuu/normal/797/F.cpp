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
int n, m;
int x[5001];
pair <int, int> p[5001];
deque <int> q;
deque <int> sp;
ll now;
ll ans;
ll f[5001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    FOR(i, 1, n) read(x[i]);
    FOR(j, 1, m){
        read(p[j].first);
        read(p[j].second);
    }
    sort(x+1, x+n+1);
    sort(p+1, p+m+1);
    int temp=0;
    FOR(i, 1, m) temp+=p[i].second;
    if(temp<n){
        puts("-1");
        return 0;
    }
    FOR(i, 1, n) f[i]=1e18;
    FOR(i, 1, m){
        deque <pair <ll, int> > q;
        q.pb(mp(0, 0));
        ll sum=0;
        FOR(j, 1, n){
            sum+=abs(p[i].first-x[j]);
            while((!q.empty())&&(q.back().first>=f[j]-sum)) q.pop_back();
            q.pb(mp(f[j]-sum, j));
            while((j-q.front().second)>p[i].second) q.pop_front();
            f[j]=q.front().first+sum;
        }
    }
    writeln(f[n]);
}