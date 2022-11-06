#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

long long n, t, k;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    for(long long i = 0; i < k-1; i++)
    {
      ll mi = 9;
      ll ma = 0;
      long long x = n;
      while(x)
      {
        mi = min(mi, x%10);
        ma = max(ma, x%10);
        x /= 10;
      }
      n += mi*ma;
      if(!mi)
        break;
    }
    cout<<n<<endl;
  }
  return 0;
}