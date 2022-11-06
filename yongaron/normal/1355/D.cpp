#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, s;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>s;
  if(s < 2*n)
    cout<<"NO"<<endl;
  else
  {
    cout<<"YES"<<endl;
    for(int i = 0; i < n-1; i++)
      cout<<2<<" ";
    cout<<s-(2*n-2)<<endl;
    cout<<1<<endl;
  }
  return 0;
}