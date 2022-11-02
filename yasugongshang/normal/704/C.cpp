#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
int read(){
    char c;int s=0,t=1;
    while(!isdigit(c=getchar()))if(c=='-')t=-1;
    do{s=s*10+c-'0';}while(isdigit(c=getchar()));
    return s*t;
}
const int maxn=300010,MOD=1e9+7;
int f[maxn][2][2],dp[2][2],tot=1,first[maxn],in[maxn],ans[maxn][2],cnt,fir;
int n,m,c[maxn][10],d[maxn][10],uv,uuv,vv,be,fr,p[maxn];
bool vis[maxn];
struct edge{int v,w,from;}e[maxn*3];
void insert(int u,int v,int w){tot++;e[tot].v=v;e[tot].w=w;e[tot].from=first[u];first[u]=tot;in[v]++;}
int M(int x){return x>=MOD?x-MOD:x;}
void dfs(int x,int fa,int w){
    bool ok=1;vis[x]=1;
    f[x][0][0]=M(f[fa][0][w]+f[fa][1][w^1]);
    f[x][1][0]=M(f[fa][0][1]+f[fa][1][1]);
    f[x][0][1]=M(f[fa][0][w^1]+f[fa][1][w]);
    f[x][1][1]=M(f[fa][0][0]+f[fa][1][0]); 
    for(int i=first[x];i;i=e[i].from)if(e[i].v!=fa){
        ok=0;
        dfs(e[i].v,x,e[i].w);
    }
    if(ok){
        
        ans[cnt][1]=M(ans[cnt][1]+M(f[x][0][1]+(p[x]?0:f[x][1][1])));
        ans[cnt][0]=M(ans[cnt][0]+M(f[x][0][0]+(p[x]?0:f[x][1][0])));
    }
}
void round(int x,int fa,int w,int b){
    vis[x]=1;
    f[x][0][0]=M(f[fa][0][w]+f[fa][1][w^1]);
    f[x][1][0]=M(f[fa][0][1]+f[fa][1][1]);
    f[x][0][1]=M(f[fa][0][w^1]+f[fa][1][w]);
    f[x][1][1]=M(f[fa][0][0]+f[fa][1][0]);
    for(int i=first[x];i;i=e[i].from)if(i!=fr&&(i^1)!=b){
        if(e[i].v!=be)round(e[i].v,x,e[i].w,i);
        else{
            if(!fir){
                ans[cnt][1]=M(f[x][e[i].w^1][0]+f[x][e[i].w][1]);
                ans[cnt][0]=M(f[x][e[i].w][0]+f[x][e[i].w^1][1]);
            }
            else{
                ans[cnt][1]=M(ans[cnt][1]+M(f[x][0][0]+f[x][1][0]));
                ans[cnt][0]=M(ans[cnt][0]+M(f[x][0][1]+f[x][1][1]));
            }
        }
    }
}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++){
        int k=read();if(k==1)p[i]=1;
        for(int j=1;j<=k;j++){
            int x=read();
            if(x<0)c[-x][++c[-x][0]]=i,d[-x][c[-x][0]]=1;
            else c[x][++c[x][0]]=i;
        }
    }
    for(int i=1;i<=m;i++){
        if(c[i][0]==0)uv++;
        if(c[i][0]==2){
            if(c[i][1]==c[i][2]){p[c[i][1]]=2;if(d[i][1]==d[i][2])uuv++;else vv++;continue;}
            insert(c[i][1],c[i][2],d[i][1]^d[i][2]);
            insert(c[i][2],c[i][1],d[i][1]^d[i][2]);
        }
    }
    for(int i=1;i<=n;i++)if(!vis[i]&&in[i]==1){
        cnt++;
        f[0][0][0]=1;
        dfs(i,0,0);
        if(!p[i]){
            dfs(i,0,1);
        }
        f[0][0][0]=0;
    }
    for(int i=1;i<=n;i++)if(!vis[i]&&in[i]==2){
        cnt++;
        f[i][0][0]=1;fir=0;be=i;vis[i]=1;fr=e[first[i]].from;
        round(e[first[i]].v,i,e[first[i]].w,first[i]);
        f[i][0][0]=0;f[i][1][0]=1;fir=1;
        round(e[first[i]].v,i,e[first[i]].w,first[i]);
    }
    for(int i=1;i<=n;i++)if(!vis[i]&&in[i]==0&&p[i]!=2){cnt++;ans[cnt][0]=1;ans[cnt][1]=p[i]?1:3;}
    int x=0;
    dp[x][vv&1]=1;
    for(int i=1;i<=vv;i++)dp[x][vv&1]=dp[x][vv&1]*2%MOD;
    for(int i=1;i<=uuv;i++){
        x=1-x;
        dp[x][0]=M(dp[1-x][0]+dp[1-x][1]);
        dp[x][1]=M(dp[1-x][0]+dp[1-x][1]);
    }
    for(int i=1;i<=cnt;i++){
        x=1-x;
        dp[x][0]=(1ll*ans[i][0]*dp[1-x][0]+1ll*ans[i][1]*dp[1-x][1])%MOD;
        dp[x][1]=(1ll*ans[i][1]*dp[1-x][0]+1ll*ans[i][0]*dp[1-x][1])%MOD;
    }
    for(int i=1;i<=uv;i++)dp[x][1]=dp[x][1]*2%MOD;
    printf("%d",dp[x][1]);
    return 0;
}