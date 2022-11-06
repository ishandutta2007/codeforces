#include<iostream>

using namespace std;

int n, m, k;

int main(int argc, char const *argv[]) {
  cin>>n>>m>>k;
  int x, y;
  for(int i = 0; i < k; i++)
  {
    cin>>x>>y;
    if(min(x, y) < 6 || min(n-x, m-y) < 5)
    {
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}