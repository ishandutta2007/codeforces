#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
  int n, m;
  cin>>n>>m;
  if((n==1)&&(m==1)){
    cout<<0<<'\n';
    return 0;
  }
  if(n==1||m==1){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=m; j++){
        cout<<i*j+1<<" \n"[j==m];
      }
    }
    return 0;
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      cout<<i*(j+n)<<" \n"[j==m];
    }
  }
}