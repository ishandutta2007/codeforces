#include<bits/stdc++.h>
using namespace std;

char s[23333];
int f[23333],n;
short d[8010][8010];
bitset<8888>b;
int C(int x){
  int t=1; for (;x>9;x/=10) t++; return t;
}
int main(){
  scanf("%s",s+1);
  n=strlen(s+1);
  memset(d,0,sizeof d);
  for (int i=n;i;i--){
    for (int j=n;j;j--){
      d[i][j]= s[i]==s[j]? d[i+1][j+1]+1: 0;
    }
  }
  memset(f,38,sizeof f);f[0]=0;
  int ti,now,l,p;
  for (int i=1;i<=n;i++){
    now=f[i-1];
    b.reset();
    for (int j=i;j<=n;j++){
      if (b[j]) continue;
      l=j-i+1;
      ti=0;
      p=i;
      while (d[i][p]>=l) {
        p+=l;ti++;
        b[p-1]=1;
        f[p-1]=min(f[p-1],now+C(ti)+l);
      }
    }
  }
  cout<<f[n];
}