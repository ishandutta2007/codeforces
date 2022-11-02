#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

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
      int x=0;
      int y=n-1;
      int cnt=0;
      while(x<=y)
      {
        if(cnt==0)
        {
          cout<<a[x]<<" ";
          x++;
        }
        else
        {
          cout<<a[y]<<" ";
          y--;
        }
        cnt=1-cnt;
      }
      cout<<'\n';
    }
    return 0;
}