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
#define taskname "F"
unordered_map <int, int>* m[1000001];
vector <int> g[1000001];
int n;
int ans[1000001];
int d[1000001];
void dfs(int u){
    for(int &v: g[u]) if(d[v]){
        swap(v, g[u].back());
        g[u].pop_back();
        break;
    }
    if(g[u].empty()){
        m[u]=new unordered_map<int, int>;
        (*m[u])[d[u]]++;
        ans[u]=d[u];
    }
    else{
        for(int v: g[u]){
            d[v]=d[u]+1;
            dfs(v);
        }
        sort(g[u].begin(), g[u].end(), [](int x, int y){
            return m[x]->size()>m[y]->size();
        });
        m[u]=m[g[u][0]];
        ans[u]=ans[g[u][0]];
        FFOR(i, 1, g[u].size()){
            for(auto t: *m[g[u][i]]){
                (*m[u])[t.first]+=t.second;
                if(((*m[u])[t.first]>(*m[u])[ans[u]])||(((*m[u])[t.first]==(*m[u])[ans[u]])&&ans[u]>t.first)) ans[u]=t.first;
            }
            m[g[u][i]]->clear();
            delete m[g[u][i]];
        }
        (*m[u])[d[u]]++;
        if((*m[u])[d[u]]>=(*m[u])[ans[u]]) ans[u]=d[u];
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    {
        int x, y;
        FFOR(i, 1, n){
            read(x);
            read(y);
            g[x].pb(y);
            g[y].pb(x);
        }
    }
    d[1]=1;
    dfs(1);
    FOR(i, 1, n){
//        bug(ans[i]);
//        bug(d[i]);
        writeln(ans[i]-d[i]);
    }
}