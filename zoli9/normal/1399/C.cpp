#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    int n;
    cin>>n;
    vi a(n+1, 0);
    vi db(2*n+1, 0);
    for(int i=0; i<n; i++)
    {
      int x;
      cin>>x;
      a[x]++;
    }
    for(int i=1; i<=n; i++)
    {
      for(int j=i; j<=n; j++)
      {
        if(i==j)
        {
          db[2*i]+=(a[i]/2);
          continue;
        }
        db[i+j]+=(min(a[i], a[j]));
      }
    }
    int ans=0;
    for(int i=0; i<=2*n; i++)
    {
      ans=max(ans, db[i]);
    }
    cout<<ans<<'\n';
    
  }
}