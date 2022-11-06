#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n;

ll a, b, c;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>a>>b>>c;
  cout<<"First"<<endl;
  if(a == b || b == c || a == c)
    return 0;
  cout<<a+b+c<<endl;
  int i;
  cin>>i;
  if(i == 1)
    a += a+b+c;
  else if(i == 2)
    b += a+b+c;
  else
    c += a+b+c;
  ll ma = a;
  ma = max(ma, b);
  ma = max(ma, c);
  ll x = 3*ma-c-b-a;
  cout<<x<<endl;
  cin>>i;
  if(i == 1)
    a += x;
  else if(i == 2)
    b += x;
  else
    c += x;
  ma = a;
  ma = max(ma, b);
  ma = max(ma, c);
  ll mi = a;
  mi = min(mi, b);
  mi = min(mi, c);
  cout<<(ma-mi)/2<<endl;
  return 0;
}