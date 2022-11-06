#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

long long p, m = 1e9+7;

long long pows[80];

void calc_pows(ll a)
{
  pows[0] = a;
  for(int i = 1; i < 40; i++)
    pows[i] = (pows[i-1]*pows[i-1])%m;
}

long long fast_pow(ll a, ll e)
{
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

ll k[1234567];

ll dif = 0;
ll real = 0;
bool lost;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>p;
    calc_pows(p);
    for(int i = 0; i < n; i++)
      cin>>k[i];
    sort(k, k+n);
    ll last = k[n-1];
    dif = real = 0;
    lost = false;
    for(int i = n-1; i >= 0; i--)
    {
      if(dif)
      {
        while(last > k[i] && !lost && p != 1)
        {
          last--;
          dif *= p;
          if(dif > 1e6)
            lost = true;
        }
        dif--;
        real = (real+m-fast_pow(p, k[i]))%m;
      }
      else
      {
        dif = 1;
        real = fast_pow(p, k[i]);
      }
      last = k[i];
    }
    cout<<real<<endl;
  }
  return 0;
}