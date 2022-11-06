#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t, k;

int a[222222], b[222222], ind[222222];
bool tokill[222222];

ll mod = 998244353;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    ll ans = 1;
    for(int i = 0; i < n; i++)
    {
      cin>>a[i];
      ind[a[i]] = i;
      tokill[i] = false;
    }
    for(int i = 0; i < k; i++)
    {
      cin>>b[i];
      int j = ind[b[i]];
      tokill[j] = true;
    }
    for(int i = 0; i < k; i++)
    {
      int j = ind[b[i]];
      ll mul = 2;
      if(j == 0 || tokill[j-1])
        mul--;
      if(j == n-1 || tokill[j+1])
        mul--;
      tokill[j] = false;
      ans = (ans*mul)%mod;
    }
    cout<<ans<<endl;
  }
  return 0;
}