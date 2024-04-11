#include<iostream>

using namespace std;

int n, ax, bx, cx, ay, by, cy;

int main(int argc, char const *argv[]) {
  cin>>n>>ax>>ay>>bx>>by>>cx>>cy;
  if(cx > ax && ax > bx)
  {
    cout<<"NO"<<endl;
    return 0;
  }
  if(cx < ax && ax < bx)
  {
    cout<<"NO"<<endl;
    return 0;
  }
  if(cy > ay && ay > by)
  {
    cout<<"NO"<<endl;
    return 0;
  }
  if(cy < ay && ay < by)
  {
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
  return 0;
}