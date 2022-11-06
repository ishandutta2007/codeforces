#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int a, b;
  cout<<"? ";
  for(int i = 1; i <= 100; i++)
    cout<<i<<" ";
  cout<<endl;
  cin>>a;
  cout<<"? ";
  for(int i = 1; i <= 100; i++)
    cout<<(i<<7)<<" ";
  cout<<endl;
  cin>>b;
  cout<<"! "<<((a>>7)<<7)+b%(1<<7)<<endl;
  return 0;
}