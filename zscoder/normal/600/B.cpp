#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < m; i++){
    cin >> b[i];
  }
  sort(a, a+n);
  for(int i = 0; i < m; i++){
    int lo = 0, hi = n-1, mid, ans=0;
    while(lo <= hi){
      mid = (lo + hi)/2;
      if(a[mid] <= b[i]){
        ans = mid + 1;
        lo = mid + 1;
      }
      else{
        hi = mid - 1;
      }
    }
    cout << ans << " ";
  }

}