#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

ll a, b;

ll gcd(ll x, ll y)
{
  while(x && y)
  {
    if(x > y)
      x %= y;
    else
      y %= x;
  }
  return x+y;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>a;
  vector<pair<bool, pair<ll, ll>>> ans;
  
  ans.push_back({0, {a, a}});

  ll m = (1LL)<<(44);
  b = a;
  ll x = 1;
  while(gcd(b^a, a) != 1)
  {
    // ans.push_back({1, {b, a}});
    b += a;
    x++;
  }

  ll aa = a;
  while(2*aa < m)
  {
    ans.push_back({1, {aa, aa}});
    aa *= 2;
  }

  ll tmp = 0;

  for(int i = 0; i < 45; i++)
  {
    if(x&((1LL)<<i))
    {
      ans.push_back({1, {tmp, a*((1LL)<<i)}});
      tmp += a*((1LL)<<i);
    }
  }

  ll k = 1;

  ans.push_back({0, {b, a}});
  b ^= a;

  // cout<<"!"<<a<<" "<<b<<endl;

  while((m-k*b)%a)
  {
    // ans.push_back({1, {k*b, b}});
    k++;
  }

  tmp = 0;

  ll bb = b;
  while(2*bb < m)
  {
    ans.push_back({1, {bb, bb}});
    bb *= 2;
  }
  for(int i = 0; i < 45; i++)
  {
    if(k&((1LL)<<i))
    {
      ans.push_back({1, {tmp, b*((1LL)<<i)}});
      tmp += b*((1LL)<<i);
    }
  }

  // cout<<"!"<<a<<" "<<b<<" "<<k<<endl;

  ll l = (m-k*b)/a;
  aa = a;
  while(2*aa < m)
  {
    ans.push_back({1, {aa, aa}});
    aa *= 2;
  }

  tmp = 0;

  for(int i = 0; i < 45; i++)
  {
    if(l&((1LL)<<i))
    {
      ans.push_back({1, {tmp, a*((1LL)<<i)}});
      tmp += a*((1LL)<<i);
    }
  }

  ans.push_back({1, {k*b, l*a}});

  ll f = a;

  // cout<<"!"<<endl;

  while(m > 1)
  {
    // cout<<m<<" "<<f<<endl;
    if(m&f)
    {
      ans.push_back({0, {m, f}});
      f ^= m;
    }
    if(__builtin_popcountll(f) == 1)
    {
      m = f;
      if(m < a)
      {
        while(2*m < a)
        {
          ans.push_back({1, {m, m}});
          m *= 2;
        }
        ans.push_back({0, {m, a}});
        a -= m;
      }
      f = a;
    }
    else
    {
      ans.push_back({1, {f, f}});
      f *= 2;
    }
  }

  cout<<ans.size()<<endl;
  for(int i = 0; i < ans.size(); i++)
  {
    if(ans[i].first)
      cout<<ans[i].second.first<<" + "<<ans[i].second.second<<endl;
    else
      cout<<ans[i].second.first<<" ^ "<<ans[i].second.second<<endl;
  }
  return 0;
}