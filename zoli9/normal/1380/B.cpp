#include <bits/stdc++.h>
using namespace std;
string z;
int main() {
    ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  
  while(test--)
  {
    cin>>z;
    int r=0;
    int s=0;
    int p=0;
    for(int i=0; i<z.size(); i++)
    {
      if(z[i]=='R') r++;
      if(z[i]=='S') s++;
      if(z[i]=='P') p++;
    }
    if(r>=s && r>=p)
    {
      for(int i=0; i<z.size(); i++)
      {
        cout<<'P';
      }
      cout<<'\n';
    }
    else if(s>=p)
    {
      for(int i=0; i<z.size(); i++)
      {
        cout<<'R';
      }
      cout<<'\n';
    }
    else
    {
      for(int i=0; i<z.size(); i++)
      {
        cout<<'S';
      }
      cout<<'\n';
    }
  }
  
  
	return 0;
}