#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

pii p[101000];
int n,a[101000],b[101000],sp;

int main(){
  cin.tie(0); cin>>n;
  for (int i=1;i<=n;++i) cin>>p[i].fi, p[i].se=i;
  sort(p+1,p+n+1); sp=(n+2)/3;
  for (int i=1;i<=n;++i){
    if (i<=sp){
      a[p[i].se]=i-1;
      b[p[i].se]=p[i].fi-a[p[i].se];
    }else if (i<=sp*2){
      a[p[i].se]=0;
      b[p[i].se]=p[i].fi;
    }else{
      b[p[i].se]=n-i;
      a[p[i].se]=p[i].fi-b[p[i].se];
    }
  }
  puts("YES");
  for (int i=1;i<=n;++i) printf("%d ",a[i]); puts("");
  for (int i=1;i<=n;++i) printf("%d ",b[i]); puts("");
}