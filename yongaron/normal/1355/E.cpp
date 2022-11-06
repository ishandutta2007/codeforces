#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

ll n, a, r, m;
ll h[123456];
ll ans = 1e18;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>a>>r>>m;
  m = min(m, a+r);
  ll sum = 0;
  for(int i = 0; i < n; i++)
  {
    cin>>h[i];
    sum += h[i];
  }
  sort(h, h+n);
  ll chybi = 0;
  ll navic = sum-h[0]*n;
  ans = navic*r;
  ll hh = sum/n;
  ll ch = 0, nv = 0;
  for(int i = 0; i < n; i++)
  {
    if(h[i] > hh)
      nv += h[i]-hh;
    else
      ch += hh-h[i];
  }
  ans = min(ans, m*min(ch, nv)+a*(ch-min(ch, nv))+r*(nv-min(ch, nv)));
  hh++;
  ch = nv = 0;
  for(int i = 0; i < n; i++)
  {
    if(h[i] > hh)
      nv += h[i]-hh;
    else
      ch += hh-h[i];
  }
  ans = min(ans, m*min(ch, nv)+a*(ch-min(ch, nv))+r*(nv-min(ch, nv)));
  for(int i = 1; i < n; i++)
  {
    chybi += i*(h[i]-h[i-1]);
    navic -= (n-i)*(h[i]-h[i-1]);
    ans = min(ans, m*min(chybi, navic)+a*(chybi-min(chybi, navic))+r*(navic-min(chybi, navic)));
  }
  cout<<ans<<endl;
  return 0;
}