#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
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

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010;
int n,a[N],ans,g[N];
vi e[N],f[N];
void dfs(int x,int fa){
    int siz=e[x].size();
    for(int i=0;i<siz;i++){
        int y=e[x][i];
        if(y==fa) siz--,e[x].erase(e[x].begin()+i),i--;
        else dfs(y,x);
    }
}

void dfs1(int x){
    int siz=e[x].size();
    f[x].resize(e[x].size()+1);f[x][e[x].size()]=a[x];
    for(int i=siz-1;i>=0;i--){
        int y=e[x][i];
        dfs1(y);
        f[x][i]=max(f[x][i+1]+f[y][0],f[x][i+1]);
    }
}

void dfs2(int x){
    int siz=e[x].size(),maxn=0;
    for(int i=0;i<siz;i++){
        int y=e[x][i];
        g[y]=max(g[y],g[x]+maxn+f[x][i+1]);
        maxn=max(maxn,maxn+f[y][0]);
        dfs2(y);
    }
}

int main(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=(rdi()?1:-1);
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    dfs(1,0);dfs1(1);dfs2(1);
    for(int i=1;i<=n;i++) printf("%d ",f[i][0]+g[i]);
    puts("");
    return 0;
}