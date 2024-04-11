#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin>>n;
  ll sum=0;
  for(int i=1; i<=n; i++)
  {
    ll xx;
    cin>>xx;
    sum+=xx;
  }
  ll sum1n=((n-1)*n)/2;
  ll small=sum-sum1n;
  small/=n;
  ll rem=sum-(sum1n)-(n*small);
  for(ll i=1; i<=n; i++)
  {
    ll res=small+i-1;
    if(i<=rem) res++;
    cout<<res<<" ";
  }
  cout<<endl;
	return 0;
}