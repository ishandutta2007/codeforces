#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  cout<<3*n+4<<endl;
  cout<<0<<" "<<0<<endl;
  for(int i = 0; i < n+1; i++)
  {
    cout<<i<<" "<<i+1<<endl;
    cout<<i+1<<" "<<i<<endl;
    cout<<i+1<<" "<<i+1<<endl;
  }
  return 0;
}