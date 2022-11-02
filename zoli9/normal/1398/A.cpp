#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int a[100009];
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
      for(int i=1; i<=n; i++)
      {
        cin>>a[i];
      }
      if(a[1]+a[2]<=a[n])
      {
        cout<<1<<" "<<2<<" "<<n<<endl;
      }
      else cout<<-1<<endl;
    }


    return 0;
}