#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

ll x1, y1, x2, y2;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>x1>>y1>>x2>>y2;
    cout<<(y2-y1+1)*(x2-x1+1)-(x2-x1)-(y2-y1)<<endl;
  }
  return 0;
}