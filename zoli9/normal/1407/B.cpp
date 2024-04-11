#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int gg[1009][1009];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    for(int i=1; i<=1000; i++)
    {
        for(int j=i; j<=1000; j++)
        {
            gg[i][j]=__gcd(i, j);
            gg[j][i]=gg[i][j];
        }
    }
    cin>>test;
    while(test--)
    {
      cin>>n;
      vi cn(1009, 0);
      int maxi=0;
      for(int i=1; i<=n; i++)
      {
          int x;
          cin>>x;
          cn[x]++;
          maxi=max(maxi, x);
      }
      for(int i=1; i<=cn[maxi]; i++)
      {
          cout<<maxi<<" ";
      }
      cn[maxi]=0;
      while(1)
      {
          int best=-1;
          int pl=-1;
          for(int i=1; i<=1000; i++)
          {
              if(cn[i]>0)
              {
                  if(best==-1 || gg[maxi][i]>best)
                  {
                      best=gg[maxi][i];
                      pl=i;
                  }
              }
          }
          if(best<=1) break;
          maxi=best;
          for(int i=1; i<=cn[pl]; i++)
          {
              cout<<pl<<" ";
          }
          cn[pl]=0;
      }
      for(int i=1; i<=1000; i++)
      {
          for(int j=1; j<=cn[i]; j++)
          {
              cout<<i<<" ";
          }
      }
      cout<<'\n';
    }

    return 0;
}