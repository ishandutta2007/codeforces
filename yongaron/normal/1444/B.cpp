#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n;

ll a[333333];

ll mod = 998244353;

long long pows[80];

void calc_pows(long long a, long long m)
{
  pows[0] = a;
  for(int i = 1; i < 40; i++)
    pows[i] = (pows[i-1]*pows[i-1])%m;
}

long long fast_pow(long long a, long long n, long long m)
{
  long long ans = 1;
  int shift = 0;
  while(n)
  {
    if(n&1)
      ans = (ans*pows[shift])%m;
    n /= 2;
    shift++;
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i < 2*n; i++)
    cin>>a[i];
  sort(a, a+2*n);
  ll s = 0;
  for(int i = 0; i < n; i++)
    s += a[n+i]-a[i];
  s %= mod;
  ll f1 = 1;
  for(ll i = 1; i <= 2*n; i++)
    f1 = (f1*i)%mod;
  ll f2 = 1;
  for(ll i = 1; i <= n; i++)
    f2 = (f2*i)%mod;
  calc_pows(f2, mod);
  ll inv = fast_pow(f2, mod-2, mod);
  cout<<(((((f1*inv)%mod)*inv)%mod)*s)%mod<<endl;
  return 0;
}