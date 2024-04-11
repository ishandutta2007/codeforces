#include<bits/stdc++.h>
using namespace std;

#define ll long long
int n, fl[202020], die[202020];
ll a[202020], b[202020], t;

int main(){
  cin>>n>>t;
  for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
  for (int i=1,p;i<=n;++i){
    fl[i]+=fl[i-1];
    scanf("%d",&p); if (p<i) return puts("No"), 0;
    fl[i+1]++; fl[p+1]--;
    die[p+1]=1;
  }
  memset(b,40,sizeof b);
  for (int i=2;i<=n;++i)
    if (die[i]) b[i-1]=a[i]+t-1;
  for (int i=n-1;i>=1;--i){
    b[i]=min(b[i],b[i+1]-1);
    if (a[i]+t>b[i]) return puts("No"), 0;
  }
  for (int i=2;i<=n;++i)
    if (fl[i]&&a[i]+t>b[i-1])
      return puts("No"), 0;
  puts("Yes");
  for (int i=1;i<=n;++i)
    printf("%lld ",b[i]);
  puts("");
}