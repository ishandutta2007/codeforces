#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

ll n;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  ll h, s = 0;
  for(int i = 0; i < n; i++)
  {
    cin>>h;
    s += h;
  }
  s -= n*(n-1)/2;
  ll b = s/n;
  s %= n;
  for(int i = 0; i < n; i++)
  {
    if(i < s)
      cout<<b+i+1<<" ";
    else
      cout<<b+i<<" ";
  }
  cout<<endl;
  return 0;
}