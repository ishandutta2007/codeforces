#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

ll a, b, c, d;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>a>>b>>c>>d;
    if(a > b*c)
    {
      cout<<-1<<endl;
      continue;
    }
    ll diff = d*b;
    ll times = a/diff;
    ll e = a-diff*times;
    cout<<((e+a)*(times+1))/2<<endl;
  }
  return 0;
}