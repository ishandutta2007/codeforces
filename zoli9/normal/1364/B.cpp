#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int t[100009];

int n;

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    cin>>n;
    for(int i=1; i<=n; i++)
    {
      cin>>t[i];
    }
    vector<int> ans;
    ans.push_back(t[1]);
    for(int i=2; i<n; i++)
    {
      if(t[i]>t[i+1] && t[i]>t[i-1])
      {
        ans.push_back(t[i]);
      }
      if(t[i]<t[i+1] && t[i]<t[i-1])
      {
        ans.push_back(t[i]);
      }
    }
    ans.push_back(t[n]);
    cout<<ans.size()<<'\n';
    for(int d: ans) cout<<d<<" ";
    cout<<'\n';
  }
  
  
  
  
	return 0;
}