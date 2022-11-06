#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[1234];

int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>a[i];
  sort(a, a+n);
  if(a[0] == a[n/2])
    cout<<"Bob"<<endl;
  else
    cout<<"Alice"<<endl;
  return 0;
}