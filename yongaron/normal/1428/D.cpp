#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n;
int a[123456];

vector<pair<int, int>> ans;
vector<int> ones;
vector<int> twos;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    cin>>a[i];
  }
  for(int i = n-1; i >= 0; i--)
  {
    if(a[i] == 0)
      continue;
    else if(a[i] == 1)
    {
      ans.push_back({i, i});
      ones.push_back(i);
    }
    else if(a[i] == 2)
    {
      if(ones.size() == 0)
      {
        cout<<-1<<endl;
        return 0;
      }
      else
      {
        ans.push_back({ones.back(), i});
        ones.pop_back();
        twos.push_back(i);
      }
    }
    else
    {
      if(twos.size() == 0)
      {
        if(ones.size() == 0)
        {
          cout<<-1<<endl;
          return 0;
        }
        else
        {
          ans.push_back({i, i});
          ans.push_back({i, ones.back()});
          ones.pop_back();
          twos.push_back(i);
        }
      }
      else
      {
          ans.push_back({i, i});
          ans.push_back({i, twos.back()});
          twos.pop_back();
          twos.push_back(i);
      }
    }
  }
  cout<<ans.size()<<endl;
  for(int i = 0; i < ans.size(); i++)
  {
    cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
  }
  return 0;
}