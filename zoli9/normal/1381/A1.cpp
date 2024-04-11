#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


    string s;
    string z;
    
void sw(int idx)
{
  int c1=0;
  int c2=idx;
  while(c1<=c2)
  {
    if(c1==c2)
    {
      if(s[c1]=='0') s[c1]='1';
      else s[c1]='0';
      return;
    }
    swap(s[c1], s[c2]);
    if(s[c1]=='0') s[c1]='1';
      else s[c1]='0';
    if(s[c2]=='0') s[c2]='1';
      else s[c2]='0';
    c1++;
    c2--;
  }
}
    
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
    cin>>z;
    vector<int> ans;
    for(int i=n-1; i>=0; i--)
    {
      if(s[i]==z[i]) continue;
      if(s[0]==z[i])
      {
        ans.push_back(0);
        if(s[0]=='0') s[0]='1';
        else s[0]='0';
      }
      sw(i);
      ans.push_back(i);
    }
    cout<<ans.size();
    for(int x: ans) cout<<" "<<x+1;
    cout<<'\n';
  }
	return 0;
}