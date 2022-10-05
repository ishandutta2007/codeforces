#include<bits/stdc++.h>
using namespace std;

namespace fastIO{
  char ss[1<<20],*A=ss,*B=ss;
  inline char gc(){if(A==B){B=(A=ss)+fread(ss,1,1<<20,stdin);}return*A++;}
  inline void read(int &x){
    x=0; char c=gc();
    for (;!(c<='9'&&c>='0'); c=gc()) ;
    for (; (c<='9'&&c>='0'); c=gc()) x=(x<<3)+(x<<1)+c-'0';
  }
}using namespace fastIO;

int n, k, p, las;
int f[111][111][111];
vector<int>vec[111];

void U(int &x,int y){
  x=min(x,y);
}

int main(){
  read(n); read(k); read(p); int x;
  for (int i=1;i<=n;++i)
    read(x), vec[las=(las+x)%p].push_back(i);
  for (int i=0;i<p;++i) vec[i].push_back(1e8);
  memset(f,33,sizeof f);
  f[0][0][0]=0;
  for (int bas=0;;++bas){
    for (int i=0;i<=k;++i)
      for (int j=0;j<p;++j)
        if (f[bas][i][j]<=n){
          if (i==k&&j==las)
            return printf("%d",bas*p+las), 0;
          int fl=0, jj=j, pos;
          for (int tim=p;tim--;){
            pos=upper_bound(vec[jj].begin(),vec[jj].end(),f[bas][i][j])-vec[jj].begin();
            pos=vec[jj][pos];
            U(f[bas+fl][i+1][jj],pos);
            if (++jj==p) jj=0, fl=1;
          }
        } 
  }
}