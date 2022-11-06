#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int n;
int a[123456];

int main(int argc, char const *argv[]) {
  cin>>n;
  if(n%4 != 0)
  {
    cout<<"! -1"<<endl;
    fflush(stdout);
    return 0;
  }
  cout<<"? "<<1<<endl;
  fflush(stdout);
  cin>>a[1];
  cout<<"? "<<n/2+1<<endl;
  fflush(stdout);
  cin>>a[n/2+1];
  cout<<"? "<<n/4<<endl;
  fflush(stdout);
  cin>>a[n/4];
  cout<<"? "<<n/4+n/2<<endl;
  fflush(stdout);
  cin>>a[n/2+n/4];
  if(a[1] == a[n/2+1])
  {
    cout<<"! 1"<<endl;
    fflush(stdout);
    return 0;
  }
  if(a[n/4] == a[n/2+n/4])
  {
    cout<<"! "<<n/4<<endl;
    fflush(stdout);
    return 0;
  }
  int l, r, m;
  if((a[n/2+1]-a[1] > 0 && a[n/2+n/4]-a[n/4] > 0) || (a[n/2+1]-a[1] < 0 && a[n/2+n/4]-a[n/4] < 0))
  {
    l = n/4;
    r = n/2;
  }
  else
  {
    l = 1;
    r = n/4;
  }
  while(r-l >= 2)
  {
    m = (l+r+1)/2;
    cout<<"? "<<m<<endl;
    fflush(stdout);
    cin>>a[m];
    cout<<"? "<<n/2+m<<endl;
    fflush(stdout);
    cin>>a[n/2+m];
    if(a[m] == a[n/2+m])
    {
      cout<<"! "<<m<<endl;
      fflush(stdout);
      return 0;
    }
    if((a[n/2+l]-a[l] > 0 && a[n/2+m]-a[m] > 0) || (a[n/2+l]-a[l] < 0 && a[n/2+m]-a[m] < 0))
      l = m;
    else
      r = m;
  }
  cout<<"? "<<l<<endl;
  fflush(stdout);
  cin>>a[l];
  cout<<"? "<<n/2+l<<endl;
  fflush(stdout);
  cin>>a[n/2+l];
  if(a[l] == a[n/2+l])
  {
    cout<<"! "<<l<<endl;
    fflush(stdout);
    return 0;
  }
  if(n/2+l+1 <= n)
  {
    cout<<"? "<<l+1<<endl;
    fflush(stdout);
    cin>>a[l+1];
    cout<<"? "<<n/2+l+1<<endl;
    fflush(stdout);
    cin>>a[n/2+l+1];
    if(a[l+1] == a[n/2+l+1])
    {
      cout<<"! "<<l+1<<endl;
      fflush(stdout);
      return 0;
    }
  }
  cout<<"! "<<-1<<endl;
  fflush(stdout);
  return 0;
}