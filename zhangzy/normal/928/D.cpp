#include<bits/stdc++.h>
using namespace std;

int n, ans, ch[303000][26], sz[303000], fa[303000], cnt=1, p=1;
int dep[303000], fl[303000];

void add(int x){
  if (!ch[p][x]){
    ch[p][x]=++cnt; fa[cnt]=p; dep[cnt]=dep[p]+1;
  }
  p=ch[p][x];
}

int cal(int x){
  int l=dep[x];
  if (!fl[x]) return l;
  for (;fa[x]&&sz[x]==1;) x=fa[x];
  return min(l,dep[x]+2);
}

void doit(){
  if (p==1) return;
  int l=dep[p];
  if (fl[p]){
    ans+=cal(p);
  }else{
    int tp=p;
    for (;!sz[tp]&&fa[tp];) tp=fa[tp], ++ans;
    ans+=cal(tp);
    fl[p]=1; for (;p;p=fa[p]) ++sz[p];
  }
}

int main(){
  //freopen("1.txt","r",stdin);
  static char c; sz[1]=23333;
  for (;scanf("%c",&c)==1;){
    if (c>='a'&&c<='z'){
      add(c-'a');
    }else{
      doit(); ++ans; p=1;
    }
  }
  cout<<ans<<endl;
}