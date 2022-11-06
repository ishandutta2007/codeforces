#include<iostream>
#include<map>
#include<vector>

#define ull unsigned long long

using namespace std;

map<pair<int, int>, ull> mp;

ull dp(int n, int h)
{
  if(h > n)
    return 0;
  if(mp.count({n, h}))
    return mp[{n, h}];
  ull ans = 0;
  for(int i = 0; i < n; i++)
    ans += dp(i, max(h-1, 0))*dp(n-i-1, 0) + dp(i, 0)*dp(n-i-1, max(h-1, 0)) - dp(i, max(h-1, 0))*dp(n-i-1, max(h-1, 0));
  mp[{n, h}] = ans;
  return ans;
}

int main(int argc, char const *argv[]) {
  int n, h;
  mp[{0, 0}] = 1;
  cin>>n>>h;
  cout<<dp(n, h)<<endl;
  return 0;
}