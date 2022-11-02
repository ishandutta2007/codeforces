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
      vi db(109, 0);
      for(int i=1; i<=n; i++)
      {
        int x;
        cin>>x;
        db[x]++;
      }
      int cnt=0;
      int ans=0;
      for(int i=0; i<=101; i++)
      {
        if(db[i]>=2) continue;
        if(db[i]==1)
        {
          if(cnt==0)
          {
            ans+=i;
            cnt=1;
          }
        }
        else
        {
          if(cnt==0)
          {
            ans+=(2*i);
          }
          else if(cnt==1)
          {
            ans+=i;
          }
          break;
        }
      }
      cout<<ans<<'\n';
    }

    return 0;
}