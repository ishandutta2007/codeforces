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
#define abs(x) ((x)>=0?(x):(-(x)))

const int N=2010;
int n,X[N],Y[N],vis[N],to[N];
ll k[N],c[N],e[N][N];
inline int dist(int x1,int y1,int x2,int y2){return abs(x1-x2)+abs(y1-y2);}
ll sum,dis[N];
void prim(){
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    for(int i=1;i<=n+1;i++){
        int p;ll minx=1e18;
        for(int j=1;j<=n+1;j++){
            if(vis[j]||dis[j]>minx) continue;
            minx=dis[j],p=j;
        }
        vis[p]=1;
        for(int j=1;j<=n+1;j++){
            if(vis[j]||e[p][j]>dis[j]) continue;
            dis[j]=e[p][j],to[j]=p;
        }
    }
    for(int i=1;i<=n+1;i++) sum+=dis[i];
}

vector<int> node;
int main(){
    n=rdi();
    for(int i=1;i<=n;i++) X[i]=rdi(),Y[i]=rdi();
    for(int i=1;i<=n;i++) c[i]=rdi();
    for(int i=1;i<=n;i++) k[i]=rdi();
    memset(e,0x3f,sizeof(e));
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++) e[i][j]=e[j][i]=(k[i]+k[j])*dist(X[i],Y[i],X[j],Y[j]);
    }
    for(int i=1;i<=n;i++) e[i][n+1]=e[n+1][i]=c[i];
    prim();
    printf("%lld\n",sum);
    for(int i=1;i<=n;i++){
        if(to[i]==n+1) node.push_back(i);
    }
    if(to[n+1]<=n&&to[n+1]>=1) node.push_back(to[n+1]);
    printf("%d\n",node.size());
    for(auto x:node) printf("%d ",x);
    puts("");
    node.clear();
    for(int i=1;i<=n;i++){
        if(to[i]<=n&&to[i]>=1) node.push_back(i);
    }
    printf("%d\n",node.size());
    for(auto x:node) printf("%d %d\n",x,to[x]);
    return 0;
}