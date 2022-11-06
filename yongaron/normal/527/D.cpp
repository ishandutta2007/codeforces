#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

const int N = 200005;

int n;

pair<int, int> points[N];

map<int, int> mp;

int ans;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>points[i].first>>points[i].second;
  sort(points, points+n, [](pair<int, int> a, pair<int, int> b){return a.first+a.second < b.first+b.second;});
  mp[1e9] = 0;
  for(int i = 0; i < n; i++)
  {
    int x = points[i].first;
    int w = points[i].second;
    int dp = mp.lower_bound(-x+w)->second+1;
    if(dp > ans)
      mp[-x-w] = dp;
    ans = max(ans, dp);
  }
  cout<<ans<<endl;
  return 0;
}