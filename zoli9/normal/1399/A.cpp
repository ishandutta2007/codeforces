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
    vi a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    bool ok=true;
    for(int i=1; i<n; i++)
    {
      if(a[i]>a[i-1]+1) ok=false;
    }
    if(ok) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
  }
}