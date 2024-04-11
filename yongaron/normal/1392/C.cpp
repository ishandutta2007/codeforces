#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

ll a[223456];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n;
    int ma = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
      cin>>a[i];
    }
    for(int i = n-1; i > 0; i--)
    {
      if(a[i-1] > a[i])
        ans += a[i-1]-a[i];
    }
    cout<<ans<<endl;
  }
  return 0;
}