#include<bits/stdc++.h>
using namespace std;

int n, m, k, l=1e5+7;
struct P{
  int x, y, z, id;
  void in(){ scanf("%d%d%d",&x,&y,&z); }
}mx, mn, p, a[202000];
int fl[101000], die[101000], c[101000];

bool chk(P p){
  return
    p.x>=mn.x && p.x<=mx.x &&
    p.y>=mn.y && p.y<=mx.y &&
    p.z>=mn.z && p.z<=mx.z ;
}

void cg(int x,int v){
  for (;x<=l;x+=x&-x) c[x]=min(c[x],v);
}
int cal(int x){
  int t=1e9;
  for (;x;x-=x&-x) t=min(t,c[x]);
  return t;
}

bool cmp(P a,P b){
  if (a.id) a=(P){max(a.x,mx.x),max(a.y,mx.y),max(a.z,mx.z),a.id};
  if (b.id) b=(P){max(b.x,mx.x),max(b.y,mx.y),max(b.z,mx.z),b.id};
  return a.z==b.z? a.id<b.id: a.z<b.z;
}

void gao(){
  sort(a+1,a+m+k+1,cmp);
  memset(c,11,sizeof c);
  for (int i=1;i<=m+k;++i){
    if (a[i].id){
      P b=a[i];
      b=(P){max(b.x,mx.x),max(b.y,mx.y),max(b.z,mx.z)};
      die[a[i].id]|= cal(b.x)<=b.y;
    }else{
      if (a[i].x<mn.x||a[i].y<mn.y||a[i].z<mn.z) continue;
      cg(a[i].x,a[i].y);
    }
  }
}

void R(int &x){ x=l-x; }
#define REV(x) \
  for (int i=0;i<l*2;++i) R(a[i].x); R(mx.x); R(mn.x);


int main(){
  scanf("%*d%*d%*d"); cin>>n>>m>>k;
  mn=(P){l,l,l};
  for (int i=1;i<=n;++i){
    p.in();
    mx=(P){max(mx.x,p.x),max(mx.y,p.y),max(mx.z,p.z)};
    mn=(P){min(mn.x,p.x),min(mn.y,p.y),min(mn.z,p.z)};
  }
  for (int i=1;i<=m;++i){
    a[i+k].in();
    if (chk(a[i+k])) return puts("INCORRECT"), 0;
  }
  for (int i=1;i<=k;++i){
    a[i].in(), a[i].id=i;
    fl[i]|= chk(a[i]);
  }
  for (int A=0;A<2;++A){
    for (int w=0;w<2;++w){
      for (int D=0;D<2;++D){
	gao();
	REV(z);
      }
      REV(y);
    }
    REV(x);
  }
  puts("CORRECT");
  for (int i=1;i<=k;++i){
    if (fl[i]) puts("OPEN");
    else puts(die[i]? "CLOSED": "UNKNOWN");
  }
}