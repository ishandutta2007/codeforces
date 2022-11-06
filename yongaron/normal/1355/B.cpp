#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;
int a[1234567];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i = 0; i < n; i++)
      cin>>a[i];
    sort(a, a+n);
    int ans = 0;
    for(int i = 0; i < n;)
    {
      int c = i;
      int w = c+a[i];
      while(i < w && i < n)
      {
        w = c+a[i];
        i++;
      }
      if(i <= n && i == w)
        ans++;
    }
    cout<<ans<<endl;
  }
  return 0;
}