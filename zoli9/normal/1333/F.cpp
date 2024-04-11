#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef vector<int> vi;

bool comp[500009];
int mindiv[500009];
int pr=1;
vi ans;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for(int i=2; i<=n; i++)
  {
    if(comp[i]) continue;
    pr++;
    mindiv[i]=i;
    for(int j=2*i; j<=n; j+=i)
    {
      if(!comp[j])
      {
        mindiv[j]=i;
        comp[j]=true;
      }
    }
  }
  ans.push_back(1);
  ans.push_back(pr);
  int round=2;
  while(pr!=n)
  {
    for(int j=1; j<=round; j++)
    {
      if(j*round>n) break;
      if(comp[j*round] && j*round/mindiv[j*round]<=round)
      {
        comp[j*round]=false;
        pr++;
      }
    }
    ans.push_back(pr);
    round++;
  }
  for(int i=1; i<ans.size(); i++)
  {
    for(int j=ans[i-1]; j<ans[i]; j++)
    {
      cout<<i<<" ";
    }
  }
  cout<<'\n';
  
  
  
  return 0;
}