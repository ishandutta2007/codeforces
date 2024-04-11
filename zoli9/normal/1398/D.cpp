#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n;
string s;

int dp[209][209][209];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int R, G, B;
    cin>>R>>G>>B;
    vi r(R), g(G), b(B);
    for(int i=0; i<R; i++)
    {
      cin>>r[i];
    }
    for(int i=0; i<G; i++)
    {
      cin>>g[i];
    }
    for(int i=0; i<B; i++)
    {
      cin>>b[i];
    }
    r.push_back(0);
    g.push_back(0);
    b.push_back(0);
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    for(int i=0; i<=R; i++)
    {
      for(int j=0; j<=G; j++)
      {
        for(int k=0; k<=B; k++)
        {
          if(i>0 && j>0) dp[i][j][k]=max(dp[i][j][k], dp[i-1][j-1][k]+r[i]*g[j]);
          if(i>0 && k>0) dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k-1]+r[i]*b[k]);
          if(j>0 && k>0) dp[i][j][k]=max(dp[i][j][k], dp[i][j-1][k-1]+g[j]*b[k]);
        }
      }
    }
    cout<<dp[R][G][B]<<endl;


    return 0;
}