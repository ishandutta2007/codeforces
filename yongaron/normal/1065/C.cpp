#include<iostream>
#include<algorithm>

using namespace std;

int n, k;
int h[234567];

int main(int argc, char const *argv[]) {
  cin>>n>>k;
  for(int i = 0; i < n; i++)
    cin>>h[i];
  sort(h, h+n);
  int curr = h[n-1], cursum = 0, ans = 0;
  while(curr > h[0])
  {
    int l = 0, r = n-1, m;
    while(l < r)
    {
      m = (l+r-1)/2;
      if(h[m] < curr)
        l = m+1;
      else
        r = m;
    }
    if(cursum+n-l > k)
    {
      ans++;
      cursum = n-l;
    }
    else
      cursum += n-l;
    // cout<<n-l<<endl;
    curr--;
  }
  if(cursum > 0)
    ans++;
  cout<<ans<<endl;
  return 0;
}