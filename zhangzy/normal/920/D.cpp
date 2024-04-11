#include<bits/stdc++.h>
using namespace std;

bool f[5050][5050], fl[5050];
int pre[5050][5050], n, m, a[5050], aim, sum, to, tof, inf=1e9;

int main(){
  cin>>n>>m>>aim;
  f[0][0]=1;
  for (int i=1;i<=n;++i){
    cin>>a[i]; sum+=a[i]; int x=a[i]%m;
    for (int j=0;j<m;++j)
      f[i][j]=f[i-1][j], pre[i][j]=j;
    for (int j=0;j<m;++j){
      if (j+x>=m) x-=m;
      if (f[i-1][j]&&!f[i][j+x]){
        f[i][j+x]=1; pre[i][j+x]=j;
      }
      if (x<0) x+=m;
    }
  }
  int las=sum-aim;
  if (las<0||!f[n][las%m]) return 0*puts("NO");
  puts("YES");
  int now=las%m;
  for (int i=n;i;--i){
    if (pre[i][now]!=now) fl[i]=1, tof=i;
    else to=i;
    now=pre[i][now];
  }
  now=a[to];
  for (int i=1;i<=n;++i){
    if (i==to||i==tof) continue;
    printf("%d %d %d\n",inf,i,fl[i]? tof: to);
    now+=a[i]*!fl[i];
  }
  if (!to) to= tof-1? tof-1: tof+1;
  if (!tof) tof= to-1? to-1: to+1;
  if (now<aim) printf("%d %d %d\n",(aim-now)/m,tof,to);
  else if (now>aim) printf("%d %d %d\n",(now-aim)/m,to,tof);
}