#include<bits/stdc++.h>
#define ll long long
using namespace std;

int T, cnt=1, fa[404000][20], pre[404000][20], dep[404000];
ll mx[404000][20], sum[404000][20], ans;

int fin(int x,ll aim){
  for (int i=19;i>=0;--i)
    if (mx[x][i]<aim)
      x=fa[x][i];
  return x;
}
int cal(int x,ll las){
  for (int i=19;i>=0;--i)
    if (sum[x][i]<=las){
      las-=sum[x][i];
      x=pre[x][i];
    }
  return x;
}

int main(){
  dep[1]=1;
  for (cin>>T;T--;){
    ll t, x, y;
    scanf("%lld%lld%lld",&t,&x,&y);
    x^=ans; y^=ans;
    if (t==1){
      fa[++cnt][0]=x; mx[cnt][0]=y;
      for (int i=1;i<=19;++i){
        fa[cnt][i]=fa[fa[cnt][i-1]][i-1];
        mx[cnt][i]=max(mx[cnt][i-1],mx[fa[cnt][i-1]][i-1]);
      }
      pre[cnt][0]=fin(x,y); sum[cnt][0]=y;
      dep[cnt]=dep[pre[cnt][0]]+1;
      for (int i=1;i<=19;++i){
        pre[cnt][i]=pre[pre[cnt][i-1]][i-1];
        sum[cnt][i]=sum[cnt][i-1]+sum[pre[cnt][i-1]][i-1];
      }
    }else{
      ans=dep[x]-dep[cal(x,y)];
      printf("%lld\n",ans);
    }
  }
}