//#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;

int n;
char s[202000];

namespace sam{
  int ch[404000][26], fa[404000], dep[404000], cnt=1, las=1;
  int Fa[404000][20], wei[404000], st[404000];
  int dft, dfl[404000], dfr[404000], a[404000];
  vector<int>G[404000];
  
  void add(int x,int who){
    int np=++cnt, p=las; st[np]=wei[np]=who;
    dep[np]=dep[las]+1; las=np;
    for (;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
    if (!p){
      fa[np]=1; return;
    }
    int q=ch[p][x];
    if (dep[q]==dep[p]+1){
      fa[np]=q; return;
    }
    int nq=++cnt;
    dep[nq]=dep[p]+1; memcpy(ch[nq],ch[q],sizeof ch[q]); fa[nq]=fa[q];
    for (;p&&ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
    fa[q]=fa[np]=nq;
  }

  void dfs(int x){
    Fa[x][0]=fa[x];
    for (int i=1;i<=19;++i)
      Fa[x][i]=Fa[Fa[x][i-1]][i-1];
    dfl[x]=dft+1; if (wei[x]) a[++dft]=wei[x];
    for (auto y:G[x]){
      dfs(y); st[x]=st[y];
    }
    dfr[x]=dft;
  }

  int to[404000], ans[404000];
  struct QUE{
    int who, l, r, fl;
  };
  vector<QUE>que[404000];

  namespace bit{
    int c[404000], sz;
    void reset(int sz_){
      memset(c,0,sizeof c); sz=sz_;
    }
    void add(register int x){
      for (;x<=sz;x+=x&-x) ++c[x];
    }
    int que(register int x){
      int t=0;
      for (;x;x-=x&-x) t+=c[x];
      return t;
    }
    int cal(int l,int r){
      return que(r)-que(l-1);
    }
  }

  void gao(){
    bit::reset(n);
    for (int i=1;i<=dft;++i){
      bit::add(a[i]);
      for (auto o:que[i])
	ans[o.who]+=o.fl*bit::cal(o.l,o.r);
    }
  }
  
  void build(){
    for (int i=1;i<=cnt;++i)
      if (fa[i]) G[fa[i]].push_back(i);
    dfs(1);
    //for (int i=1;i<=cnt;++i)
    //  printf("%d : %d %d  %d,%d\n",i,dep[i],st[i],dfl[i],dfr[i]);
    
    for (int i=1;i<=cnt;++i) to[i]=i;
    for (int b=19;b>=0;--b){
      memset(ans,0,sizeof ans);
      for (int i=0;i<=dft;++i) que[i].clear();
      for (int i=1;i<=cnt;++i){
	int aim=Fa[to[i]][b];
	if (aim<=1){
	  ans[i]=2; continue;
	}
	int l=st[i]-dep[i]+dep[aim], r=st[i];
	//printf(" %d %d %d %d\n",dfl[aim],dfr[aim],l,r);
	que[dfl[aim]-1].push_back((QUE){i,l,r,-1});
	que[dfr[aim]].push_back((QUE){i,l,r,1});
      }
      gao();
      for (int i=1;i<=cnt;++i){
	if (ans[i]<=1) to[i]=Fa[to[i]][b];
      }
    }
  }

  int f[404000];
  void sfd(int x){
    f[x]=max(f[fa[x]],1);
    f[x]=max(f[x],f[fa[to[x]]]+1);
    if (x==1) f[x]=0;
    //printf("%d : %d\n",x,to[x]);
    for (auto y:G[x]) sfd(y);
  }
  int getdp(){
    sfd(1);
    return *max_element(f+1,f+cnt+1);
  }
}


int main(){
    cin>>n;
  cin>>s+1;// n=strlen(s+1);
  //n=2e5; for (int i=1;i<=n;++i) s[i]=min(rand()%233,1)+'a';
  for (int i=1;i<=n;++i) sam::add(s[i]-'a',i);
  sam::build();
  cout<<sam::getdp()<<endl;
}