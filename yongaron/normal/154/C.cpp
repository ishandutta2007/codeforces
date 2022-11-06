#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long

using namespace std;

const int N = 1e6+5;

ll n, m;

ll pw[N], base = 37;
ll hsh[N], hsh2[N];

ll ans;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>n>>m;
  pw[0] = 1;
  for(int i = 0; i < n; i++)
    pw[i+1] = pw[i]*37;
  for(int i = 0; i < n; i++)
    hsh2[i] = pw[i];
  int a, b;
  for(int i = 0; i < m; i++)
  {
    cin>>a>>b;
    a--;
    b--;
    hsh[a] += pw[b];
    hsh2[a] += pw[b];
    hsh[b] += pw[a];
    hsh2[b] += pw[a];
  }
  sort(hsh, hsh+n);
  sort(hsh2, hsh2+n);
  for(int i = 0; i < n; i++)
  {
    ll cur = 1;
    while(i+1 < n && hsh[i] == hsh[i+1])
    {
      cur++;
      i++;
    }
    ans += cur*(cur-1)/2;
  }
  for(int i = 0; i < n; i++)
  {
    ll cur = 1;
    while(i+1 < n && hsh2[i] == hsh2[i+1])
    {
      cur++;
      i++;
    }
    ans += cur*(cur-1)/2;
  }
  cout<<ans<<endl;
  return 0;
}