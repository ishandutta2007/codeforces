#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;
string s, z;
int db[29][29];
int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    for(int i=0; i<=20; i++)
    {
      for(int j=0; j<=20; j++)
      {
        db[i][j]=0;
      }
    }
    cin>>n;
    cin>>s;
    cin>>z;
    int ans=0;
    for(int i=0; i<n; i++)
    {
      int c1=s[i]-'a';
      int c2=z[i]-'a';
      db[c1][c2]++;
      if(c1>c2)
      {
        ans=-1;
        break;
      }
    }
    if(ans<0)
    {
      cout<<-1<<'\n';
      continue;
    }
    for(int i=0; i<20; i++)
    {
      int mini=-1;
      for(int j=i+1; j<20; j++)
      {
        if(db[i][j]>0)
        {
          mini=j;
          break;
        }
      }
      if(mini<0) continue;
      ans++;
      for(int j=i+1; j<20; j++)
      {
        db[mini][j]+=db[i][j];
      }
    }
    cout<<ans<<endl;
  }
	return 0;
}