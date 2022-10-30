#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vi pm;
vector<vector<int> > w;
vector<int> costs;
int n;

int dp[4009][4009];

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  
  int test;
  cin>>test;
  while(test--)
  {
    cin>>n;
    pm.resize(2*n);
    w.clear();
    costs.clear();
    for(int i=0; i<2*n; i++)
    {
      cin>>pm[i];
    }
    vi cur;
    vector<bool> was(2*n+1, false);
    int cnt=2*n-1;
    for(int i=2*n; i>=1; i--)
    {
      if(was[i]) continue;
      cur.clear();
      while(cnt>=0 && !was[i])
      {
        was[pm[cnt]]=true;
        cur.push_back(pm[cnt]);
        cnt--;
      }
      reverse(cur.begin(), cur.end());
      w.push_back(cur);
      costs.push_back(cur.size());
    }
    int m=w.size();
    dp[0][0]=1;
    for(int z=1; z<=n; z++)
    {
      dp[0][z]=0;
    }
    dp[0][costs[0]]=1;
    for(int i=1; i<m; i++)
    {
      dp[i][0]=1;
      for(int z=1; z<=n; z++)
      {
        dp[i][z]=dp[i-1][z];
        if(z-costs[i]>=0 && dp[i-1][z-costs[i]]>0)
        {
          dp[i][z]=1;
        }
      }
    }
    if(dp[m-1][n]>0) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
  }
	return 0;
}