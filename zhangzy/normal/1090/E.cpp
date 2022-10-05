#include<bits/stdc++.h>
using namespace std;

int n;
#define pii pair<int,int>
#define fi first
#define se second
map<pii,pii>to; pii nil;
char str[233];

vector<pii>U, V, l;

bool ok(pii x){
  return x.fi>='a'&&x.fi<='h' && x.se>=1&&x.se<=8;
}
void bfs(pii s,pii t){
  set<pii>vis;
  map<pii,pii>pre;
  queue<pii>q;
  vis.insert(s); q.push(s);
  for (;!q.empty();){
    pii x=q.front(); q.pop();
    for (int i=-2;i<=2;++i)
      for (int j=-2;j<=2;++j)
        if (abs(i)+abs(j)==3){
          pii y=(pii){x.fi+i,x.se+j};
          if (!ok(y)||vis.count(y)) continue;
          vis.insert(y); pre[y]=x; q.push(y);
        }
  }
  l.clear();
  for (pii p=t;p!=nil;p=pre[p]){
    l.push_back(p);
  }
}

void fuck(pii t){
  pii s;
  for (auto o:to) if (o.se==t) s=o.fi;
  if (to[t]!=nil){
    swap(to[s],to[t]); return;
  }
  bfs(s,t); int sz=l.size()-1;
  for (int i=0,j;i<sz;i=j){
    for (j=i+1;to[l[j]]==nil;++j);
    for (int k=j-1;k>=i;--k){
      U.push_back(l[k+1]);
      V.push_back(l[k]);
    }
  }
  to[s]=nil; to[t]=t;
}

int main(){
  cin>>n;
  for (int i=0;i<n;++i){
    cin>>str;
    pii x=(pii){str[0],str[1]-'0'};
    pii y=(pii){i%8+'a',i/8+1};
    to[x]=y;
  }
  for (int i=0;i<n;++i){
    pii p=(pii){i%8+'a',i/8+1};
    if (to[p]!=p) fuck(p);
  }
  cout<<U.size()<<endl;
  for (int i=0;i<U.size();++i)
    printf("%c%d-%c%d\n",(char)U[i].fi,U[i].se,(char)V[i].fi,V[i].se);
}