#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
int a[200001];
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin>>t;
  while(t--){
    long long k;
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    int mi=0;
    int mx=0;
    while(k>0){
      mi=*min_element(a+1, a+n+1);
      mx=*max_element(a+1, a+n+1);
      if(mi==0) break;
      for(int i=1; i<=n; i++) a[i]=mx-a[i];
      k--;
    }
    if(mi==0){
      k%=2;
      if(k) for(int i=1; i<=n; i++) a[i]=mx-a[i];
    }
    for(int i=1; i<=n; i++) cout<<a[i]<<" \n"[i==n];
  }
}