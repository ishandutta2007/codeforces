#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

string s;
int n;
int x;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int test;
    cin>>test;
    while(test--)
    {
      cin>>s;
      cin>>x;
      n=s.size();
      vi a(n, 1);
      for(int i=0; i<n; i++)
      {
        if(s[i]=='0')
        {
          if(i-x>=0) a[i-x]=0;
          if(i+x<n) a[i+x]=0;
        }
      }
      bool ok=true;
      for(int i=0; i<n; i++)
      {
        if(s[i]=='1')
        {
          bool cok=false;
          if(i-x>=0 && a[i-x]==1) cok=true;
          if(i+x<n && a[i+x]==1) cok=true;
          if(!cok) ok=false;
        }
      }
      if(ok)
      {
        for(int x: a) cout<<x;
        cout<<'\n';
      }
      else
      {
        cout<<-1<<'\n';
      }
    }


    return 0;
}