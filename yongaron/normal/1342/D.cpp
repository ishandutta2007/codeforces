#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int m[223456], c[223456];

int n, k;

vector<vector<int>> cases;

int main(int argc, char const *argv[]) {
  cin>>n>>k;
  for(int i = 0; i < n; i++)
    cin>>m[i];
  for(int i = 0; i < k; i++)
    cin>>c[i+1];
  sort(m ,m+n, [](int a, int b){return a > b;});
  vector<int> v;
  int cur = 0, tolast = 0;
  cases.push_back(v);
  for(int i = 0; i < n; i++)
  {
    if(tolast)
    {
      cases.back().push_back(m[i]);
      tolast--;
    }
    else if(cases[cur].size() >= c[m[i]])
    {
      cases.push_back(v);
      cases.back().push_back(m[i]);
      tolast = cases[cur].size()-1;
    }
    else
    {
      cases[cur].push_back(m[i]);
      cur = (cur+1)%cases.size();
    }
  }
  cout<<cases.size()<<endl;
  for(int i = 0; i < cases.size(); i++)
  {
    cout<<cases[i].size()<<" ";
    for(int j = 0; j < cases[i].size(); j++)
      cout<<cases[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}