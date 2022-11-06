#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

int a[12345];

ll s;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n;
    s = 0;
    for(int i = 0; i < n; i++)
    {
      cin>>a[i];
      s+= a[i];
    }
    if(s == 0)
      cout<<"NO"<<endl;
    else
    {
      cout<<"YES"<<endl;
      sort(a, a+n);
      if(s > 0)
        reverse(a, a+n);
      for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
      cout<<endl;
    }
    
  }
  return 0;
}