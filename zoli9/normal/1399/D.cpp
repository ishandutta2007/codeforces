#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

string s;

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    int n;
    cin>>n;
    cin>>s;
    vi s0, s1;
    vi ans(n);
    int cnt=0;
    for(int i=0; i<n; i++)
    {
      int x=s[i]-'0';
      if(x==0)
      {
        if(s1.size()>0)
        {
          int tp=s1.back();
          s1.pop_back();
          s0.push_back(tp);
          ans[i]=tp;
        }
        else
        {
          cnt++;
          s0.push_back(cnt);
          ans[i]=cnt;
        }
      }
      else
      {
        if(s0.size()>0)
        {
          int tp=s0.back();
          s0.pop_back();
          s1.push_back(tp);
          ans[i]=tp;
        }
        else
        {
          cnt++;
          s1.push_back(cnt);
          ans[i]=cnt;
        }
      }
    }
    cout<<cnt<<'\n';
    for(int i=0; i<n; i++)
    {
      cout<<ans[i]<<" ";
    }
    cout<<'\n';
    
  }
}