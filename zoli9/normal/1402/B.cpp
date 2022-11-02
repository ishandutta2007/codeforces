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
      ll a, b;
      cin>>a>>b;
      ll ans=abs(a-b);
      ll ans2=ans/10;
      if(ans%10!=0) ans2++;
      cout<<ans2<<'\n';
    }


    return 0;
}