#include <bits/stdc++.h>
using namespace std;

int a[200009];
bool jo1[200009];
bool jo2[200009];

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
      cin>>a[i];
    }
    int maxi=0;
    vector<bool> volt1(n+1, false);
    vector<bool> volt2(n+1, false);
    bool ok1=true;
    bool ok2=true;
    for(int i=1; i<=n; i++)
    {
      jo1[i]=ok1;
      if(!ok1) continue;
      if(a[i]>n || volt1[a[i]])
      {
        jo1[i]=false;
        ok1=false;
        continue;
      }
      volt1[a[i]]=true;
      maxi=max(maxi, a[i]);
      if(i==maxi) jo1[i]=true;
      else jo1[i]=false;
    }
    maxi=0;
    for(int i=1; i<=n; i++)
    {
      jo2[i]=ok2;
      if(!ok2) continue;
      if(a[n-i+1]>n || volt2[a[n-i+1]])
      {
        jo2[i]=false;
        ok2=false;
        continue;
      }
      volt2[a[n-i+1]]=true;
      maxi=max(maxi, a[n-i+1]);
      if(i==maxi) jo2[i]=true;
      else jo2[i]=false;
    }
    vector<int> ans;
    for(int i=1; i<n; i++)
    {
      if(jo1[i] && jo2[n-i]) ans.push_back(i);
    }
    cout<<(ans.size())<<'\n';
    for(int i: ans)
    {
      cout<<i<<" "<<n-i<<'\n';
    }
  }
	return 0;
}