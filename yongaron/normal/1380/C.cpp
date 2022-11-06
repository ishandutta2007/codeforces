#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

ll a[123456];
ll x;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>x;
    for(int i = 0; i < n; i++)
      cin>>a[i];
    sort(a, a+n);
    int ans = -1;
    int mi = 0;
    for(int i = 0; i < n; i++)
    {
      int y = i+x/a[i];
      if(x%a[i])
        y++;
      if(i >= mi)
      {
        ans++;
        mi = y;
      }
      if(y < mi)
        mi = y;
      // cout<<"! "<<i<<" "<<mi<<" "<<ans<<endl;
    }
    if(mi == n)
      ans++;
    cout<<ans<<endl;
  }
  return 0;
}