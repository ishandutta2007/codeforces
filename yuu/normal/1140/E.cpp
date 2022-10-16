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
#define taskname "E"
int n, k;
const ll base=998244353;
vector <int> o[2];
ll f[100001][3];
ll F(int a, int b, int n){
    if(n==0) return a!=b;
    else{
        if(b==0) swap(a, b);
        if(a==0){
            if(b==0){
                ll res=k;
                FFOR(i, 1, n) res=(res*(k-1))%base;
                return res;
            }
            else{
                ll res=1;
                FOR(i, 1, n) res=(res*(k-1))%base;
                return res;
            }
        }
        else{
            if(a==b){
                FOR(i, 0, n) FOR(x, 0, 1) f[i][x]=0;
                f[1][0]=k-1;
                FFOR(i, 1, n){
                    f[i+1][0]=(f[i][0]*(k-2)+f[i][1]*(k-1))%base;
                    f[i+1][1]=f[i][0];
                }
                return f[n][0];
            }
            else{
                FOR(i, 0, n) FOR(x, 0, 2) f[i][x]=0;
                f[1][0]=k-2;
                f[1][2]=1;
                FFOR(i, 1, n){
                    f[i+1][0]=(f[i][0]*max(0, k-3)+f[i][1]*(k-2)+f[i][2]*(k-2))%base;
                    f[i+1][1]=(f[i][0]+f[i][2])%base;
                    f[i+1][2]=(f[i][0]+f[i][1])%base;
                }
                return (f[n][0]+f[n][1])%base;
            }
        }
    }
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    read(k);
    FOR(i, 1, n){
        ll a;
        read(a);
        o[i%2].pb(a);
    }
    ll ans=1;
    FOR(b, 0, 1){
        int old=0;
        int cnt=0;
        FFOR(i, 0, o[b].size()){
            if(o[b][i]==-1) cnt++;
            else{
                ans=(ans*F(old, o[b][i], cnt))%base;
                old=o[b][i];
                cnt=0;
            }
        }
        if(cnt) ans=(ans*F(old, 0, cnt))%base;
    }
    writeln(ans);
}