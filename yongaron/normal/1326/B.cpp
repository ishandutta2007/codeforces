#include<iostream>

using namespace std;

int n;
int b[1234567];
int ma = 0;

int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    cin>>b[i];
    int a = b[i]+ma;
    ma = max(a, ma);
    cout<<a<<" ";
  }
  cout<<endl;
  return 0;
}