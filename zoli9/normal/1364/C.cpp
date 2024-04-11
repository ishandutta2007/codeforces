#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[100009];

int n;

int last[1000009];

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>a[i];
    last[a[i]]=i;
  }
  last[0]=1;
  for(int i=1; i<n; i++)
  {
    if(a[i]>a[i+1])
    {
      cout<<-1<<endl;
      return 0;
    }
  }
  int cnt=0;
  for(int i=1; i<=n; i++)
  {
    if(a[i]!=a[i-1])
    {
      cout<<a[i-1]<<" ";
      continue;
    }
    while(last[cnt]>0) cnt++;
    cout<<cnt<<" ";
    cnt++;
  }
  cout<<endl;
  
  
  
	return 0;
}