#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

ll m = 1e9+7;

ll ans[2234567];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for(int i = 2; i < 2234567; i++)
  {
    ans[i] = 2*ans[i-2]+ans[i-1];
    if(i%3 == 0)
      ans[i] += 4;
    ans[i] %= m;
  }
  cin>>t;
  while(t--)
  {
    cin>>n;
    cout<<ans[n]<<endl;
  }
  return 0;
}