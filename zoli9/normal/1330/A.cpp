#include <iostream>
using namespace std;

bool b[209];

int main() {
	int test;
  cin>>test;
  int n, x;
  while(test--)
  {
    cin>>n>>x;
    for(int i=1; i<=210; i++)
    {
      b[i]=false;
    }
    for(int i=1; i<=n; i++)
    {
      int z;
      cin>>z;
      b[z]=true;
    }
    int cnt=1;
    while(x--)
    {
      while(b[cnt]) cnt++;
      b[cnt]=true;
    }
    while(b[cnt]) cnt++;
    cout<<cnt-1<<'\n';
  }
}