#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll infi=1e18;
vll x;
ll dp[200009][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
      int n;
      ll k;
      cin>>n>>k;
      x.resize(n);
      for(int i=0; i<n; i++)
      {
        cin>>x[i];
      }
      int dummy;
      for(int i=1; i<=n; i++) cin>>dummy;
      sort(x.begin(), x.end());
      x.push_back(infi);
      vll ri(n);
      int en=0;
      for(int i=0; i<n; i++)
      {
        while(x[en]<=x[i]+k) en++;
        ri[i]=en;
        //cout<<ri[i]<<endl<<endl;
      }
      dp[n][1]=0;
      dp[n][2]=0;
      for(int i=n-1; i>=0; i--)
      {
        for(int j=1; j<=2; j++)
        {
          dp[i][j]=dp[i+1][j];
          dp[i][j]=max(dp[i][j], ri[i]-i+dp[ri[i]][j-1]);
        }
      }
      cout<<dp[0][2]<<'\n';
    }


    return 0;
}