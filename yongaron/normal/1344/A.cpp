#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

int x[223456];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n;
    bool ok = true;
    for(int i = 0; i < n; i++)
    {
      x[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
      int a;
      cin>>a;
      a = ((i+a)%n+n)%n;
      if(x[a]++)
        ok = false;
    }
    if(ok)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}