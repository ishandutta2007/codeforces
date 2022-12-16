#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N=200010,M=21,INF=0x3f3f3f3f3f3f3f3f;
ll n,m,dis[N],h[N],A[N],B[N];
ll maxn[N][M],minx[N][M],ans;
int lg2[N];
inline int which_max(int x,int y){return A[x]>A[y]?x:y;}
inline int which_min(int x,int y){return B[x]<B[y]?x:y;}
void init(){
    for(int i=2;i<=2*n;i++) lg2[i]=lg2[i>>1]+1;
    ll sum=0;A[0]=-INF,B[0]=INF;
    for(int i=1;i<=2*n;i++){
        sum+=dis[i];
        A[i]=sum+h[i],B[i]=sum-h[i];
        maxn[i][0]=minx[i][0]=i;
    }
    for(int j=1;j<=lg2[2*n];j++){
        for(int i=1;i<=2*n-(1<<j)+1;i++){
            maxn[i][j]=which_max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
            minx[i][j]=which_min(minx[i][j-1],minx[i+(1<<(j-1))][j-1]);
        }
    }
}

inline int query_max(int l,int r){
    if(l>r) return 0;
    int tmp=lg2[r-l];
    return which_max(maxn[l][tmp],maxn[r-(1<<tmp)+1][tmp]);
}

inline int query_min(int l,int r){
    if(l>r) return 0;
    int tmp=lg2[r-l];
    return which_min(minx[l][tmp],minx[r-(1<<tmp)+1][tmp]);
}

inline ll query(int l,int r){
    int x=query_max(l,r),y=query_min(l,r);
    if(x!=y) return A[x]-B[y];
    int x1=which_max(query_max(l,x-1),query_max(x+1,r));
    int y1=which_min(query_min(l,y-1),query_min(y+1,r));
    return max(A[x1]-B[y],A[x]-B[y1]);
}

int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&dis[i%n+1]);
    for(int i=1;i<=n;i++) scanf("%lld",&h[i]),h[i]*=2;
    for(int i=n+1;i<=n*2;i++) dis[i]=dis[i-n],h[i]=h[i-n];
    init();
    while(m--){
        int l,r;scanf("%d%d",&l,&r);
        printf("%lld\n",l<=r?query(r+1,l+n-1):query(r+1,l-1));
    }
    return 0;
}