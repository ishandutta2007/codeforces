#include<iostream>
#include<algorithm>

using namespace std;

char a[123456];

int n;

int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>a[i];
  sort(a, a+n);
  for(int i = 0; i < n; i++)
    cout<<a[i];
  cout<<endl;
  return 0;
}