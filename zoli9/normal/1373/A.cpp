#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    ll a, b, c;
    cin>>a>>b>>c;
    if(a<c) cout<<1<<" ";
    else cout<<-1<<" ";
    if(a*b>c) cout<<b<<endl;
    else cout<<-1<<endl;
  }
	return 0;
}