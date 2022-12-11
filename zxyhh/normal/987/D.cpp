#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<string>
#include<queue>
#include<cmath>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
#define ldb long double
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define maxn 100005
using namespace std;
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
void write(ll x){ if (x>=10) write(x/10),putchar(x%10+'0'); else putchar(x+'0'); }
inline void wrt(ll x,int p){if (x<0) putchar('-'),x=-x; write(x); if (p) putchar(p);}
int nx[maxn<<1],to[maxn<<1],hd[maxn<<1],cnt;
inline void add(int u,int v){to[++cnt]=v,nx[cnt]=hd[u],hd[u]=cnt;}
int col[maxn][105];
int q[maxn],h,t;
int n,m,k,s,a[maxn];
inline void bfs(int cl)
{
    h=0;t=0;
    rep(i,1,n) if (a[i]==cl) q[++t]=i;
    else col[i][cl]=0x7fffffff;
    while(h<t){
        h++;
        cross(i,q[h])
            if (col[to[i]][cl]>col[q[h]][cl]+1) 
            col[to[i]][cl]=col[q[h]][cl]+1,q[++t]=to[i];
    }
}
int main()
{
    n=rd(),m=rd(),k=rd(),s=rd();
    rep(i,1,n) a[i]=rd();
    rep(i,1,m){
        int x=rd(),y=rd();
        add(x,y),add(y,x);
    }
    rep(i,1,k) bfs(i);
    int ans=0;
    rep(i,1,n){
        sort(col[i]+1,col[i]+1+k);ans=0;
        rep(j,1,s) ans+=col[i][j];
        if (i!=n) wrt(ans,' ');
        else wrt(ans,'\n');
    }
}