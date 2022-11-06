#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n;

int a[1234];

vector<pair<int, pair<int, int>>> v;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>a[i];
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
      if(a[i] > a[j])
        v.push_back({-j, {a[i], i}});
  sort(v.begin(), v.end());
  cout<<v.size()<<endl;
  for(int i = 0; i < v.size(); i++)
    cout<<v[i].second.second+1<<" "<<-v[i].first+1<<endl;
  return 0;
}