#include<iostream>

using namespace std;

int t;
long long s, a, b, c;

int main(int argc, char const *argv[]) {
  cin>>t;
  for(int l = 0; l < t; l++)
  {
    cin>>s>>a>>b>>c;
    long long bon = s/(a*c);
    long long ans = bon*(a+b)+(s-bon*c*a)/c;
    cout<<ans<<endl;
  }
  return 0;
}