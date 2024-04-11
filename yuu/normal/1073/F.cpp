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
#define taskname "1073F"
#define y1 Kafuu
#define y2 Chino
class data{
public:
    pair <int, int> value;
    int a, b;
    friend bool operator >(data A, data B){
        return A.value>B.value;
    }
    friend data max(data A, data B){
        return (A>B)?A:B;
    }
    data(pair <int, int> value, int a, int b){
        this->value=value;
        this->a=a;
        this->b=b;
    }
    data(){
        value=mp(-1e9, -1e9);
        a=b=0;
    }
    data travel_edge_single(){
        data res=(*this);
        res.value.second++;
        return res;
    }
    data travel_edge_double(){
        data res=(*this);
        res.value.first++;
        res.value.second+=2;
        return res;
    }
};
data combine_single(data A, data B){///combine two single paths
    assert(A.b==0);
    assert(B.b==0);
    if(A.value.first<0||B.value.first<0) return data();
    return data(mp(1, A.value.second+B.value.second), A.a, B.a);
}
pair <int, int> best;
int x1, y1, x2, y2;
void combine_double(data A, data B){///combine two double paths and update answer
    pair <int, int> res=mp(A.value.first+B.value.first, A.value.second+B.value.second);
    if(res>best){
        best=res;
        x1=A.a;
        x2=A.b;
        y1=B.a;
        y2=B.b;
    }
}
data f[200001][2];
vector <int> g[200001];
bool done[200001];
void dfs(int u){
    done[u]=1;
    for(int &v: g[u]) if(done[v]){
        swap(v, g[u].back());
        g[u].pop_back();
        break;
    }
    f[u][0]=data(mp(0, 0), u, 0);
    data best;
    for(int v: g[u]){
        dfs(v);
        f[u][0]=max(f[u][0], f[v][0].travel_edge_single());
        f[u][1]=max(f[u][1], combine_single(best, f[v][0].travel_edge_single()));
        f[u][1]=max(f[u][1], f[v][1].travel_edge_double());
        best=max(best, f[u][0]);
    }
}
data best_single[200001];
data best_double[200001];
void dfs2(int u){
    data best_double_now=best_double[u];
    data best_single_now=best_single[u];
    for(int v: g[u]){
        combine_double(best_double_now, f[v][1].travel_edge_double());
        best_single[v]=max(best_single[v], best_single_now.travel_edge_single());
        best_double[v]=max(best_double[v], best_double_now.travel_edge_double());
        best_double_now=max(best_double_now, f[v][1].travel_edge_double());
        best_double_now=max(best_double_now, combine_single(best_single_now, f[v][0].travel_edge_single()));
        best_single_now=max(best_single_now, f[v][0].travel_edge_single());
    }
    best_double_now=best_double[u];
    best_single_now=best_single[u];
    reverse(g[u].begin(), g[u].end());
    for(int v: g[u]){
        combine_double(best_double_now, f[v][1].travel_edge_double());
        best_single[v]=max(best_single[v], best_single_now.travel_edge_single());
        best_double[v]=max(best_double[v], best_double_now.travel_edge_double());
        best_double_now=max(best_double_now, f[v][1].travel_edge_double());
        best_double_now=max(best_double_now, combine_single(best_single_now, f[v][0].travel_edge_single()));
        best_single_now=max(best_single_now, f[v][0].travel_edge_single());
    }
    for(int v: g[u]) dfs2(v);
}
int n;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    {
        int u, v;
        FFOR(i, 1, n){
            read(u);
            read(v);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    dfs(1);
    dfs2(1);
    bug(best.first);
    bug(best.second);
    printf("%d %d\n%d %d\n", x1, y1, x2, y2);
}