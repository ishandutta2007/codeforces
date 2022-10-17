#include<bits/stdc++.h>
using namespace std;
const int N=105;
int t,n,x,a[N];
int main(){
  for(scanf("%d",&t);t;--t){
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int s=0;bool qwq=0; 
    for(int i=1;i<=n;++i){
      s+=a[i];
      if(s==x){qwq=1;
        bool ok=0;
        for(int j=i+1;j<=n;++j){
          if(a[j]!=a[i]){
            puts("YES");ok=1;
            swap(a[i],a[j]);
            for(int k=1;k<=n;++k)printf("%d%c",a[k]," \n"[k==n]);
            break;
          }
        }
        if(!ok)puts("NO");
        break;
      }
    }
    if(!qwq){
      puts("YES");
      for(int k=1;k<=n;++k)printf("%d%c",a[k]," \n"[k==n]);
    }
  }
  return 0;
}