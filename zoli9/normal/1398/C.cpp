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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
      cin>>n;
      cin>>s;
      ll ans=0;
      map<int, int> ma;
      ma[0]=1;
      int sum=0;
      for(int i=0; i<n; i++)
      {
        sum+=(s[i]-'0');
        ans+=ma[sum-i-1];
        ma[sum-i-1]++;
      }
      cout<<ans<<'\n';
      
      
      
    }


    return 0;
}