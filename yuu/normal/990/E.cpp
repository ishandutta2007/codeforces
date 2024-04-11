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
#define left Chino
int n, m, k, x;
bool bad[1000001];
int left[1000001];
int a[1000001];
ll ans=1e18;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    read(k);
    {
        int s;
        FOR(i, 1, m){
            read(s);
            bad[s]=1;
        }
    }
    if(bad[0]){
        puts("-1");
        return 0;
    }
    int cnt=0;
    FOR(i, 1, n){
        if(bad[i]) cnt++;
        else cnt=0;
        x=max(x, cnt);
    }
    if(x>=k){
        puts("-1");
        return 0;
    }
    FOR(i, 1, k) read(a[i]);
    FOR(i, 1, n){
        if(bad[i]) left[i]=left[i-1];
        else left[i]=i;
    }
    FOR(i, x+1, k){
        ll cost=0;
        int st=0;
        while(st<n){
            st=left[st];
            cost+=a[i];
            st+=i;
        }
        ans=min(ans, cost);
        line0:;
    }
    writeln(ans);
}