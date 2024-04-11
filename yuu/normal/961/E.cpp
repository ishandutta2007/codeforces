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
int a[200001];
int ft[200001];
bool removed[200001];
deque <int> pos;
void update(int u, int x){
    for(; u<=n; u+=u&-u) ft[u]+=x;
}
int get(int u){
    int res=0;
    for(; u>0; u-=u&-u) res+=ft[u];
    return res;
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) pos.pb(i);
    sort(pos.begin(), pos.end(), [](int A, int B){
        return a[A]<a[B];
    });
    ll ans=0;
    FOR(i, 1, n){
        while((!pos.empty())&&(a[pos.front()]<i)){
            removed[pos.front()]=1;
            if(pos.front()<i) update(pos.front(), -1);
            pos.pop_front();
        }
        a[i]=min(a[i], n);
        ans+=get(a[i]);
        if(!removed[i]) update(i, 1);
    }
    writeln(ans);
}