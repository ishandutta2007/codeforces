#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=210;

int n;
bool f[N][N][N];

struct Dsu{
    int f[N];
    void init(int n) {iota(f+1,f+n+1,1);}
    int find(int x) {return x==f[x]?f[x]:f[x]=find(f[x]);}
    void merge(int x,int y) {f[find(x)]=find(y);}
}d;

vi mem[N];
int fa[N],vis[N];

vi t[N];int dis[N];
void dfs(int x,int fa) {for(auto y:t[x]) if(y!=fa) dis[y]=dis[x]+1,dfs(y,x);}
bool check(){
    for(int i=1;i<=n;i++) t[i].clear();
    for(int i=2;i<=n;i++){
        if(!fa[i]) return false;
        t[fa[i]].pb(i),t[i].pb(fa[i]);
    }
    for(int i=1;i<=n;i++){
        dis[i]=0;dfs(i,0);
        for(int j=1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                if(f[j][k][i]!=(dis[j]==dis[k])) return false;
    }
    return true;
}

bool test(vi lst1){
    vi lst[2]={{1},lst1};
    for(int i=1;i<=n;i++) fa[i]=0;
    for(auto x:lst1) fa[x]=1;
    while(true){
        vi tmp;
        for(int i=2;i<=n;i++){
            if(!fa[i]){
                for(auto y:lst[1])
                    if(f[fa[y]][i][y]) {fa[i]=y,tmp.pb(i);goto nxt;}
                nxt:;
            }
        }
        if(tmp.empty()) break;
        lst[0]=lst[1],lst[1]=tmp;
    }
    return check();
}

bool construct(){
    d.init(n);
    for(int i=2;i<=n;i++) for(int j=i+1;j<=n;j++) if(f[i][j][1]) d.merge(i,j);
    for(int i=2;i<=n;i++) mem[d.find(i)].pb(i);
    for(int i=2;i<=n;i++) if(mem[i].size()&&test(mem[i])) return true;
    return false;
}

void clear(){
    for(int i=1;i<=n;i++) t[i].clear(),mem[i].clear(),dis[i]=fa[i]=vis[i]=0;
}

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            static char s[N];scanf("%s",s+1);
            for(int k=1;k<=n;k++) f[i][j][k]=f[j][i][k]=s[k]-'0';
        }
    }
    if(construct()) {puts("Yes");for(int i=2;i<=n;i++) cout<<fa[i]<<' '<<i<<'\n';}
    else puts("No");
    clear();
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}