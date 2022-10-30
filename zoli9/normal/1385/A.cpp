#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    vll a(3);
    cin>>a[0]>>a[1]>>a[2];
    sort(a.begin(), a.end());
    if(a[1]==a[2])
    {
      cout<<"YES"<<'\n';
      cout<<a[0]<<" "<<a[0]<<" "<<a[1]<<'\n';
    }
    else 
    {
      cout<<"NO"<<'\n';
    }
    
  }
  return 0;
}