#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, k;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
      cin>>n>>k;
      cin>>s;
      int db0=0;
      int db1=0;
      bool ans=true;
      for(int i=0; i<k; i++)
      {
        bool w0=false;
        bool w1=false;
        for(int j=i; j<n; j+=k)
        {
          if(s[j]=='1') w1=true;
          if(s[j]=='0') w0=true;
        }
        if(w0 && w1)
        {
          ans=false;
          break;
        }
        else if(w0) db0++;
        else if(w1) db1++;
      }
      if(!ans)
      {
        cout<<"NO"<<'\n';
        continue;
      }
      if(db0<=k/2 && db1<=k/2)
      {
        cout<<"YES"<<'\n';
      }
      else
      {
        cout<<"NO"<<'\n';
      }
    }


    return 0;
}