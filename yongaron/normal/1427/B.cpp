#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t, k;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    string s;
    cin>>n>>k;
    cin>>s;
    vector<int> v;
    int c = 0;
    bool first = true;
    int ans = 0;
    int w = 0;
    for(int i = 0; i < n; i++)
    {
      if(s[i] == 'L')
      {
        c++;
      }
      else
      {
        ans++;
        w++;
        if(c == 0 && !first)
          ans++;
        if(!first && c > 0)
          v.push_back(c);
        c = 0;
        first = false;
      }
    }
    ans += 2*k;
    if(k+w >= n)
    {
      cout<<2*n-1<<endl;
      continue;
    }
    if(w == 0 && k > 0)
    {
      cout<<2*k-1<<endl;
      continue;
    }
    v.push_back(1e9);
    sort(v.begin(), v.end());
    int in = 0;
    while(k >= v[in])
    {
      k -= v[in];
      in++;
      ans++;
    }
    cout<<ans<<endl;
  }
  return 0;
}