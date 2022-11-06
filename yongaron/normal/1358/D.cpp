#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;
ll d[1234567], sd[1234567];

ll ans = 0;
ll x;


int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>x;
  ll s = 0, l = 0;
  int ind = 0;
  for(int i = 0; i < n; i++)
  {
    cin>>d[i];
    d[n+i] = d[i];
    sd[i] = sd[n+i] = d[i]*(d[i]+1)/2;
    s += sd[i];
    l += d[i];
  }
  while(l-d[ind] >= x)
  {
    l -= d[ind];
    s -= sd[ind];
    ind++;
  }
  ans = s-(l-x)*(l-x+1)/2;
  for(int i = n; i < 2*n; i++)
  {
    l += d[i];
    s += sd[i];
    while(l-d[ind] >= x)
    {
      l -= d[ind];
      s -= sd[ind];
      ind++;
    }
    ans = max(ans, s-(l-x)*(l-x+1)/2);
  }
  cout<<ans<<endl;
  return 0;
}