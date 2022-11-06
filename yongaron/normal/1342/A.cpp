#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int t, n;

long long x, y, a, b;

int main(int argc, char const *argv[]) {
  cin>>t;
  while(t--)
  {
    cin>>x>>y;
    cin>>a>>b;
    cout<<min((min(x, y)*b)+abs(x-y)*a, (x+y)*a)<<endl;
  }
  return 0;
}