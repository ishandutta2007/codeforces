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
#define taskname "E"
int n, l;
ll s;
ll w[100001];
int p[100001];
vector <int> g[100001];
pair <ll, int> f[100001];
ll d[100001];
vector <int> acs;
int ans=1;
void dfs(int u){
    acs.pb(u);
    for(int v: g[u]){
        d[v]=d[u]+w[v];
        dfs(v);
    }
    if(g[u].empty()) f[u]=mp(w[u], 1);
    else{
        int best=0;
        f[u]=mp(w[u], 1);
        bool first=1;
        for(int v: g[u]){
            ///find
            if((f[v].second==l)||(f[v].first+w[u]>s)){
                ans++;
                continue;
            }
            if(l-f[v].second<best){
                ans++;
                continue;
            }
            int low=max(0, ((int)acs.size())-(l-f[v].second));
            int high=acs.size()-1;
            int mid;
            int res=acs.size();
            while(low<=high){
                mid=(low+high)/2;
                if(d[u]-(mid?d[acs[mid-1]]:0)+f[v].first<=s){
                    res=mid;
                    high=mid-1;
                }
                else low=mid+1;
            }
            if(((int)acs.size())-res>best){
                best=((int)acs.size())-res;
                f[u]=mp(w[u]+f[v].first, f[v].second+1);
                if(first) first=0;
                else ans++;
            }
            else ans++;
        }
    }
    acs.pop_back();
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(l);
    read(s);
    FOR(i, 1, n){
        read(w[i]);
        if(w[i]>s){
            puts("-1");
            return 0;
        }
    }
    FOR(i, 2, n){
        read(p[i]);
        g[p[i]].pb(i);
    }
    d[1]=w[1];
    dfs(1);
    writeln(ans);
}