#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
#define taskname "G"
int g[51][26][17][4];
bool doneg[51][26][17][4];
const int base=1000000007;
void PE(int &a, int b){
    a+=b;
    while(a>=base) a-=base;
    while(a<0) a+=base;
}
int P(int a, int b){
    a+=b;
    while(a>=base) a-=base;
    while(a<0) a+=base;
    return a;
}
ll G(int a, int b, int c, int d=0){
    if(doneg[a][b][c][d]) return g[a][b][c][d];
    doneg[a][b][c][d]=1;
    if(a==0&&b==0&&c==0) return g[a][b][c][d]=1;
    ll res=0;
    if(a&&(d!=1)) res+=G(a-1, b, c, 1)*a;
    if(b&&(d!=2)) res+=G(a, b-1, c, 2)*b;
    if(c&&(d!=3)) res+=G(a, b, c-1, 3)*c;
    res%=base;
    return g[a][b][c][d]=res;
}
int n, t;
int f[2551][51][26][17];
int cnt[4];
int ha[4];
int po[4];
int d[51];
int k[51];
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
//    int cnt=0;
//    bug(G(0, 2, 2));
////    int cx=16;
////    int cy=17;
////    int cz=50-cx-cy;
//    int mx=0;
//    FOR(x, 0, 50) FOR(y, 0, 50){
//        if(x+y>50) break;
//        int z=50-x-y;
//        mx=max(mx, (x+1)*(y+1)*(z+1));
//    }
//    bug(mx);
    //mx~5000
    ha[1]=1;
    ha[2]=2;
    ha[3]=3;
    read(n);
    read(t);
    FOR(i, 1, n){
        read(d[i]);
        read(k[i]);
        cnt[k[i]]++;
    }
    sort(ha+1, ha+4, [](int a, int b){
        return cnt[a]>cnt[b];
    });
    FOR(i, 1, 3) po[ha[i]]=i;
    FOR(i, 1, n) k[i]=po[k[i]];
    FOR(i, 1, 3) cnt[i]=0;
    f[0][0][0][0]=1;
    FOR(i, 1, n){
        DFOR(j, t, 0) FOR(a, 0, cnt[1]) FOR(b, 0, cnt[2]) FOR(c, 0, cnt[3]) if(f[j][a][b][c]){
//            cerr<<i<<' '<<j<<' '<<a<<' '<<b<<' '<<c<<'\n';
            PE(f[j+d[i]][a+(k[i]==1)][b+(k[i]==2)][c+(k[i]==3)], f[j][a][b][c]);
        }
        cnt[k[i]]++;
    }
//    bug(f[3][1][1][1]);
    ll ans=0;
    FOR(a, 0, cnt[1]) FOR(b, 0, cnt[2]) FOR(c, 0, cnt[3]){
        ans+=(G(a, b, c, 0)*f[t][a][b][c])%base;
    }
    ans%=base;
    writeln(ans);
}