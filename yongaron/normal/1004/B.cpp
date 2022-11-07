#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, m;

int main(int argc, char const *argv[]) {
  cin>>n>>m;
  for(int i = 0; i < m; i++)
  {
    int l, r;
    cin>>l>>r;
  }
  for(int i = 0; i < n; i++)
    cout<<i%2;
  cout<<endl;
  return 0;
}