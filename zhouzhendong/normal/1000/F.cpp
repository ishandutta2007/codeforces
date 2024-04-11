#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int>P;
const int N=500010,M=1333333;
int n,m,i,j,a[N],pre[N],nxt[N],vis[N],L[N],R[N],NXT[N],G[N],ans[N];
int Gp[N],Nxt[N];
P v[M];
inline void up(P&a,const P&b){if(a<b)a=b;}
void change(int x,int a,int b,int c,const P&t){
  up(v[x],t);
  if(a==b)return;
  int mid=(a+b)>>1;
  if(c<=mid)change(x<<1,a,mid,c,t);else change(x<<1|1,mid+1,b,c,t);
}
P ask(int x,int a,int b,int c,int d){
  if(c<=a&&b<=d)return v[x];
  int mid=(a+b)>>1;P t(0,0);
  if(c<=mid)t=ask(x<<1,a,mid,c,d);
  if(d>mid)up(t,ask(x<<1|1,mid+1,b,c,d));
  return t;
}
int main(){
  scanf("%d",&n);
  for(i=1;i<=n;i++)scanf("%d",&a[i]);
  for(i=1;i<=n;i++){
    pre[i]=vis[a[i]];
    vis[a[i]]=i;
    Nxt[i]=Gp[pre[i]];
    Gp[pre[i]]=i;
  }
  for(i=0;i<=500000;i++)vis[i]=n+1;
  for(i=n;i;i--)nxt[i]=vis[a[i]],vis[a[i]]=i;
  scanf("%d",&m);
  for(i=1;i<=m;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    L[i]=x;
    R[i]=y;
    NXT[i]=G[x-1];
    G[x-1]=i;
  }
  //[l..r] pre<l max(nxt)
  for(i=0;i<=n;i++){
    for(j=Gp[i];j;j=Nxt[j])change(1,1,n,j,P(nxt[j],j));
    for(j=G[i];j;j=NXT[j]){
      P t=ask(1,1,n,L[j],R[j]);
      if(t.first>R[j])ans[j]=t.second;
    }
  }
  for(i=1;i<=m;i++)printf("%d\n",a[ans[i]]);
}