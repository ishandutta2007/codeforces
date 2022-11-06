#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int n, k;
int d[333333];
int sd[333333];
map<pair<int, int>, int> mp;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>k;
  int a, b;
  for(int i = 0; i < n; i++)
  {
    cin>>a>>b;
    a--; b--;
    d[a]++;
    d[b]++;
    sd[a] = d[a];
    sd[b] = d[b];
    if(a > b)
      swap(a, b);
    if(mp.count({a, b}))
      mp[{a, b}]++;
    else
      mp[{a, b}] = 1;
  }
  sort(sd, sd+n);
  long long ans = 0;
  for(int l = 0, r = n; l < n; l++)
  {
    while(r > l && sd[l]+sd[r-1] >= k)
      r--;
    r = max(r, l+1);
    ans += (n-r);
  }
  for(pair<pair<int, int>, int> p : mp)
    if(d[p.first.first]+d[p.first.second] >= k
       && d[p.first.first]+d[p.first.second]-p.second < k)
      ans--;
  cout<<ans<<endl;
  return 0;
}