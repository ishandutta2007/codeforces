#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

ll n;

ll a[1234567], x, suf[1234567];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  ll s = 0;
  for(int i = 0; i < (n+1)/2; i++)
  {
    cin>>a[i];
    s += a[i];
  }
  cin>>x;
  s += (n-(n+1)/2)*x;
  if(x >= 0)
  {
    if(s > 0)
      cout<<n<<endl;
    else
      cout<<-1<<endl;
    return 0;
  }
  ll mik = n-(n+1)/2+1;
  suf[(n+1)/2] = 0;
  for(int i = (n+1)/2-1; i >= 0; i--)
  {
    suf[i] = suf[i+1]+a[i];
  }
  for(int i = (n+1)/2-1; i >= 0; i--)
  {
    ll sum = suf[i]+(mik-((n+1)/2-i))*x;
    if(sum <= 0)
    {
      mik = (n-i)+1;
    }
  }
  if(mik <= n)
    cout<<mik<<endl;
  else
    cout<<-1<<endl;
  return 0;
}