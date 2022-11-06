#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n;
ll k;
ll a[123456];

ll kolik(int i, ll m)
{
  ll l = 0, r = a[i], mm;
  // cout<<"kolik "<<i<<" "<<m<<endl;
  while(l < r)
  {
    mm = (l+r+1)/2;
    // cout<<l<<" "<<mm<<" "<<r<<endl;
    ll dif = a[i]-3*mm*mm+3*mm-1;
    if(dif >= m)
      l = mm;
    else
      r = mm-1;
  }
  // cout<<l<<endl<<endl;
  return l;
}

ll total(ll m)
{
  ll ans = 0;
  for(int i = 0; i < n; i++)
    ans += kolik(i, m);
  return ans;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>k;
  for(int i = 0; i < n; i++)
    cin>>a[i];
  ll l = -4e18;
  ll r = 4e18;
  ll m;
  if(n == 1)
  {
    cout<<k<<endl;
    return 0;
  }
  while(l < r)
  {
    m = l/2+r/2;
    if(l%2 ==1 && r%2 == 1)
      m++;
    // cout<<"!"<<l<<" "<<m<<" "<<r<<endl;
    ll t = total(m);
    // cout<<t<<endl;
    if(t >= k)
    {
      l = m;
    }
    if(t < k)
    {
      r = m-1;
    }
  }
  ll have = total(r);
  ll much = have-k;
  for(int i = 0; i < n; i++)
  {
    ll b = kolik(i, r);
    if(a[i]-3*b*b+3*b-1 == r && much)
    {
      b--;
      much--;
    }
    cout<<b<<" ";
  }
  cout<<endl;
  return 0;
}