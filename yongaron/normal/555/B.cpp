#include<iostream>
#include<algorithm>
#include<set>

#define ll long long

using namespace std;

const int N = 200005;
const int M = 200005;

struct interval{
  ll l, r;
  int i;
};


ll l[N], r[N];
interval ints[N];

int n, m;

set<pair<ll, int>> st;

int ans[N];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>n>>m;
  for(int i = 0; i < n; i++)
    cin>>l[i]>>r[i];
  ll a;
  for(int i = 0; i < m; i++)
  {
    cin>>a;
    st.insert({a, i+1});
  }
  for(int i = 0; i < n-1; i++)
    ints[i] = {l[i+1]-r[i], r[i+1]-l[i], i};
  sort(ints, ints+n-1, [](interval a, interval b){return a.r < b.r;});
  for(int i = 0; i < n-1; i++)
  {
    auto it = st.lower_bound({ints[i].l, 0});
    if(it == st.end() || it->first > ints[i].r)
    {
      cout<<"No"<<endl;
      return 0;
    }
    ans[ints[i].i] = it->second;
    st.erase(it);
  }
  cout<<"Yes"<<endl;
  for(int i = 0; i < n-1; i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}