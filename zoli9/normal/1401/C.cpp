#include <bits/stdc++.h>
using namespace std;

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
    vll a(n);
    vll b(n);
    for(int i=0; i<n; i++)
    {
      cin>>a[i];
      b[i]=a[i];
    }
    sort(b.begin(), b.end());
    ll small=b[0];
    bool ok=true;
    for(int i=0; i<n; i++)
    {
      if(a[i]==b[i]) continue;
      if(a[i]%small!=0)
      {
        ok=false;
        break;
      }
    }
    if(ok) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
  }
	return 0;
}