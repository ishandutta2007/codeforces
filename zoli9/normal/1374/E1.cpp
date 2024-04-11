#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

vll AA, BB, AB;
ll infi=1e15;
int n, k;

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>n>>k;
  for(int i=1; i<=n; i++)
  {
    ll t;
    int a, b;
    cin>>t>>a>>b;
    if(a==1 && b==1)
    {
      AB.push_back(t);
    }
    else if(a==1)
    {
      AA.push_back(t);
    }
    else if(b==1)
    {
      BB.push_back(t);
    }
  }
  sort(AA.begin(), AA.end());
  sort(BB.begin(), BB.end());
  sort(AB.begin(), AB.end());
  int same=0;
  int diff=0;
  ll ans=0;
  for(int i=1; i<=k; i++)
  {
    ll ss=infi;
    ll dd=infi;
    if(same<AB.size()) ss=AB[same];
    if(diff<AA.size() && diff<BB.size()) dd=AA[diff]+BB[diff];
    if(ss==infi && dd==infi)
    {
      cout<<-1<<endl;
      return 0;
    }
    if(ss<dd)
    {
      ans+=ss;
      same++;
    }
    else
    {
      ans+=dd;
      diff++;
    }
  }
  cout<<ans<<endl;
	return 0;
}