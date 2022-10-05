#include<bits/stdc++.h>
using namespace std;

#define ll long long

namespace mxfl{
  const int N=2.1e5, M=4.1e6;
  typedef int str;
  const str inf=1e9;
  
  struct E{
    int to; str fl; int nex;
  }e[M];
  int n, hea[N], cne, cur[N], st, en, d[N];
  void init(int n_=N-1){
    n=n_; cne=1;
    memset(hea,0,sizeof (int)*(n+1));
  }
  int adde(int u,int v,str w,str bw=0){
    e[++cne]=(E){v,w,hea[u]}; hea[u]=cne;
    e[++cne]=(E){u,bw,hea[v]}; hea[v]=cne;
    return cne;
  }
  void banv(int x){
    for (int i=hea[x];i;i=e[i].nex){
      e[i].fl=e[i^1].fl=0;
    }
  }
  void bane(int x,int y){
    for (int i=hea[x];i;i=e[i].nex){
      if (e[i].to==y) e[i].fl=e[i^1].fl=0;
    }
  }
  bool bfs(){
    memset(d,33,sizeof d); d[st]=0;
    queue<int>q; q.push(st);
    for (int x,y,z;!q.empty();){
      x=q.front(); q.pop(); if (x==en) return 1;
      for (int i=hea[x];i;i=e[i].nex){
        if (!e[i].fl) continue;
        y=e[i].to; z=d[x]+1;
        if (z<d[y]) d[y]=z, q.push(y);
      }
    }
    return 0;
  }
  str dfs(int x,str F){
    if (x==en||!F) return F;
    str las=F;
    for (int &i=cur[x];i;i=e[i].nex){
      int y=e[i].to;
      if (!e[i].fl||d[y]!=d[x]+1) continue;
      str t=dfs(y,min(las,e[i].fl));
      las-=t; e[i].fl-=t; e[i^1].fl+=t;
      if (!las) break;
    }
    return F-las;
  }
  str realmain(int st_,int en_){
    st=st_; en=en_;
    str ans=0;
    for (;bfs();){
      memcpy(cur,hea,sizeof (int)*(n+1));
      ans+=dfs(st,inf);
    }
    return ans;
  }
}

int n, m, s, t, ss, tt, tot, ide[101000];

map<int,int>idx, idy;
int cnt[202000], mn[202000], cor, cob, rev;

int main(){
    cin>>n>>m; mxfl::init();
    cin>>cor>>cob;
    s=++tot; t=++tot; ss=++tot; tt=++tot;
    memset(mn,33,sizeof mn);
    for (int i=1;i<=n;++i){
        int x, y; scanf("%d%d",&x,&y);
        if (!idx.count(x)) idx[x]=++tot;
        if (!idy.count(y)) idy[y]=++tot;
        int xx=idx[x], yy=idy[y];
        ++cnt[xx]; ++cnt[yy];
        ide[i]=mxfl::adde(xx,yy,1);
    }
    int need=0;
    for (int i=1;i<=m;++i){
        int t, x, v; scanf("%d%d%d",&t,&x,&v);
        int xx= t==1? idx[x]: idy[x];
        mn[xx]=min(mn[xx],v);
    }
    for (int ty=1;ty<=2;++ty){
        map<int,int>mp= ty==1? idx: idy;
        for (auto o:mp){
            int xx= o.second, v=mn[xx];
            int l=(cnt[xx]-v+1)/2, r=cnt[xx]-l;
            if (cnt[xx]<=v) l=0, r=cnt[xx];
            //printf(" %d %d %d %d  %d %d %d ",ty,o.first,l,r,s,t,xx);
            if (l>r){
                puts("-1"); exit(0);
            }
            {
                int u, v;
                if (ty==1) u=s, v=xx;
                else u=xx, v=t;
                //printf("  %d %d\n",u,v);
                need+=l; mxfl::adde(ss,v,l); mxfl::adde(u,tt,l);
                mxfl::adde(u,v,r-l);
            }
        }
    }
    mxfl::adde(t,s,1e9);
    {
        int tmp=mxfl::realmain(ss,tt);
        if (tmp!=need){
            puts("-1"); exit(0);
        }
    }
    mxfl::banv(ss); mxfl::banv(tt);
    mxfl::bane(s,t);
    mxfl::realmain(s,t);
    ll ans=0; string str;
    for (int i=1;i<=n;++i)
        if (mxfl::e[ide[i]].fl){
            if (cor>cob) ans+=cob, str+='b';
            else ans+=cor, str+='r';
        }else{
            if (cor>cob) ans+=cor, str+='r';
            else ans+=cob, str+='b';
        }
    cout<<ans<<endl<<str<<endl;
}