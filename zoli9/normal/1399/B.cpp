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
    ll ans=0;
    vll a(n);
    vll b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    ll mina=a[0];
    ll minb=b[0];
    for(int i=0; i<n; i++) mina=min(mina, a[i]);
    for(int i=0; i<n; i++) minb=min(minb, b[i]);
    for(int i=0; i<n; i++)
    {
      ll pl=max(a[i]-mina, b[i]-minb);
      ans+=pl;
    }
    cout<<ans<<'\n';
  }
}