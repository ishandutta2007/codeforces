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
    if(a[0] < a[n-1])
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}