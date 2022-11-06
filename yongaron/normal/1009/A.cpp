#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int n, m;
int a[1234], c[1234];

int main(int argc, char const *argv[]) {
  cin>>n>>m;
  for(int i = 0; i < n; i++)
    cin>>c[i];
  for(int i = 0; i < m; i++)
    cin>>a[i];
  int cc = 0, ca = 0, b = 0;
  while(cc < n && ca < m)
  {
    if(a[ca] >= c[cc])
    {
      ca++;
      b++;
    }
    cc++;
  }
  cout<<b<<endl;
  return 0;
}