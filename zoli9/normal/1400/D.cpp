#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

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
      vi a(n+1);
      vector<vi> pref(n+1, vi(n+1, 0));
      for(int i=1; i<=n; i++)
      {
        cin>>a[i];
        for(int j=1; j<=n; j++)
        {
          pref[j][i]=pref[j][i-1];
          if(a[i]==j) pref[j][i]++;
        }
      }
      ll ans=0;
      for(int i=1; i<=n; i++)
      {
        ll cnt=pref[i][n];
        ll pl=cnt*(cnt-1)*(cnt-2)*(cnt-3);
        pl/=24;
        ans+=pl;
      }
      for(int i=1; i<=n; i++)
      {
        for(int j=i+1; j<=n; j++)
        {
          if(a[i]==a[j]) continue;
          ll left=pref[a[j]][i-1];
          ll right=pref[a[i]][n]-pref[a[i]][j];
          ll pl=left*right;
          ans+=pl;
        }
      }
      cout<<ans<<'\n';
    }


    return 0;
}