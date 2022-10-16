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
int n, q;
ll a[500001];
ll s[500001];
ld ans=0;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(q);
{
    int t;
    FOR(i, 1, q){
        read(t);
        if(t==2) cout<<setprecision(10)<<fixed<<ans<<'\n';
        else{
            n++;
            read(a[n]);
            s[n]=s[n-1]+a[n];
            int l=1, r=n-1, m, pos=1;
            while(l<=r){
                m=(l+r)/2;
                if(s[m]+a[n]>=a[m]*(m+1)){
                    pos=m;
                    l=m+1;
                }
                else r=m-1;
            }
            ans=max(ans, ((ld)a[n])-((ld)s[pos]+a[n])/(pos+1));
        }
    }
}
}