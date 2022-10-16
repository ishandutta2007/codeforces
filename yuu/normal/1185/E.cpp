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
int n, m;
char c[2001][2001];
char d[2001][2001];
int lx[26];
int ly[26];
int hx[26];
int hy[26];
bool bad[26];
vector <pair <pair <int, int>, pair <int, int>>> ans;
void solve(){
    read(n);
    read(m);
    int mx=-1;
    FOR(i, 1, n) FOR(j, 1, m){
        while(true){
            c[i][j]=getchar();
            if(c[i][j]=='.') break;
            if(isalpha(c[i][j])){
                c[i][j]-='a';
                if(c[i][j]>mx) mx=c[i][j];
                break;
            }
        }
    }
    ans.clear();
    FOR(i, 0, mx) lx[i]=ly[i]=1e9;
    FOR(i, 0, mx) hx[i]=hy[i]=-1e9;
    FOR(i, 1, n) FOR(j, 1, m) if(c[i][j]!='.'){
        lx[c[i][j]]=min(lx[c[i][j]], i);
        ly[c[i][j]]=min(ly[c[i][j]], j);
        hx[c[i][j]]=max(hx[c[i][j]], i);
        hy[c[i][j]]=max(hy[c[i][j]], j);
    }
//    cerr<<"OK\n";
//    bug(mx);
    int now=0;
    FOR(i, 0, mx) bad[i]=0;
    FOR(i, 0, mx) if(lx[i]!=1e9){
        if((lx[i]!=hx[i])&&(ly[i]!=hy[i])){
            puts("NO");
            return;
        }
        while(now<=i){
            ans.pb(mp(mp(lx[i], ly[i]), mp(hx[i], hy[i])));
            if(now<i) bad[now]=1;
            now++;
        }
    }
    FOR(i, 1, n) FOR(j, 1, m) d[i][j]='.';
    FOR(i, 0, mx) if(!bad[i]){
//        bug(i);
//        cerr<<ans[i].first.first<<' '<<ans[i].first.second<<' '<<ans[i].second.first<<' '<<ans[i].second.second<<'\n';
        FOR(x, ans[i].first.first, ans[i].second.first) FOR(y, ans[i].first.second, ans[i].second.second){
            d[x][y]=i;
        }
    }
//    FOR(i, 1, n) FOR(j, 1, m) cerr<<c[i][j]<<"\0\n"[j==m];
//    FOR(i, 1, n) FOR(j, 1, m) cerr<<d[i][j]<<"\0\n"[j==m];
    FOR(i, 1, n) FOR(j, 1, m) if(d[i][j]!=c[i][j]){
        puts("NO");
        return;
    }
    puts("YES");
    writeln(ans.size());
    FOR(i, 0, mx){
        write(ans[i].first.first);
        putchar(' ');
        write(ans[i].first.second);
        putchar(' ');
        write(ans[i].second.first);
        putchar(' ');
        writeln(ans[i].second.second);
    }
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    int t;
    read(t);
    while(t--) solve();
}