#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int n;
int a[123456], b[123456];

int main(int argc, char const *argv[]) {
  cin>>n;
  char c;
  for(int i = 0; i < n; i++)
  {
    cin>>c;
    a[i] = c-'0';
  }
  for(int i = 0; i < n; i++)
  {
    cin>>c;
    b[i] = c-'0';
  }
  long long zeros = 0, ones = 0, doubz = 0, doubo = 0;
  for(int i = 0; i < n; i++)
  {
    if(!a[i] && !b[i])
      doubz++;
    else if(!a[i])
      zeros++;
    else if(a[i] && b[i])
      doubo++;
    else
      ones++;
  }
  cout<<doubz*(ones+doubo)+ones*zeros<<endl;
  return 0;
}