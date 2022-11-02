#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll infi=1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
      ll n, x, y;
      cin>>n>>x>>y;
      ll px=-1;
      ll py=-1;
      ll pdf=-1;
      ll maxi=-1;
      for(ll i=1; i<n; i++)
      {
        for(ll j=i+1; j<=n; j++)
        {
          if((y-x)%(j-i)!=0) continue;
          //cout<<"ok";
          ll df=(y-x)/(j-i);
          if(0>=x-(i-1)*df) continue;
          if(maxi==-1 || x+(n-i)*df<maxi)
          {
            px=i;
            py=j;
            pdf=df;
            maxi=x+(n-i)*df;
          }
        }
      }
      ll ff=x-(px-1)*pdf;
      for(ll i=0; i<n; i++)
      {
        cout<<ff<<" ";
        ff+=pdf;
      }
      cout<<'\n';
    }


    return 0;
}