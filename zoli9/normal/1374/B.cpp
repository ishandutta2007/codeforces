#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    ll n;
    cin>>n;
    ll ketto=0;
    ll harom=0;
    while(n%2==0)
    {
      n/=2;
      ketto++;
    }
    while(n%3==0)
    {
      n/=3;
      harom++;
    }
    if(n>1 || ketto>harom)
    {
      cout<<-1<<'\n';
      continue;
    }
    ll pl=harom-ketto;
    cout<<pl+harom<<'\n';
  }
	return 0;
}