#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

int c[123];
int nc[123];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>c[i];
  vector<vector<int>> ans;
  for(int i = 0; i < n; i++)
  {
    vector<int> v;
    if((n-i)%2) // 1 je napravo
    {
      for(int j = 0; j < n; j++)
      {
        if(c[j] == i+1)
        {
          if(j)
            v.push_back(j);
          v.push_back(n-i-j);
          break;
        }
      }
      for(int j = 0; j < i; j++)
      {
        v.push_back(1);
      }
      if(v.size() > 1)
        ans.push_back(v);
    }
    else  // 1 je nalevo
    {
      for(int j = 0; j < i; j++)
      {
        v.push_back(1);
      }
      for(int j = 0; j < n; j++)
      {
        if(c[j] == i+1)
        {
          v.push_back(j-i+1);
            if(n-j-1)
          v.push_back(n-j-1);
          break;
        }
      }
      if(v.size() > 1)
        ans.push_back(v);
    }
    int s = 0;
    for(int j = 0; j < v.size(); j++)
    {
      for(int l = 0; l < v[j]; l++)
      {
        nc[n-s-v[j]+l] = c[s+l];
      }
      s += v[j];
    }
    // cout<<"v: ";
    // for(int j = 0; j < v.size(); j++)
    //   cout<<v[j]<<" ";
    // cout<<endl;
    v.clear();
    for(int j = 0; j < n; j++)
      c[j] = nc[j];
    // cout<<"c: ";
    // for(int j = 0; j < n; j++)
    //   cout<<c[j]<<" ";
    // cout<<endl;
  }
  cout<<ans.size()<<endl;
  for(int i = 0; i < ans.size(); i++)
  {
    cout<<ans[i].size()<<" ";
    for(int j = 0; j < ans[i].size(); j++)
      cout<<ans[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}