#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    if(*max_element(a+1, a+n+1)==*min_element(a+1, a+n+1)) cout<<n<<'\n';
    else cout<<1<<'\n';
  }
}