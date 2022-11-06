#include<iostream>
#include<algorithm>

using namespace std;

int a[3], d;

int main(int argc, char const *argv[]) {
  cin>>a[0]>>a[1]>>a[2]>>d;
  sort(a, a+3);
  int ans = 0;
  if(a[1]-a[0] < d)
    ans += d-(a[1]-a[0]);

  if(a[2]-a[1] < d)
    ans += d-(a[2]-a[1]);

  cout<<ans<<endl;
  return 0;
}