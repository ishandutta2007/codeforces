#include <iostream>
using namespace std;
int main()
{
 int n;
 long long s;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  if(x>=0)cout<<(s+=x)<<' ';
  else cout<<s+x<<' ';
 }
 return 0;
}