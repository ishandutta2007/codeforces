#include<iostream>

using namespace std;

int n;
int a[1234][1234];

int main()
{
  cin>>n;
  for(int i = 0; i < n/2; i++)
  {
    for(int j = 0; j < n/2; j++)
    {
      a[2*i][2*j] = n*2*i+4*j;
      a[2*i][2*j+1] = n*2*i+4*j+1;
      a[2*i+1][2*j] = n*2*i+4*j+2;
      a[2*i+1][2*j+1] = n*2*i+4*j+3;
    }
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}