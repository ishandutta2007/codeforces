#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, m; cin >> n >> m;
  int a[n], b[m+1], last_pos[m+1];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= m; i++){
    cin >> b[i];
  }
  int lo = 0, hi = n-1, mid, ans=-1;
  while(lo <= hi){
    mid=(lo + hi)/2;
    for(int i = 0; i <= m; i++){
      last_pos[i] = -1;
    }
    for(int i = 0; i <= mid; i++){
      if(a[i]!=0) last_pos[a[i]]=i;
    }
    int passed=0, cnt=0;
    for(int i = 0; i <= mid; i++){
      if(last_pos[a[i]]!=i){
        cnt++;
      }
      else if(cnt>=b[a[i]]){
        cnt-=b[a[i]];
        passed++;
      }
      else{
        break;
      }
    }
    if(passed==m){
      ans=mid+1;
      hi=mid-1;
    }
    else{
      lo=mid+1;
    }
  }
  cout << ans;
}