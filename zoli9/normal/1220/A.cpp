#include <iostream>
using namespace std;

int main() {
  int b;
  cin>>b;
  string h;
  cin>>h;
  int sz=0;
  while(b>sz)
  {
    if(h[sz]=='n')
    {
      cout<<1<<" ";
    }
    sz=sz+1;
  }
  sz=0;
  while(b>sz)
  {
    if(h[sz]=='z')
    {
      cout<<0<<" ";
    }
    sz=sz+1;
  }
}