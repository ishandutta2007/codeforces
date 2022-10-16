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
int f[1001];
ll c[1001][1001];
const ll base=1000000007;
string n;
int k;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    cin>>n>>k;
    if(k==0){
        write(1);
        return 0;
    }
    c[0][0]=1;
    FOR(i, 1, 1000){
        c[i][0]=c[i][i]=1;
        FFOR(j, 1, i) c[i][j]=(c[i-1][j]+c[i-1][j-1])%base;
    }
    f[1]=0;
    FOR(i, 2, 1000) f[i]=f[builtin_popcount(i)]+1;
    ll ans=0;
    FOR(i, 1, 1000) if(f[i]+1==k){
        int z=0;
        FFOR(j, 0, n.size()) if(n[j]=='1'){
            ans=(ans+c[n.size()-j-1][i-z])%base;
            z++;
            if(z==i){
                ans=(ans+1)%base;
                break;
            }
        }
    }
    if(k==1) ans=(ans+base-1)%base;
    writeln(ans);

}