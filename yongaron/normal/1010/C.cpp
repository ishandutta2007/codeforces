#include<iostream>
#include<iomanip>

using namespace std;

int n, k;

int c;
bool pos[132456];

int gcd(int a, int b)
{
  while(a && b)
  {
    if(a > b)
      a %= b;
    else
      b %= a;
  }
  return a+b;
}

int main(int argc, char const *argv[]) {
  cin>>n>>k;
  int a;
  c = k;
  for(int i = 0; i < n; i++)
  {
    cin>>a;
    a %= k;
    c = gcd(c, a);
  }
  int s = 0;
  int ans = 0;
  while(!pos[s])
  {
    pos[s] = true;
    ans++;
    s = (s+c)%k;
  }
  cout<<ans<<endl;
  for(int i = 0; i < k; i++)
    if(pos[i])
      cout<<i<<" ";
  cout<<endl;
  return 0;
}