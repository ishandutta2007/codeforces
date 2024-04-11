#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    int a;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
      cin>>a;
      if(i%2 == 1)
        cout<<abs(a)<<" ";
      else
        cout<<-abs(a)<<" ";
    }
    cout<<endl;
  }
  return 0;
}