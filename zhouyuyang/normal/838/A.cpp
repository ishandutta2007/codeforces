#include<bits/stdc++.h>
#define N 2505
using namespace std;

int n,m,ans=N*N*50,tut[N+N][N+N];
char a[N][N];

int main() {

  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++) {
    scanf("%s",a[i]+1);
  }
  for(int i=1;i<=n+max(n,m);i++) {
    for(int j=1;j<=m+max(n,m);j++) {
      tut[i][j]=tut[i-1][j]+tut[i][j-1]-tut[i-1][j-1]+(a[i][j]=='1');
    }
  }
  for(int k=2;k<=max(n,m);k++) {
    int ansk=0;
    for(int i=k;i<=n+k-1;i+=k) {
      for(int j=k;j<=m+k-1;j+=k) {
        int no1=tut[i][j]-tut[i-k][j]-tut[i][j-k]+tut[i-k][j-k];
        ansk+=min(no1,k*k-no1);
      }
    }
    ans=min(ans,ansk);
  }
  printf("%d",ans);

}