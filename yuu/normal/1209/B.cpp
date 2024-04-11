#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int a[100];
int b[100];
int main(){
  ios_base::sync_with_stdio(false);
  cin>>n>>s;
  for(int i=0; i<n; i++) cin>>a[i]>>b[i];
  int ans=0;
  for(int time=0; time<100000; time++){
    int now=0;
    for(int i=0; i<n; i++){
      if((time>=b[i])&&((time-b[i])%a[i]==0)) s[i]^='0'^'1';
      now+=(s[i]=='1');
    }
    ans=max(ans, now);
  }
  cout<<ans<<'\n';
  
}