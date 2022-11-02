#include <iostream>
using namespace std;

int main() {
	int darab[109];
  int sz=1;
  while(sz<=100)
  {
    darab[sz]=0;
    sz=sz+1;
  }
  int v;
  cin>>v;
  int szam;
  sz=0;               
  while(sz<v)
  {
    cin>>szam;
    darab[szam]=darab[szam]+1;
    sz=sz+1;
  }
  int vegsovalasz=0;
  sz=1;
  while(sz<=100)
  {
    vegsovalasz=max(vegsovalasz, darab[sz]);
    sz=sz+1;
  }
  cout<<vegsovalasz;
}