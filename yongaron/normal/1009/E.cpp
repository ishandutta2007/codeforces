#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;


long long mod = 998244353;
long long n;
long long a[1234567];
long long pw[1234567];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>a[i];
  pw[0] = 1;
  for(long long i = 1; i <= n+3; i++)
    pw[i] = 2*pw[i-1]%mod;
  long long s = 0;
  for(long long i = 1; i < n; i++)
    s = (s+a[i-1]*((pw[n-i]+pw[n-i-1]*(n-i))%mod))%mod;
  s = (s+a[n-1])%mod;
  cout<<s<<endl;
  return 0;
}