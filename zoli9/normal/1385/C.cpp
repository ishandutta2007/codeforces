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
    vi a(n);
    for(int i=0; i<n; i++)
    {
      cin>>a[i];
    }
    int cnt=n-2;
    while(cnt>=0 && a[cnt]>=a[cnt+1]) cnt--;
    while(cnt>=0 && a[cnt]<=a[cnt+1]) cnt--;
    cout<<cnt+1<<'\n';
  }
  return 0;
}