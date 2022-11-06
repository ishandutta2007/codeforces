#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int t;
ll a, b, n;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>a>>b>>n;
    int ans = 0;
    if(a < b)
      swap(a, b);
    while(a <= n)
    {
      b += a;
      swap(a, b);
      ans++;
    }
    cout<<ans<<endl;
  }
  return 0;
}