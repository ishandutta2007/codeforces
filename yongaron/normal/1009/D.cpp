#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

vector<int> graf[123456];

int gcd(int a, int b)
{
  while(a && b)
  {
    if(a > b)
      a%=b;
    else
      b%=a;
  }
  return a+b;
}

int n, m;

int main(int argc, char const *argv[]) {
  cin>>n>>m;
  int c = 1, x = 0;
  while(x < m)
  {
    c++;
    for(int i = 1; i < c; i++)
    {
      if(gcd(i, c) == 1)
      {
        x++;
        graf[i].push_back(c);
      }
    }
  }
  if(c > n || m < n-1)
  {
    cout<<"Impossible"<<endl;
    return 0;
  }
  cout<<"Possible"<<endl;
  c = 0;
  for(int i = 2; i <= n; i++, c++)
    cout<<1<<" "<<i<<endl;
  for(int i = 2; c < m; i++)
  {
    for(int j = 0; j < graf[i].size() && c < m; j++, c++)
      cout<<i<<" "<<graf[i][j]<<endl;
  }
  return 0;
}