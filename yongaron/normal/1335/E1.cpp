#include<iostream>
#include<vector>

using namespace std;

int t, n;

int pre[123456][202];

vector<int> v[202];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>t;
  while(t--)
  {
    cin>>n;
    int a;
    for(int i = 1; i <= n; i++)
    {
      cin>>a;
      for(int j = 0; j < 201; j++)
        pre[i][j] = pre[i-1][j];
      pre[i][a]++;
      v[a].push_back(i);
    }
    int ma = 0;
    for(int i = 0; i < 201; i++)
    {
      ma = max(ma, (int)v[i].size());
      for(int j = 0; j < v[i].size(); j++)
      {
        if(v[i][j] >= v[i][v[i].size()-j-1])
          break;
        for(int k = 0; k < 201; k++)
        {
          if(k == i)
            continue;
          ma = max(ma, 2*j+2+pre[v[i][v[i].size()-j-1]][k]-pre[v[i][j]][k]);
        }
      }
      v[i].clear();
    }
    for(int i = 0; i <= n; i++)
      for(int j = 0; j < 201; j++)
        pre[i][j] = 0;
    cout<<ma<<endl;
  }
  return 0;
}