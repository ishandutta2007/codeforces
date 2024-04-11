#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

int a[1234];

bool have[1234];

int mex()
{
  for(int i = 0; i <= n; i++)
    have[i] = false;
  for(int i = 0; i < n; i++)
    have[a[i]] = true;
  for(int i = 0; i <= n; i++)
    if(!have[i])
      return i;
}

bool done()
{
  for(int i = 0; i < n; i++)
    if(a[i] != i)
      return false;
  return true;
}

vector<int> ans;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i = 0; i < n; i++)
      cin>>a[i];
    ans.clear();
    while(!done())
    {
      int m = mex();
      if(m < n)
      {
        a[m] = m;
        ans.push_back(m);
      }
      else
      {
        for(int i = 0; i < n; i++)
        {
          if(a[i] != i)
          {
            a[i] = m;
            ans.push_back(i);
            break;
          }
        }
      }
    }
    cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); i++)
      cout<<ans[i]+1<<" ";
    cout<<endl;
  }
  return 0;
}