#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a[n], b[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    cin >> b[i];
  }
  int lo = 0, hi = 2000, mid, ans=0;
  while(lo <= hi){
    mid = (lo + hi)/2;
    int cur = 0;
    for(int i = 0; i < n; i++){
      cur += max(0, a[i]*mid - b[i]);
    }
    if(cur > k){
      hi=mid-1;
    }
    else{
      ans=mid;
      lo=mid+1;
    }
  }
  cout << ans;
}