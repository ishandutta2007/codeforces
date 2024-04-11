#include<iostream>

using namespace std;

long long d, m;
int t;

int main(int argc, char const *argv[]) {
  cin>>t;
  while(t--)
  {
    cin>>d>>m;
    d++;
    long long pow;
    long long last = 0%m;
    for(pow = 1; pow <= d; pow *= 2)
    {
      // cout<<pow/2<<" "<<last<<endl;
      last = (pow/2+(pow/2)*last+last)%m;
    }
    pow /= 2;
    cout<<(d-pow+(d-pow)*last+last)%m<<endl;
  }
}