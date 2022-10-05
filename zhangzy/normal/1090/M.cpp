#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;

int n, k, a[101000], ans=1;

int main(){
  cin>>n>>k;
  int p=1;
  for (int i=1;i<=n;++i){
    scanf("%d",&a[i]);
    if (i!=1&&a[i]==a[i-1]) p=i;
    ans=max(ans,i-p+1);
  }
  cout<<ans<<endl;
}