#include<iostream>

using namespace std;

long long n, m;

int main(int argc, char const *argv[]) {
  cin>>n>>m;
  long long x = 0;
  while(x*(x-1)/2 < m)
    x++;
  cout<<max((long long)0, n-2*m)<<" "<<n-x<<endl;
  return 0;
}