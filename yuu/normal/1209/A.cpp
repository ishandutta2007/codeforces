#include <bits/stdc++.h>
int n;
int a[100];
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin>>n;
  for(int i=0; i<n; i++) cin>>a[i];
  sort(a, a+n);
  int ans=0;
  for(int i=0; i<n; i++) if(a[i]){
    ans++;
    for(int j=i+1; j<n; j++) if(a[j]%a[i]==0) a[j]=0;
  }
  cout<<ans<<'\n';
}