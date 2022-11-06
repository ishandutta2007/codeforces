#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int n;
long long a[223456];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin>>n;
  for(int i = 0; i < 2*n; i++)
    cin>>a[i];
  sort(a, &a[2*n]);
  long long f = 0, s = 0;
  long long ans;
  f = a[n-1]-a[0];
  s = a[2*n-1]-a[n];
  ans = f*s;
  for(int i = 1; i < n; i++)
  {
    f = a[n-1+i]-a[i];
    s = a[2*n-1]-a[0];
    ans = min(ans, s*f);
  }
  cout<<ans<<endl;
  return 0;
}