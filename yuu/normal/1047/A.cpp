#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
  cin>>n;
  for(int i=1; i<n; i++) if(i%3){
    for(int j=i; i+j<n; j++) if(j%3){
      int k=n-i-j;
      if(k%3){
        cout<<i<<' '<<j<<' '<<k;
        return 0;
      }
    }
  }
}