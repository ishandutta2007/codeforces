#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  
  while(test--)
  {
    cin>>s;
    int n=s.size();
    vll v(n+1, 0);
    ll res=0;
    ll depth=0;
    v[0]=0;
    for(int i=0; i<n; i++)
    {
      if(s[i]=='+')
      {
        v[i+1]=v[i]+1;
      }
      else
      {
        v[i+1]=v[i]-1;
        if(v[i+1]<depth)
        {
          res+=(i+1);
          depth=v[i+1];
        }
      }
    }
    cout<<res+n<<'\n';
  }
	return 0;
}