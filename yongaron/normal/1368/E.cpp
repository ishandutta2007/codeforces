#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, m, t;

vector<int> graf[223456];

int d[223456];

vector<int> ans;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    ans.clear();
    cin>>n>>m;
    for(int i = 0; i <= n; i++)
    {
      graf[i].clear();
      d[i] = 0;
    }
    int a, b;
    for(int i = 0; i < m; i++)
    {
      cin>>a>>b;
      graf[a].push_back(b);
    }
    for(int i = 1; i <= n; i++)
    {
      if(d[i] < 2)
        for(int j = 0; j < graf[i].size(); j++)
          d[graf[i][j]] = max(d[graf[i][j]], d[i]+1);
      else
        ans.push_back(i);
    }
    cout<<ans.size()<<endl;;
    for(int i = 0; i < ans.size(); i++)
      cout<<ans[i]<<" ";
    cout<<endl;
  }
  return 0;
}