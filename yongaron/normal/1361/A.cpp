#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, m;

vector<int> graf[1234567];
pair<int, int> x[1234567];

bool was[1234567];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  int a, b;
  for(int i = 0; i < m; i++)
  {
    cin>>a>>b;
    graf[a].push_back(b);
    graf[b].push_back(a);
  }
  for(int i = 1; i <= n; i++)
  {
    cin>>x[i].first;
    x[i].second = i;
  }
  for(int i = 1; i <= n; i++)
  {
    if(x[i].first > graf[i].size()+1)
    {
      cout<<-1<<endl;
      return 0;
    }
    for(int j = 0; j <= x[i].first; j++)
      was[j] = false;
    for(int j = 0; j < graf[i].size(); j++)
      was[x[graf[i][j]].first] = true;
    for(int j = 1; j < x[i].first; j++)
    {
      if(!was[j])
      {
        cout<<-1<<endl;
        return 0;
      }
    }
    if(was[x[i].first])
    {
      cout<<-1<<endl;
      return 0;
    }
  }
  sort(x+1, x+n+1);
  for(int i = 1; i <= n; i++)
    cout<<x[i].second<<" ";
  cout<<endl;
  return 0;
}