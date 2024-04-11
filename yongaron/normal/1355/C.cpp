#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

ll a, b, c, d;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>a>>b>>c>>d;
  ll ans = 0;
  for(ll x = a; x <= b; x++)
  {

    ll newb = b;
    ll newc = c;

    if(d-x+1 <= c)
    {
      ans += (c-max(b, (d-x+1))+1)*(d-c+1);
      newc = d-x;
    }


    if(c-x+1 >= b)
    {
      newb = c-x+1;
    }



    if(newb <= newc)
    {
      ll mi = min(x+newb-1, d)-c+1;
      ll ma = min(x+newc-1, d)-c+1;
      ans += (newc-newb+1)*(mi+ma)/2;
    }
  }
  cout<<ans<<endl;
  return 0;
}