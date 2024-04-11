#include<iostream>

using namespace std;

long long a, b;
int t;

bool prime(long long p)
{
  long long o;
  for(o = 1; o < p; o++)
  {
    if(o*o > p)
      break;
  }
  for(int i = 2; i <= o+1 && i < p; i++)
    if(p%i == 0)
      return false;
  return true;
}

int main(int argc, char const *argv[]) {
  cin>>t;
  for(int i = 0; i < t; i++)
  {
    cin>>a>>b;
    if(a-b == 1)
    {
      if(prime(a+b))
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
    }
    else
      cout<<"NO"<<endl;
  }
  return 0;
}