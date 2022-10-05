#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

int n, p[1010], fl, s[1010][1010];
char S[]="./\\";

void out(int x){
  cout<<x<<endl;
  for (int i=1;i<=n;++i,puts(""))
    for (int j=1;j<=n;++j)
      putchar(S[s[i][j]]);
  exit(0);
}

int main(){
  cin>>n;
  for (int i=1;i<=n;++i){
    cin>>p[i];
    if (p[i]!=i) fl=i;
  }
  if (!fl) out(n);
  for (int c=n,ty=1; c>=1; --c,ty^=3){
    int ti=0;
    if (ty==1){
      for (int i=1;i<fl&&!ti;++i)
        if (p[i]>i) ti=i;
    }
    else{
      for (int i=n;i>fl&&!ti;--i)
        if (p[i]<i) ti=i;
    }
    if (!ti) break;
    s[c][ti]=s[c][p[ti]]=s[c][fl]=ty;
    p[fl]=p[p[ti]]; p[p[ti]]=p[ti]; fl=ti;
  }
  out(n-1);
}