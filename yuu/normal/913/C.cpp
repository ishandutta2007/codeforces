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
ll c[32];
int n;
ll l;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(l);
    FFOR(i, 1, 32) c[i]=mask(60);
    FFOR(i, 0, n) read(c[i]);
    FFOR(i, 1, 32) c[i]=min(c[i], c[i-1]*2);
    DFOR(i, 30, 0) c[i]=min(c[i], c[i+1]);
    ll ans=mask(60);
    DFOR(i, 31, 0){
        ll res=0;
        ll sum=0;
        DFOR(j, 31, i) if(bit(l, j)){
            res+=c[j];
            sum|=mask(j);
        }
        ll a=l-sum;
        if(a<=0) ans=min(ans, res);
        else{
            int k=0;
            while(mask(k)<a) k++;
            ans=min(ans, res+c[k]);
        }
    }
    write(ans);
}