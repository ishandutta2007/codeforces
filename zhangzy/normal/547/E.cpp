#include<bits/stdc++.h>
using namespace std;

struct TR{
  int lc, rc, sz;
}tr[5001000];
int cntr, rt[202000];

int n, q, pos[202000];
char s[202000];

void add(int &x,int l,int r,int p){
  if (!x) x=++cntr;
  ++tr[x].sz;
  if (l==r) return;
  int mid=l+r>>1;
  if (p<=mid) add(tr[x].lc,l,mid,p);
  else add(tr[x].rc,mid+1,r,p);
}
void mg(int &x,int y,int l,int r){
  if (!y) return;
  if (!x){
    x=y; return;
  }
  tr[x].sz+=tr[y].sz;
  if (l==r) return;
  int mid=l+r>>1;
  mg(tr[x].lc,tr[y].lc,l,mid);
  mg(tr[x].rc,tr[y].rc,mid+1,r);
}
int que(int x,int l,int r,int st,int en){
  st=max(st,l); en=min(en,r);
  if (st>en||!x) return 0;
  if (st==l&&en==r) return tr[x].sz;
  int mid=l+r>>1;
  return que(tr[x].lc,l,mid,st,en)
        +que(tr[x].rc,mid+1,r,st,en);
}

struct OPT{
  int l, r, id;
}; vector<OPT>opt[202000];

int ans[505000];

namespace ac{
  int ch[202000][26], fai[202000], cnt;
  int qu[202000], tot;
  void init(){
    memset(ch,0,sizeof ch);
    cnt=1; for (int i=0;i<26;++i) ch[0][i]=1;
    memset(fai,0,sizeof fai);
  }
  int adds(char *s,int id){
    int l=strlen(s),p=1,c;
    for (int i=0;i<l;++i){
      c=s[i]-'a';
      if (!ch[p][c]) ch[p][c]=++cnt;
      p=ch[p][c]; add(rt[p],1,n,id);
    }
    return p;
  }
  void build(){
    queue<int>q;
    for (;!q.empty();) q.pop();
    q.push(1); tot=0;
    int x,y;
    for (;!q.empty();){
      x=q.front(); q.pop(); qu[++tot]=x;
      for (int i=0;i<26;++i)
        if (y=ch[x][i]){
          fai[y]=ch[fai[x]][i];
          q.push(y);
        }else{
          ch[x][i]=ch[fai[x]][i];
        }
    }
  }
  vector<int>G[202000];
  void dfs(int x){
    for (auto y:G[x]){
      dfs(y);
      mg(rt[x],rt[y],1,n);
    }
    for (auto o:opt[x]){
      ans[o.id]=que(rt[x],1,n,o.l,o.r);
    }
  }
  void fuck(){
    for (int i=2;i<=cnt;++i)
      G[fai[i]].push_back(i);
    dfs(1);
  }
}

int main(){
  cin>>n>>q;
  ac::init();
  for (int i=1;i<=n;++i){
    scanf("%s",s);
    pos[i]=ac::adds(s,i);
  }
  for (int i=1;i<=q;++i){
    int l, r, k;
    scanf("%d%d%d",&l,&r,&k);
    opt[pos[k]].push_back({l,r,i});
  }
  ac::build();
  ac::fuck();
  for (int i=1;i<=q;++i) printf("%d\n",ans[i]);
}