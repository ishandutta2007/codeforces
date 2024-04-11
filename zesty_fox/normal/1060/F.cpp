#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define rdl read<ll>

const int N=60;
int n,head[N],tot;
struct Edge{int to,nxt;}e[N<<1];
void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x]};
    head[x]=tot;
}

ll C[N][N];
double fac=1;
void pre(){
    C[0][0]=1;
    for(int i=1;i<=n;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    for(int i=1;i<n;i++) fac*=i;
}

int siz[N];
double f[N][N],g[N];
void dfs(int x,int fa){
    f[x][0]=1;siz[x]=1;
    for(int id=head[x];id;id=e[id].nxt){
        int y=e[id].to;
        if(y==fa) continue;
        dfs(y,x);
        memset(g,0,sizeof(g));
        for(int i=0;i<=siz[y];i++){
            for(int j=1;j<=siz[y];j++) g[i]+=j<=i?f[y][j-1]/2:f[y][i];
        }
        double tmp[N]={0.0};
        for(int i=siz[x]-1;i>=0;i--){
            for(int j=siz[y];j>=0;j--) tmp[i+j]+=f[x][i]*g[j]*C[i+j][j]*C[siz[x]-i-1+siz[y]-j][siz[x]-i-1];
        }
        memcpy(f[x],tmp,sizeof(double)*(siz[x]+siz[y]));
        siz[x]+=siz[y];
    }
}

int main(){
    n=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        addedge(x,y);addedge(y,x);
    }
    pre();
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));dfs(i,0);
        printf("%.6lf\n",f[i][n-1]/fac);
    }
    return 0;
}