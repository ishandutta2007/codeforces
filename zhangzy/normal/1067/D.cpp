#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define db double

struct mat{
  db v[3][3];
}bas[101000], f[40], one, nil, org;
mat operator * (const mat &a,const mat &b){
  static mat c;
  for (int i=0;i<3;++i)
    for (int j=0;j<3;++j){
      db t=0;
      for (int k=0;k<3;++k)
	t+= a.v[i][k]*b.v[k][j];
      c.v[i][j]=t;
    }
  return c;
}

int n; ll m; db b;
#define pdd pair<db,db>
#define fi first
#define se second
pdd p[101000];

struct node{
  int id; ll las;
  mat pre;
};
vector<node>st;

int main(){
  cin>>n>>m;
  for (int i=1;i<=n;++i){
    db x, y, z;
    scanf("%lf%lf%lf",&x,&y,&z);
    b=max(b,y*z);
    p[i]=(pdd){x*z,z};
  }
  sort(p+1,p+n+1,greater<pdd>());
  one.v[0][0]=one.v[1][1]=one.v[2][2]=1;
  org.v[2][0]=1;
  for (int i=1;i<=n;++i){
    mat &tmp=bas[i];
    tmp.v[0][0]=1-p[i].se;
    tmp.v[0][1]=p[i].se;
    tmp.v[0][2]=p[i].fi;
    tmp.v[1][1]=1;
    tmp.v[1][2]=b;
    tmp.v[2][2]=1;
  }
  st.push_back((node){1,m,org});
  
  for (int i=2;i<=n;++i){
    for (;;){
      if (
	  (bas[i]*st.back().pre).v[0][0]  >
	  (bas[st.back().id]*st.back().pre).v[0][0]
	  ) st.pop_back();
      else break;
    }
    if (st.back().las==0) continue;
    node bk=st.back();
    f[0]=bas[bk.id]; for (int j=1;j<=35;++j) f[j]=f[j-1]*f[j-1];
    for (int j=35;j>=0;--j)
      if (
	  bk.las-(1ll<<j)>=1&&
	  (bas[i]*f[j]*bk.pre).v[0][0]  <=
	  (bas[bk.id]*f[j]*bk.pre).v[0][0]
	  ){
	bk.pre=f[j]*bk.pre;
	bk.las-=1ll<<j;
      }
    bk.pre=bas[bk.id]*bk.pre;
    --bk.las;
    if (bk.las) bk.id=i, st.push_back(bk);
  }
  ll i=st.back().id, y=st.back().las;
  mat ans=st.back().pre, x=bas[i]; 
  for (;y;x=x*x,y>>=1)
    if (y&1) ans=x*ans;
  printf("%.15lf\n",ans.v[0][0]);
}