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

vector<int> a[300009];
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
        vi ans(n+2, -1);
        for(int i=1; i<=n; i++)
        {
          a[i].clear();
          a[i].push_back(0);
        }
        for(int i=1; i<=n; i++)
        {
          int x;
          cin>>x;
          a[x].push_back(i);
        }
        for(int i=1; i<=n; i++)
        {
          a[i].push_back(n+1);
          int maxi=0;
          for(int j=0; j+1<a[i].size(); j++)
          {
            maxi=max(maxi, a[i][j+1]-a[i][j]);
          }
          if(ans[maxi]==-1 || i<ans[maxi])
          {
            ans[maxi]=i;
          }
        }
        cout<<ans[1];
        for(int i=2; i<=n; i++)
        {
          if(ans[i]==-1 || (ans[i-1]>=0 && ans[i-1]<ans[i]))
          {
            ans[i]=ans[i-1];
          }
          cout<<" "<<ans[i];
        }
        cout<<'\n';
    }
    return 0;
}