#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

int m[25];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  int a;
  for(int i = 0; i < n; i++)
  {
    cin>>a;
    for(int j = 0; j < 20; j++)
      if(a & (1<<j))
        m[j]++;
  }
  ll ans = 0;
  ll b = 0;
  for(int i = 0; i < n; i++)
  {
    b = 0;
    for(int j = 0; j < 20; j++)
      if(m[j] > i)
        b += (1<<j);
    ans += b*b;
  }
  cout<<ans<<endl;
  return 0;
}