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
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
      cin>>s;
      n=s.size();
      int cnt=0;
      vi x;
      for(int i=0; i<n; i++)
      {
        if(s[i]=='1') cnt++;
        else
        {
          if(cnt>0) x.push_back(cnt);
          cnt=0;
        }
      }
      if(cnt>0) x.push_back(cnt);
      sort(x.begin(), x.end());
      reverse(x.begin(), x.end());
      int ans=0;
      for(int i=0; i<x.size(); i++)
      {
        if(i%2==0) ans+=x[i];
      }
      cout<<ans<<'\n';
      
      
    }


    return 0;
}