#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, t;

int a[123456];
bool was[123456];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i = 0; i < n; i++)
    {
      cin>>a[i];
      was[a[i]] = false;
    }
    int ma = 0;
    was[0] = true;
    bool ok = true;
    for(int i = n-1; i > 0; i--)
    {
      was[a[i]] = true;
      if(a[i-1] == a[i]-1 || was[a[i]-1])
      {
        ;
      }
      else
        ok = false;
    }
    if(ok)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
  return 0;
}