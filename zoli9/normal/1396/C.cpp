#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n;
ll r1, r2, r3, r13, r;
ll d;

ll dp[1000009];
ll dpback[1000009];
ll a[1000009];

ll instantf(int x)
{
  ll res=r2+2*d+r;
  res=min(res, r13*a[x]+r1+2*d+r);
  return min(res, r13*a[x]+r3);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>r1>>r2>>r3;
    cin>>d;
    r13=min(r1, r3);
    r=min(r13, r2);
    for(int i=1; i<=n; i++)
    {
      cin>>a[i];
    }
    
    dp[n]=instantf(n);
    dpback[n]=instantf(n);
    for(int i=n-1; i>=1; i--)
    {
      ll ii=instantf(i);
      dp[i]=ii+d+dp[i+1];
      
      ll parti=min(r2+r, r13*a[i]+r1+r);
      ll parti2=min(r2+r, r13*a[i+1]+r1+r);
      dp[i]=min(dp[i], parti+2*d+dpback[i+1]);
      dpback[i]=ii+2*d+dpback[i+1];
      dpback[i]=min(dpback[i], parti+2*d+dpback[i+1]);
      if(i==n-1)
      {
        dp[i]=min(dp[i], parti+3*d+parti2);
      }
      else
      {
        dp[i]=min(dp[i], parti+4*d+parti2+dp[i+2]);
      }
    }
    /*for(int i=1; i<=n; i++)
    {
      cout<<"dp: "<<i<<": "<<dp[i]<<endl;
    }
    for(int i=1; i<=n; i++)
    {
      cout<<"dpback: "<<i<<": "<<dpback[i]<<endl;
    }*/
    cout<<dp[1]<<'\n';
    return 0;
}