#include<iostream>

using namespace std;

int t, n;

int main(int argc, char const *argv[]) {
  cin>>t;
  while(t--)
  {
    cin>>n;
    if(n == 1)
      cout<<-1<<endl;
    else
    {
      cout<<8;
      for(int i = 0; i < n-1; i++)
        cout<<9;
      cout<<endl;
    }
  }
  return 0;
}