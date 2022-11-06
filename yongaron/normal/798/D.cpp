#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long

using namespace std;

const int N = 1e5+5;

int n;
pair<int, int> c[N];

int ma, mai;
int mab, mabi;

vector<pair<pair<int, int>, int>> v;
vector<int> ans;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>n;
  if(n == 1)
  {
    cout<<1<<endl<<1<<endl;
    return 0;
  }
  if(n == 2)
  {
    cout<<2<<endl<<1<<" "<<2<<endl;
    return 0;
  }
  for(int i = 0; i < n; i++)
  {
    cin>>c[i].first;
    if(c[i].first > ma)
    {
      ma = c[i].first;
      mai = i;
    }
  }
  for(int i = 0; i < n; i++)
  {
    cin>>c[i].second;
    if(c[i].second > mab && i != mai)
    {
      mab = c[i].second;
      mabi = i;
    }
  }
  for(int i = 0; i < n; i++)
    if(i != mai && i != mabi)
      v.push_back({c[i], i});
  ans.push_back(mai);
  ans.push_back(mabi);
  sort(v.begin(), v.end(), [](pair<pair<int, int>, int> x, pair<pair<int, int>, int> y){return x.first.first > y.first.first;});
  for(int i = 0; i+1 < v.size(); i+=2)
  {
    if(v[i].first.second > v[i+1].first.second)
      ans.push_back(v[i].second);
    else
      ans.push_back(v[i+1].second);
  }
  cout<<ans.size()<<endl;
  for(int i = 0; i < ans.size(); i++)
    cout<<ans[i]+1<<" ";
  cout<<endl;
  return 0;
}