#include<cstdio>
#include<algorithm>
#define N 3000005
#define INF 1000005
using namespace std;
struct arr{int go,next;}a[N*2];
int M[N],f[N][2],dis[N][2],pre[N],deep[N],end[N];
int D,x,y,n,m,i,root,cnt,ans,mobie;
inline void add(int u,int v){a[++cnt].go=v;a[cnt].next=end[u];end[u]=cnt;}
void dfs(int k,int fa)
{
  dis[k][0]=(M[k])?0:-INF;dis[k][1]=-INF;
  pre[k]=(M[k])?k:INF;
  for (int i=end[k];i;i=a[i].next)
  {
    int go=a[i].go;if (go==fa) continue;
    dfs(go,k);if (dis[go][0]==-INF) continue;
    if (dis[go][0]+1>dis[k][0])
    {
      dis[k][1]=dis[k][0];
      dis[k][0]=dis[go][0]+1;
      pre[k]=go;continue;
    }
    dis[k][1]=max(dis[k][1],dis[go][0]+1);
  }
}
void find(int k,int fa)
{
  for (int i=end[k];i;i=a[i].next)
  {
    int go=a[i].go;if (go==fa) continue;
    f[go][0]=dis[go][0];f[go][1]=dis[go][1];
    if (go==pre[k]) 
    {
      if (f[k][1]+1>f[go][0]) f[go][0]=f[k][1]+1,pre[go]=0;
      else f[go][1]=max(f[go][1],f[k][1]+1);
    }
    else
    {
      if (f[k][0]+1>f[go][0]) f[go][0]=f[k][0]+1,pre[go]=0;
      f[go][1]=max(f[go][1],f[k][0]+1);
    }
    find(go,k);
  }
}
int main()
{
  scanf("%d%d%d",&n,&m,&D);
  for (i=1;i<=m;i++) scanf("%d",&mobie),M[mobie]=1;
  for (i=1;i<n;i++)
    scanf("%d%d",&x,&y),add(x,y),add(y,x);
  dfs(1,-1);f[1][0]=dis[1][0];f[1][1]=dis[1][1];
  find(1,-1);
  for (i=1;i<=n;i++)
    if (f[i][0]<=D) ans++;
  printf("%d",ans);
  return 0;
}