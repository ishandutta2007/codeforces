#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(i > 0) a[i]+=a[i-1];
  }
  int m, x; cin >> m;
  for(int i = 0; i < m; i++){
    cin >> x;
    int lo = 0, hi = n-1, mid, ans;
    while(lo <= hi){
      mid = (lo+hi)/2;
      if(a[mid] >= x){
        ans=mid+1;
        hi=mid-1;
      }
      else{
        lo=mid+1;
      }
    }
    cout << ans << '\n';
  }
}