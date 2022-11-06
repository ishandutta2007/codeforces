#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int n;

int main(int argc, char const *argv[]) {
  cin>>n;
  int l = 1e9+1;
  int a, b;
  for(int i = 0; i < n; i++)
  {
    cin>>a>>b;
    if(min(a, b) > l)
    {
      cout<<"NO"<<endl;
      return 0;
    }
    else if(max(a, b) <= l)
      l = max(a, b);
    else
      l = min(a, b);
  }
  cout<<"YES"<<endl;
  return 0;
}