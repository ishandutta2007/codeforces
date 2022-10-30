#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int t[100009];

int n, x;

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    cin>>n>>x;
    for(int i=1; i<=n; i++)
    {
      int elm;
      cin>>elm;
      t[i]=(t[i-1]+elm)%x;
    }
    if(t[0]!=t[n])
    {
      cout<<n<<'\n';
      continue;
    }
    int f1=-1;
    int f2=-1;
    for(int i=1; i<=n; i++)
    {
      if(t[i]!=t[0])
      {
        f1=i;
        break;
      }
    }
    for(int i=n-1; i>=0; i--)
    {
      if(t[i]!=t[0])
      {
        f2=i;
        break;
      }
    }
    if(f1==-1)
    {
      cout<<-1<<'\n';
      continue;
    }
    int maxi=max(f2, n-f1);
    cout<<maxi<<'\n';
  }
  
  
	return 0;
}