#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

int a[333333];
int mis[333333];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i = 0; i < n; i++)
      cin>>a[i];
    int mi = 1e9;
    ll tor = 0;
    bool ok = true;
    for(int i = 0; i < n; i++)
    {
      a[i] -= tor;
      if(a[i] < 0)
        ok = false;
      mi = min(mi, a[i]);
      tor += a[i]-mi;
    }

    if(ok)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}