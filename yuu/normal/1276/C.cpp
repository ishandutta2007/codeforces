#include <bits/stdc++.h>
using namespace std;
int n;
int a[400001];
vector <int> f[400001];
deque <int> res[1000];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
  cin>>n;
  for(int i=1; i<=n; i++) cin>>a[i];
  sort(a+1, a+n+1);
  int cnt=0;
  for(int i=1; i<=n; i++){
    int j=i;
    while((j<n)&&(a[j+1]==a[j])) j++;
    f[j-i+1].push_back(a[i]);
    i=j;
    cnt++;
  }
  int low=1, high=1;;
  int sum=0;
  int ans=0;
  for(int len=1; len*len<=n; len++){
    sum+=f[len].size()*len;
    cnt-=f[len].size();
    int total=sum+cnt*len;
    // cerr<<len<<' '<<total<<'\n';
    total/=len;
    // cerr<<len<<' '<<total<<'\n';
    if(total<len) continue;
    if(len*total>ans){
      ans=len*total;
      low=len;
      high=total;
    }
  }
  cout<<ans<<'\n';
  cout<<low<<' '<<high<<'\n';
  for(int i=low+1; i<=n; i++){
    for(auto &x: f[i]) f[low].push_back(x);
  }
  
  for(int i=low; i>=1; i--){
    for(auto &x: f[i]){
      for(int j=0; j<i; j++){
        res[ans%low].push_back(x);
        ans--;
        if(ans==0) break;
      }
      if(ans==0) break;
    }
    if(ans==0) break;
  }
  for(int i=0; i<low; i++){
    for(int j=0; j<high; j++) cout<<res[i][(i+j)%high]<<" \n"[j+1==high];
  }
}