#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

ll k;
ll m[10];
string c = "codeforces";

ll tot()
{
  ll ans = 1;
  for(int i = 0; i < 10; i++)
    ans *= m[i];
  return ans;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>k;
  for(int i = 0; i < 10; i++)
    m[i] = 0;
  int ind = 0;
  while(tot() < k)
  {
    m[ind]++;
    ind = (ind+1)%10;
  }
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < m[i]; j++)
      cout<<c[i];
  cout<<endl;
  return 0;
}