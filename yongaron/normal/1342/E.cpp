#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

ll n, k;

ll m = 998244353;
ll ans = 1;
ll sub = 1;

ll pows[80];

ll fact[223456];

void calc_pows(ll a)
{
  pows[0] = a;
  for(int i = 1; i < 40; i++)
    pows[i] = (pows[i-1]*pows[i-1])%m;
}

ll fast_pow(ll a, ll e)
{
  calc_pows(a);
  ll ans = 1;
  int shift = 0;
  while(e)
  {
    if(e&1)
      ans = (ans*pows[shift])%m;
    e /= 2;
    shift++;
  }
  return ans;
}

ll inv(ll x)
{
  return fast_pow(x, m-2);
}

ll choose(ll nn, ll kk)
{
  return (fact[nn]*(inv(fact[kk]*fact[nn-kk]%m)))%m;
}

int main(int argc, char const *argv[]) {
  cin>>n>>k;
  if(k >= n)
  {
    cout<<0<<endl;
    return 0;
  }
  fact[0] = 1;
  for(int i = 0; i < n; i++)
    fact[i+1] = (fact[i]*(i+1))%m;
  ll sig = 1;
  ll ans = 0;
  for(int i = n-k; i > 0; i--, sig *= -1)
  {
    // cout<<sig<<" "<<i<<" "<<fast_pow(i, n)<<" "<<choose(n-k, i)<<endl;
    ans = (ans+m+(sig*fast_pow(i, n)*choose(n-k, i))%m)%m;
    // cout<<ans<<endl;
  }
  if(k)
    ans = ans*2%m;
  cout<<ans*choose(n, k)%m<<endl;
  return 0;
}