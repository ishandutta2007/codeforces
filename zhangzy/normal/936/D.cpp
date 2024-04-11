#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int n, m0, m1, t, f[4004000][2], tot, st[4004000];
bool fl[4004000][2], swp[4004000][2];
int ban0[1001000], ban1[1001000];
vector<int>sft;
vector<pii>fire;

int has(int x){
  return lower_bound(st+1,st+tot+1,x)-st;
}

void prt(int b){
  puts("Yes"); int las=2e9, d, w;
  for (int i=tot;i;--i){
    if (swp[i][b]){
      b^=1;
      sft.push_back(st[i]);
    }
    d=st[i]-st[i-1];
    if (f[i-1][b]+d>f[i][b]){
      w=min(las-t,st[i]-1); las=w;
      fire.push_back((pii){w,b+1});
    }
  }
  if (b) sft.push_back(0);
  sort(sft.begin(),sft.end());
  printf("%u\n",sft.size());
  for (auto o:sft) printf("%d ",o); puts("");
  sort(fire.begin(),fire.end());
  printf("%u\n",fire.size());
  for (auto o:fire) printf("%d %d\n",o.first,o.second);
}

int main(){
  cin>>n>>m0>>m1>>t; int x;
  for (int i=1;i<=m0;++i){
    scanf("%d",&ban0[i]);
    st[++tot]=ban0[i]; st[++tot]=ban0[i]+1;
  }
  for (int i=1;i<=m1;++i){
    scanf("%d",&ban1[i]);
    st[++tot]=ban1[i]; st[++tot]=ban1[i]+1;
  }
  sort(st+1,st+tot+1);
  tot=unique(st+1,st+tot+1)-st-1;
  
  for (int i=1;i<=m0;++i) fl[has(ban0[i])][0]=1;
  for (int i=1;i<=m1;++i) fl[has(ban1[i])][1]=1;
  
  memset(f,-1,sizeof f); f[0][0]=0; f[0][1]=0;
  
  for (int i=1;i<=tot;++i){
    int d=st[i]-st[i-1];
    for (int j=0;j<2;++j) if (~f[i-1][j]){
      if (fl[i][j]){
        if (f[i-1][j]+d-1>=t&&f[i-1][j]+d-t>f[i][j]){
          f[i][j]=f[i-1][j]+d-t;
          swp[i][j]=0;
        }
      }else{
        if (f[i-1][j]+d>f[i][j]){
          f[i][j]=f[i-1][j]+d;
          swp[i][j]=0;
        }
      }
    }
    //printf("%d:: %d %d  ",st[i],f[i][0],f[i][1]);
    if (!fl[i][1]&&~f[i][0]&&min(f[i][0],t)>f[i][1]){
      f[i][1]=min(f[i][0],t);
      swp[i][1]=1;
    }
    if (!fl[i][0]&&~f[i][1]&&min(f[i][1],t)>f[i][0]){
      f[i][0]=min(f[i][1],t);
      swp[i][0]=1;
    }
    //printf("%d %d\n",f[i][0],f[i][1]);
  }
  if (~f[tot][0]) return prt(0),0;
  if (~f[tot][1]) return prt(1),0;
  puts("No");
}