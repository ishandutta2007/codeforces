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
#define taskname "F"
#define next Imouto_sae_Ireba_Ii
int n;
string s;
const ll base=1000000007;
int k[201];
int next[201][2];
ll f[201][201][201];
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    cin>>n>>s;
    n*=2;
    for(auto &x: s) x=(x==')');
    k[0]=-1;
    FFOR(i, 1, s.size()){
        k[i]=k[i-1];
        while((k[i]!=-1)&&(s[k[i]+1]!=s[i])) k[i]=k[k[i]];
        if(s[k[i]+1]==s[i]) k[i]++;
    }
    FFOR(i, 0, s.size()){
        FOR(b, 0, 1){
            if(b==s[i]) next[i][b]=i+1;
            else{
                int p=(i?k[i-1]:-1);
                while((p!=-1)&&(s[p+1]!=b)) p=k[p];
                if(s[p+1]==b) p++;
                next[i][b]=p+1;
            }
        }
    }
    next[s.size()][0]=next[s.size()][1]=s.size();
    f[0][0][0]=1;
    FFOR(i, 0, n) FOR(j, 0, s.size()) FOR(k, 0, i){
        FOR(b, 0, 1){
            int nk=k+((b==0)?1:-1);
            if(nk<0) continue;
            f[i+1][next[j][b]][nk]+=f[i][j][k];
            while(f[i+1][next[j][b]][nk]>=base) f[i+1][next[j][b]][nk]-=base;
        }
    }
    writeln(f[n][s.size()][0]);
}