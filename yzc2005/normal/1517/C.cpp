#include <bits/stdc++.h>
using namespace std;
const int N=505;
int n,p[N],a[N][N];
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;++i){
    scanf("%d",&p[i]);
    int x=i,y=i,c=p[i];
    while(c--){
      a[x][y]=i;
      if(y>1&&!a[x][y-1])--y;
      else ++x;
    }
  }
  for(int i=1;i<=n;++i)
    for(int j=1;j<=i;++j)
      printf("%d%c",p[a[i][j]]," \n"[j==i]);
  return 0;
}