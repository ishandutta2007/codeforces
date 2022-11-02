#include <iostream>
using namespace std;

int main() {
  int w;
  cin>>w;
  int n;
  cin>>n;
  int k;
  cin>>k;
  int sz=1;
  int t=(k*(k+1)/2)*w;
  if(t-n>0)
  {
   cout<<t-n; 
  }
  else
  {
    cout<<0;
  }
}