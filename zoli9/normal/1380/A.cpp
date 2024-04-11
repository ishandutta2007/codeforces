#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
      cin>>v[i];
    }
    vector<int> mini(n);
    vector<int> mini2(n);
    mini[0]=0;
    for(int i=1; i<n; i++)
    {
      mini[i]=mini[i-1];
      if(v[i]<v[mini[i]])
      {
        mini[i]=i;
      }
    }
    mini2[n-1]=n-1;
    for(int i=n-2; i>=0; i--)
    {
      mini2[i]=mini2[i+1];
      if(v[i]<v[mini2[i]])
      {
        mini2[i]=i;
      }
    }
    bool ok=false;
    for(int i=1; i<n-1; i++)
    {
      if(v[i]>v[mini[i-1]] && v[i]>v[mini2[i+1]])
      {
        ok=true;
        cout<<"YES"<<'\n';
        cout<<mini[i-1]+1<<" "<<i+1<<" "<<mini2[i+1]+1<<'\n';
        break;
      }
    }
    if(!ok)
    {
      cout<<"NO"<<'\n';
    }
  }
  
  
	return 0;
}