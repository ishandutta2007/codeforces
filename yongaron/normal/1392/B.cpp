#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

ll n, t, k;

ll a[223456];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    ll ma = -1e10;
    for(int i = 0; i < n; i++)
    {
      cin>>a[i];
      ma = max(ma, a[i]);
    }
    for(int i = 0; i < n; i++)
    {
      a[i] = ma-a[i];
    }
    k--;
    k %= 2;
    ma = -1e10;
    for(int i = 0; i < n; i++)
    {
      ma = max(ma, a[i]);
    }
    for(int i = 0; i < n; i++)
    {
      if(k)
        a[i] = ma-a[i];
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}