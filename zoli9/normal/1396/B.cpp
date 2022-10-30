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
    int n;
    while(test--)
    {
      cin>>n;
      int maxi=0;
      int sum=0;
      for(int i=1; i<=n; i++)
      {
        int x;
        cin>>x;
        sum+=x;
        maxi=max(maxi, x);
      }
      if(maxi>sum-maxi || sum%2==1)
      {
        cout<<"T"<<'\n';
      }
      else
      {
        cout<<"HL"<<'\n';
      }
    }
    return 0;
}