#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

long long n, m;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin>>n>>m;
  long long s = 0;
  long long x, d;
  long long ma = n*(n-1)/2;
  long long mi = (n/2)*(n/2+1)/2+(n/2-1)*(n/2)/2;
  if(n%2 == 1)
    mi = (n/2)*(n/2+1);
  for(int i = 0; i < m; i++)
  {
    cin>>x>>d;
    if(d > 0)
      s += n*x+ma*d;
    else
      s += n*x+mi*d;
  }
  cout<<fixed<<std::setprecision(15)<<(double)(s)/(double)(n)<<endl;;
  return 0;
}