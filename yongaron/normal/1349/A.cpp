#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n;
ll a[123456];
bool p[223456];
ll times[223456][2];
int was[223456];
vector<ll> ps;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    cin>>a[i];
  }
  for(int i = 2; i < 223456; i++)
  {
    p[i] = true;
    times[i][0] = times[i][1] = 1e6;
  }
  for(int i = 2; i < 1000; i++)
  {
    if(p[i])
    {
      for(int j = 2; i*j < 1000; j++)
        p[i*j] = false;
      ps.push_back(i);
    }
  }
  for(int i = 0; i < n; i++)
  {
    int x;
    for(int j = 0; j < ps.size(); j++)
    {
      x = 0;
      while((a[i]%ps[j]) == 0)
      {
        x++;
        a[i] /= ps[j];
      }
      if(x < times[ps[j]][0])
      {
        times[ps[j]][1] = times[ps[j]][0];
        times[ps[j]][0] = x;
      }
      else if(x < times[ps[j]][1])
      {
        times[ps[j]][1] = x;
      }
      was[ps[j]]++;
    }
    x = 1;
    if(x < times[a[i]][0])
    {
      times[a[i]][1] = times[a[i]][0];
      times[a[i]][0] = x;
    }
    else if(x < times[a[i]][1])
    {
      times[a[i]][1] = x;
    }
    was[a[i]]++;
  }
  ll ans = 1;
  for(ll i = 2; i < 223456; i++)
  {
    if(p[i])
    {
      int x = times[i][1];
      if(was[i] < n)
        x = times[i][0];
      if(was[i] < n-1)
        x = 0;
      while(x--)
        ans *= i;
    }
  }
  cout<<ans<<endl;
  return 0;
}