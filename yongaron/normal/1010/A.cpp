#include<iostream>
#include<iomanip>

using namespace std;

int n;
double m, m0;
double a[1234], b[1234];

int main(int argc, char const *argv[]) {
  cin>>n>>m;
  m0 = m;
  for(int i = 0; i < n; i++)
    cin>>a[i];
  for(int i = 0; i < n; i++)
    cin>>b[i];
  for(int i = 0; i < n; i++)
  {
    if(a[i] <= 1 || b[i] <= 1)
    {
      cout<<-1<<endl;
      return 0;
    }
  }
  m = m+m/(b[0]-1);
  for(int i = n-1; i; i--)
  {
    m = m+m/(a[i]-1);
    m = m+m/(b[i]-1);
  }
  m = m+m/(a[0]-1);
  cout<<fixed<<setprecision(10)<<m-m0<<endl;
  return 0;
}