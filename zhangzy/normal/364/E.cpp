#include<bits/stdc++.h>
using namespace std;

int n,m,k,u,d,pos,ty,cnt[2555],a[2555][2555],ne[2555][2555],nn[2555];
char s[2555][2555];
long long ans;

inline int sqr(int u,int d,int l,int r){
  return a[d][r]-a[d][l-1]-a[u-1][r]+a[u-1][l-1];
}
#define val(x) (ty?sqr(u,d,pos-x+1,pos):sqr(u,d,pos,pos+x-1))
struct P{
  int p1[7],p2[7],c[2555],sz;
  void re(int sz_){
    sz=sz_;
    for (int i=0;i<=6;++i) p1[i]=sz, p2[i]=sz;
    memset(c,0,sizeof (int)*(sz+10));
  }
  void fix(){
    for (int i=0;i<=6;++i){
      for (;p1[i]&&val(p1[i])>=i;--p1[i]);
      for (;p2[i]&&val(p2[i])>i; --p2[i]);
    }
  }
}L,R;

void doit(int l1,int mid,int r2){
  int r1=mid-1,l2=mid+1,cnt,x,nex;
  if (l1>r1+1||l2>r2+1) return;

  nn[n+1]=n+1;
  for (int i=l1;i<=r2;++i) ne[n+1][i]=n+1;
  for (int i=n;i;--i){
    x=0;
    for (int j=r1;j>=l1;--j){
      x+=s[i][j]-'0';
      ne[i][j]= x? i: ne[i+1][j];
    }
    x=0;
    for (int j=l2;j<=r2;++j){
      x+=s[i][j]-'0';
      ne[i][j]= x? i: ne[i+1][j];
    }
    ne[i][mid]= s[i][mid]-'0'? i: ne[i+1][mid];
  }

  for (u=1;u<=n;++u){
    L.re(r1-l1+1);
    R.re(r2-l2+1);
    for (d=u;d<=n;d=nex){
      cnt= sqr(u,d,mid,mid);
      if (cnt>k) break;
      ty=1, pos=r1, L.fix();
      ty=0, pos=l2, R.fix();

      nex=min(ne[d+1][mid-L.p2[6]],ne[d+1][mid+R.p2[6]]);
      nex=min(nex,ne[d+1][mid]);

      for (int i=0;i<=k-cnt;++i)
	ans+=1ll*(nex-d)\
	  *(L.p2[i]-L.p1[i]+!i)*(R.p2[k-cnt-i]-R.p1[k-cnt-i]+!(k-cnt-i));
    }
  }
  doit(l1,l1+r1>>1,r1);
  doit(l2,l2+r2>>1,r2);
}

int main(){
  cin>>n>>m>>k;
  for (int i=1;i<=n;++i){
    scanf("%s",s[i]+1);
    for (int j=1;j<=m;++j)
      a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+s[i][j]-'0';
  }
  doit(1,1+m>>1,m);
  cout<<ans<<endl;
}