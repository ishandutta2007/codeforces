#include<bits/stdc++.h>
using namespace std;

int n, c1, c2, cnt, rt, g[110];
struct TR{
  int lc, rc, val, mx[110], mn[110], fa, sz;
}tr[20200];

#define LC tr[x].lc
#define RC tr[x].rc
void sfd(int &x,int fff){
  if (!x) x=++cnt; 
  tr[x].fa=fff;
  
  char c=getchar();
  if (c=='(') {
    sfd(LC,x);
  } else {
    tr[x].val=c-'0';
    return;
  }
  if (getchar()!='?') cerr<<"fuck\n";
  sfd(RC,x);
  if (getchar()!=')') cerr<<"fuck\n";
}

void U(int &x,int y){
  x=max(x,y);
}
void V(int &x,int y){
  x=min(x,y);
}

namespace f__k{
  
  void dfs(int x){
    if (LC){
      dfs(LC); dfs(RC);
      tr[x].sz=min(c1,tr[LC].sz+tr[RC].sz+1);
      
      memset(g,-33,sizeof g);
      for (int i=0;i<=tr[LC].sz;++i)
        for (int j=0;j<=tr[RC].sz&&i+j<=c1;++j){
          U(g[i+j+1] ,tr[LC].mx[i]+tr[RC].mx[j]);
          U(g[i+j]   ,tr[LC].mx[i]-tr[RC].mn[j]);
        }
      memcpy(tr[x].mx,g,sizeof g);
      
      memset(g,33,sizeof g);
      for (int i=0;i<=tr[LC].sz;++i)
        for (int j=0;j<=tr[RC].sz&&i+j<=c1;++j){
          V(g[i+j+1] ,tr[LC].mn[i]+tr[RC].mn[j]);
          V(g[i+j]   ,tr[LC].mn[i]-tr[RC].mx[j]);
        }
      memcpy(tr[x].mn,g,sizeof g);
      
    }else{
      tr[x].mx[0]=tr[x].mn[0]=tr[x].val;
    }
  }
  
  void realmain(){
    dfs(rt); cout<<tr[rt].mx[c1];
  }
}

namespace s__t{
  
  void dfs(int x){
    if (LC){
      dfs(LC); dfs(RC);
      tr[x].sz=min(c2,tr[LC].sz+tr[RC].sz+1);
      
      memset(g,-33,sizeof g);
      for (int i=0;i<=tr[LC].sz;++i)
        for (int j=0;j<=tr[RC].sz&&i+j<=c2;++j){
          U(g[i+j]   ,tr[LC].mx[i]+tr[RC].mx[j]);
          U(g[i+j+1] ,tr[LC].mx[i]-tr[RC].mn[j]);
        }
      memcpy(tr[x].mx,g,sizeof g);
      
      memset(g,33,sizeof g);
      for (int i=0;i<=tr[LC].sz;++i)
        for (int j=0;j<=tr[RC].sz&&i+j<=c2;++j){
          V(g[i+j]   ,tr[LC].mn[i]+tr[RC].mn[j]);
          V(g[i+j+1] ,tr[LC].mn[i]-tr[RC].mx[j]);
        }
      memcpy(tr[x].mn,g,sizeof g);
      
    }else{
      tr[x].mx[0]=tr[x].mn[0]=tr[x].val;
    }
  }
  
  void realmain(){
    dfs(rt); cout<<tr[rt].mx[c2];
  }
}

int main(){
  sfd(rt,0);
  cin>>c1>>c2;
  if (c1<c2) f__k::realmain();
  else s__t::realmain();
}