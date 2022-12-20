#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

const int INF=0x3f3f3f3f,N=1000010;
#define rdi read<int>
#define rdl read<ll>
#define mp make_pair
#define pb push_back
#define fi first
#define sec second

int n,a[N][3],pos[N],vis[N];
vector<int> e[N],c[3];
ll sumc[3];
void dfs(int x,int col){
    vis[x]=1;
    c[col].pb(x);
    sumc[col]+=x;
    for(auto y:e[x]){
        if(vis[y]) continue;
        dfs(y,3-col);
    }
}

void solve(){
    n=rdi();
    if(n&1){
        puts("Second");
        fflush(stdout);
        for(int i=1;i<=n;i++) pos[i]=0,e[i].clear();
        c[1].clear();c[2].clear();
        for(int i=1;i<=(n<<1);i++){
            int x=rdi();
            a[x][++pos[x]]=i;
        }
        for(int i=1;i<=n;i++){
            e[a[i][1]].pb(a[i][2]);
            e[a[i][2]].pb(a[i][1]);
            e[i].pb(i+n),e[i+n].pb(i);
        }
        for(int i=1;i<=(n<<1);i++){
            if(!vis[i]) dfs(i,1);
        }
        for(int i=1;i<=2;i++){
            if(sumc[i]%(n<<1)==0){
                for(auto x:c[i]) printf("%d ",x);
                puts("");fflush(stdout);
                break;
            }
        }
    }
    else{
        puts("First");
        fflush(stdout);
        for(int i=1;i<=(n<<1);i++) printf("%d ",(i>n?i-n:i));
        puts("");fflush(stdout);
    }
    return;
}

int main(){
    solve();
    return 0;
}