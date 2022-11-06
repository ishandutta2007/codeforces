#include<iostream>
#include<iomanip>

using namespace std;

int n, m;
bool lie[50];

int main(int argc, char const *argv[]) {
  cin>>m>>n;
  for(int i = 0; i < n; i++)
  {
    cout<<1<<endl;
    int a;
    cin>>a;
    if(!a)
      return 0;
    else if(a == 1)
      lie[i] = 0;
    else
      lie[i] = 1;
  }
  int i = 0;
  int l = 2;
  int r = m;
  while(l <= r)
  {
    int mid = (l+r)/2;
    cout<<mid<<endl;
    int a;
    cin>>a;
    if((lie[i] && a == 1) || (!lie[i] && a == -1))
      r = mid-1;
    else if((lie[i] && a == -1) || (!lie[i] && a == 1))
      l = mid+1;
    else
      return 0;
    i = (i+1)%n;
  }
  return 0;
}