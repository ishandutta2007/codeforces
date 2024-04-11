#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,f[5050],b[5050],ans;
ll a[5050];

bool ok(int dis,int x,int y){
  if (!y) return 1;
  if (x+dis==y) return 1;
  if (dis>y) return 1;
  return 0;
}

int main(){
  cin>>n;
  for (int i=1;i<=n;++i){
    cin>>a[i];
    for (;a[i]%2==0;) a[i]/=2, ++b[i];
  }
  for (int i=1;i<=n;++i){
    for (int j=0;j<i;++j)
      if (j==0||ok(i-j,b[j],b[i])&&a[j]%a[i]==0)
        f[i]=max(f[i],f[j]+1);
    ans=max(ans,f[i]); //printf("%d %d\n",i,f[i]);
  }
  cout<<n-ans;
}