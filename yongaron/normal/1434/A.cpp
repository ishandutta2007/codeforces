#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

#define ll long long

using namespace std;

int n;

int a[7];
int b[123456];

set<int> bs[123456];
vector<pair<int, int>> v;

int ans = 2e9;

int ma = 0;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 6; i++)
      cin>>a[i];
    sort(a, a+6);
    cin>>n;
    for(int i = 0; i < n; i++)
    {
      cin>>b[i];
      for(int j = 0; j < 6; j++)
      {
        if(b[i]-a[j] > 0)
        {
          if(bs[i].count(b[i]-a[j]) == 0)
            v.push_back({b[i]-a[j], i});
          bs[i].insert(b[i]-a[j]);
        }
      }
      ma = max(ma, *bs[i].begin());
    }
    sort(v.begin(), v.end());
    ans = ma-v.begin()->first;
    for(int i = 0; i < v.size(); i++)
    {
      if(bs[v[i].second].size() == 1)
        break;
      bs[v[i].second].erase(v[i].first);
      ma = max(ma, *bs[v[i].second].begin());
      ans = min(ans, ma-v[i+1].first);
    }
    cout<<ans<<endl;
    return 0;
}