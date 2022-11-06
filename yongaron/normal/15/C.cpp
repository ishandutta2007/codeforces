#include<iostream>

#define ll long long

using namespace std;

int n;
ll m, x;
ll ans;

int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    cin>>x>>m;
    x--;
    if(x%4 == 0)
      ans ^= x;
    if(x%4 == 1)
      ans ^= 1;
    if(x%4 == 2)
      ans ^= x+1;
    x += m;
    if(x%4 == 0)
      ans ^= x;
    if(x%4 == 1)
      ans ^= 1;
    if(x%4 == 2)
      ans ^= x+1;
  }
  cout<< (ans ? "tolik" : "bolik") << endl;
  return 0;
}