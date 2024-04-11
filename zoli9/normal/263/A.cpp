#include <iostream>
using namespace std;

int main() {
  int v;
  int f=0;
  int sor=0;
  int oszlop=0;
  int s=1,o=1;
  while(s<=5)
  {
    o=1;
    while(o<=5)
    {
      cin>>v;
      if(v==1)
      {
        sor=s;
        oszlop=o;
      }
      o=o+1;
    }
    s=s+1;
  }
  sor=sor-3;
  oszlop=oszlop-3;
  if(sor<0)
  {
    sor=sor*-1;
  }
  if(oszlop<0)
  {
    oszlop=oszlop*-1;
  }
  cout<<oszlop+sor;
}