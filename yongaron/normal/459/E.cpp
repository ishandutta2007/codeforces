#include<iostream>
#include<algorithm>

using namespace std;

const int N = 300005;
const int M = 300005;

int dp[N];
int pre[N];
int last[N];

pair<int, pair<int, int>> edges[M];

int n, m;
int ans = 0;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>n>>m;
  for(int i = 0; i < m; i++)
    cin>>edges[i].second.first>>edges[i].second.second>>edges[i].first;
  sort(edges, edges+m);
  for(int i = 0; i < m; i++)
  {
    int a = edges[i].second.first;
    int b = edges[i].second.second;
    int w = edges[i].first;
    int val = dp[a]+1;
    if(w == last[a])
      val = pre[a]+1;
    if(val > dp[b])
    {
      if(last[b] == w)
        dp[b] = val;
      else
      {
        pre[b] = dp[b];
        dp[b] = val;
        last[b] = w;
      }
    }
    ans = max(ans, val);
  }
  cout<<ans<<endl;
  return 0;
}