#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
int n;
int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    cin>>n;
    vector<ll> w(109, 0);
    for(int i=0; i<n; i++)
    {
      ll x;
      cin>>x;
      int cnt=0;
      while(x>0)
      {
        if(x%2) w[cnt]++;
        x/=2;
        cnt++;
      }
    }
    int big=-1;
    for(int i=100; i>=0; i--)
    {
      if(w[i]%2==1)
      {
        big=i;
        break;
      }
    }
    if(big==-1)
    {
      cout<<"DRAW"<<'\n';
      continue;
    }
    ll y=w[big];
    ll z=y/2;
    if(z%2==0 || n%2==0)
    {
      cout<<"WIN"<<'\n';
      continue;
    }
    cout<<"LOSE"<<'\n';
  }
	return 0;
}