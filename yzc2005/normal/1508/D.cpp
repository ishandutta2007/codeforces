#include<bits/stdc++.h>
using namespace std;
#define EB emplace_back
const int N=2005;
int n,x[N],y[N],p[N],m,f[N],q[N];
vector<pair<int,int>>ans;
int get(int x){return x==f[x]?x:(f[x]=get(f[x]));}
bool check(int a,int b){return 1ll*(x[b]-x[a])*(-y[a])-1ll*(-x[a])*(y[b]-y[a])>0;}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;++i)scanf("%d%d%d",&x[i],&y[i],&p[i]),f[i]=i;
  for(int i=1;i<=n;++i)if(p[i]!=i)q[0]=i;
  if(!q[0])return puts("0"),0;
  for(int i=1;i<=n;++i)if(i!=q[0]&&p[i]!=i)q[++m]=i,x[i]-=x[q[0]],y[i]-=y[q[0]];
  sort(q+1,q+m+1,[&](int a,int b){return atan2(y[a],x[a])<atan2(y[b],x[b]);});
  for(int i=0;i<=m;++i)f[get(q[i])]=get(p[q[i]]);
  q[m+1]=q[1];for(int i=1;i<=m;++i)if(get(q[i])!=get(q[i+1])&&check(q[i],q[i+1]))ans.EB(q[i],q[i+1]),swap(p[q[i]],p[q[i+1]]),f[get(q[i])]=get(q[i+1]);
  for(int cur=p[q[0]];cur!=q[0];cur=p[cur])ans.EB(cur,q[0]);
  printf("%d\n",int(ans.size()));for(auto&p:ans)printf("%d %d\n",p.first,p.second);
  return 0;
}