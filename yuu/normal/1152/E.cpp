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
int v[100001];
int b[100001];
int c[100001];
int x[100001];
int n, m;
map <int, int> M;
vector <int> g[100001];
bool done[100001];
deque <int> path;
void dfs(int u){
    if((!path.empty())&&(path.front()==u)) return;
    while(true){
        while((!g[u].empty())&&(done[g[u].back()])) g[u].pop_back();
        if(g[u].empty()) return;
        path.pb(u);
        int v=x[g[u].back()]^u;
        done[g[u].back()]=1;
        dfs(v);
        path.push_front(u);
        path.pop_back();
    }
}

void check(){
    int x;
    multiset <pair <int, int>> s;
    FFOR(i, 0, n-1){
        s.insert(mp(min(path[i], path[i+1]), max(path[i], path[i+1])));
//        bug(min(path[i], path[i+1]));
//        bug(max(path[i], path[i+1]));
    }
    FFOR(i, 1, n){
        if(s.find(mp(b[i], c[i]))==s.end()) exit(-4);
        s.erase(s.find(mp(b[i], c[i])));
    }
}
void find_euler_path(){
    vector <int> odd;
    FOR(i, 1, m) if(g[i].size()%2) odd.pb(i);
    if(odd.size()){
        assert(odd.size()==2);
        b[n]=odd[0];
        c[n]=odd[1];
        x[n]=b[n]^c[n];
        g[odd[0]].pb(n);
        g[odd[1]].pb(n);
    }
    else done[n]=1;
    dfs(1);
    FOR(i, 1, n) if(!done[i]){
        puts("-1");
        exit(0);
    }
    if(odd.size()){
        while(!(((path[0]==b[n])&&(path[1]==c[n]))||((path[1]==b[n])&&(path[0]==c[n])))){
            path.pb(path.front());
            path.pop_front();
        }
        path.pb(path.front());
        path.pop_front();
    }
    else path.pb(path.front());
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
            freopen(taskname".out", "w", stdout);
    #endif // Aria
    read(n);
    FFOR(i, 1, n){
        read(b[i]);
        M[b[i]]=1;
    }
    FFOR(i, 1, n){
        read(c[i]);
        M[c[i]]=1;
    }
    FFOR(i, 1, n) if(b[i]>c[i]){
        puts("-1");
        #ifdef Aria
        return -1;
        #endif // Aria
        return 0;
    }
    if(M.size()>n){
        puts("-1");
        #ifdef Aria
        return -1;
        #endif // Aria
        return 0;
    }
    for(auto &c: M){
        m++;
        c.second=m;
        v[m]=c.first;
    }
    FFOR(i, 1, n) b[i]=M[b[i]];
    FFOR(i, 1, n) c[i]=M[c[i]];
    FFOR(i, 1, n){
        x[i]=b[i]^c[i];
        g[b[i]].pb(i);
        g[c[i]].pb(i);
    }
    int odd_cnt=0;
    FOR(i, 1, m) odd_cnt+=g[i].size()%2;
    if(odd_cnt>2){
        puts("-1");
        #ifdef Aria
        return -1;
        #endif // Aria
        return 0;
    }
    find_euler_path();
    for(auto &x: path){
        write(v[x]);
        putchar(' ');
    }
    #ifdef Aria
        check();
    #endif // Aria
}