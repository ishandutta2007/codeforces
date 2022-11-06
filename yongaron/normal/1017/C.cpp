#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int n, o;

int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i <= n+1; i++)
  {
    if(i*i > n)
    {
      o = i-1;
      break;
    }
  }
  int res = n-o*o;
  int c = n;
  int ma = o;
  if(res > o)
  {
    ma++;
    res = n-o*ma;
  }
  for(int i = 0; i < ma; i++)
  {
    int x = o;
    if(res > 0)
    {
      x++;
      res--;
    }
    int l = c-x+1;
    for(int j = l; j <= c; j++)
      cout<<j<<" ";
    c = l-1;
  }
  cout<<endl;
  return 0;
}