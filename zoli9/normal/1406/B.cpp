#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int test;
    cin>>test;
    while(test--)
    {
      cin>>n;
      vll a(n);
      for(int i=0; i<n; i++)
      {
        cin>>a[i];
      }
      ll ans=a[0]*a[1]*a[2]*a[3]*a[4];
      sort(a.begin(), a.end());
      ans=max(ans, a[0]*a[1]*a[2]*a[3]*a[n-1]);
      ans=max(ans, a[0]*a[1]*a[n-1]*a[n-2]*a[n-3]);
      ans=max(ans, a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5]);
      cout<<ans<<'\n';
    }

    return 0;
}