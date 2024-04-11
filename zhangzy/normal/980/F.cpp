#include<bits/stdc++.h>
using namespace std;

vector<int>G[505000], S[505000];
unordered_map<int,int>f[505000];

int n, m, dep[505000], fa[505000], bel[505000], used[505000];
void dfs(int x,int fff){
  fa[x]=fff; dep[x]=dep[fff]+1;
  for (auto y:G[x])
    if (y!=fff){
      if (!dep[y]) dfs(y,x);
      else if (dep[y]>dep[x]){
	for (;;y=fa[y]){
	  bel[y]=x; S[x].push_back(y);
	  if (y==x) break;
	}
      }
    }
}

deque<int>q;
void add(int x){
  for (;!q.empty()&&q.back()<x;) q.pop_back();
  q.push_back(x);
}
void del(int x){
  if (q.front()==x) q.pop_front();
}

int gaof(int fff,int x){
  //printf(" %d %d\n",x,fff);
  if (f[x].count(fff)) return f[x][fff];
  if (!bel[x]){
    if (!used[x]){
      used[x]=1;
      int res=0;
      for (auto y:G[x])
	if (y!=fff)
	  res=max(res,gaof(x,y)+1);
      return f[x][fff]=res;
    }
    int now=0;
    for (auto y:G[x]) now=max(now,gaof(x,y)+1);
    f[x][0]=now; now=0;
    for (auto y:G[x]){
      f[x][y]=max(f[x][y],now);
      now=max(now,gaof(x,y)+1);
    }
    now=0;
    for (auto it=G[x].rbegin();it!=G[x].rend();++it){
      int y=*it;
      f[x][y]=max(f[x][y],now);
      now=max(now,gaof(x,y)+1);
    }
    return f[x][fff];
  }
  int b=bel[x];
  vector<int>&T=S[b]; int sz=T.size();
  if (!used[b]){
    used[b]=1;
    int id=find(T.begin(),T.end(),x)-T.begin();
    int res=0;
    for (int i=0;i<sz;++i){
      int d=abs(i-id); d=min(d,sz-d);
      int u=T[i]; res=max(res,d);
      for (auto v:G[u])
	if (!(u==x&&v==fff)&&bel[v]!=b)
	  res=max(res,gaof(u,v)+d+1);
    }
    return f[x][fff]=res;
  }
  
  vector<int>mx, nex, pre;
  mx.resize(sz); nex.resize(sz); pre.resize(sz);
  for (int i=0;i<sz;++i){
    int u=T[i];
    for (auto v:G[u])
      if (bel[v]!=b)
	mx[i]=max(mx[i],gaof(u,v)+1);
  }

  q.clear(); int l=sz/2;
  for (int i=0;i<sz*2;++i){
    add(mx[i%sz]+i);
    if (i>=l){
      del(mx[(i-l)%sz]+(i-l));
      nex[(i-l)%sz]=q.front()-(i-l);
    }
  }
  q.clear();
  for (int i=sz*2;i>0;--i){
    add(mx[i%sz]-i);
    if (i+l<=sz*2){
      del(mx[(i+l)%sz]-(i+l));
      pre[(i+l)%sz]=q.front()+(i+l);
    }
  }

  for (int i=0;i<sz;++i){
    int u=T[i];
    for (auto v:G[u])
      if (bel[v]!=b)
	f[u][v]=max(pre[i],nex[i]);
    f[u][0]=max(max(pre[i],nex[i]),mx[i]);
    int now=0;
    for (auto v:G[u]){
      if (bel[v]==b) continue;
      f[u][v]=max(f[u][v],now);
      now=max(now,gaof(u,v)+1);
    }
    now=0;
    for (auto it=G[u].rbegin();it!=G[u].rend();++it){
      int v=*it;
      if (bel[v]==b) continue;
      f[u][v]=max(f[u][v],now);
      now=max(now,gaof(u,v)+1);
    }
  }
  
  return f[x][fff];
}

int main(){
  cin>>n>>m;
  int u, v;
  for (int i=1;i<=m;++i){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1,0);
  for (int i=1;i<=n;++i){
    printf("%d ",gaof(0,i));
  }
  puts("");
}