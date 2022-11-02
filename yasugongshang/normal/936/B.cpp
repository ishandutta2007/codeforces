#include<cstdio>
#include<algorithm>
#define N 110000
using namespace std;
inline char gc(){
    static char now[1<<16],*S,*T;
    if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
    return *S++;
}
inline int read(){
    int x=0,f=1;char ch=gc();
    while(ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=gc();}
    while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=gc();
    return x*f;
}
struct node{
    int y,next;
}data[N<<1];
bool dp[N][2],cir;int h[N],num,visit[N][2],out[N],next[N][2],n,m;
inline bool dfs(int x,int s){
    if (!out[x]) return s==1;
    if (visit[x][s]==2) return dp[x][s];
    visit[x][s]=1;bool t=0;
    for (int i=h[x];i;i=data[i].next){
        int y=data[i].y;if (visit[y][s^1]==1) {cir=1;continue;}
        if (dfs(y,s^1)) t=1,next[x][s]=y;
    }visit[x][s]=2;return dp[x][s]=t;
}
inline void print(int x,int s){
    printf("%d ",x);if (next[x][s]) print(next[x][s],s^1);
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;++i){
        int xx=read();
        while(xx--){
            int to=read();++out[i];
            data[++num].y=to;data[num].next=h[i];h[i]=num;
        }
    }int st=read();
    if (dfs(st,0))puts("Win"),print(st,0);else
    if (cir) puts("Draw");else puts("Lose");
    return 0;
}