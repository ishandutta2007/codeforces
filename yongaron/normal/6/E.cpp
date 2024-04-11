#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int n, k;
deque<pair<int, int>> mi, ma;

int l = 0;


void pop()
{
  if(mi.front().second > ma.front().second)
  {
    l = max(ma.front().second+1, l);
    ma.pop_front();
  }
  else
  {
    l = max(mi.front().second+1, l);
    mi.pop_front();
  }
}

int dif()
{
  return ma.front().first-mi.front().first;
}

int len()
{
  return ma.back().second - l + 1;
}

void add(int a, int i)
{
  while(mi.size() && mi.back().first > a)
    mi.pop_back();
  mi.push_back({a, i});
  while(ma.size() && ma.back().first < a)
    ma.pop_back();
  ma.push_back({a, i});
}

int best = 0;
vector<int> ans;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie();
  cin>>n>>k;
  int a;
  for(int i = 0; i < n; i++)
  {
    cin>>a;
    add(a, i);
    while(dif() > k)
      pop();
    if(len() > best)
    {
      best = len();
      ans = {i};
    }
    else if(len() == best)
      ans.push_back(i);
  }
  cout<<best<<" "<<ans.size()<<endl;
  for(int i = 0; i < ans.size(); i++)
    cout<<ans[i]-best+2<<" "<<ans[i]+1<<endl;
  return 0;
}