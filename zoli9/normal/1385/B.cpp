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
    int n;
    cin>>n;
    vi ans;
    vector<bool> w(n+1, false);
    for(int i=1; i<=2*n; i++)
    {
      int x;
      cin>>x;
      if(!w[x])
      {
        ans.push_back(x);
        w[x]=true;
      }
    }
    for(int x: ans) cout<<x<<" ";
    cout<<'\n';
  }
  return 0;
}