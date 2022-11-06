#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int n, m;

int p[12345];
long long c[12345];
vector<long long> voters[12345];
vector<long long> all;

int main(int argc, char const *argv[]) {
  cin>>n>>m;
  for(int i = 0; i < n; i++)
  {
    cin>>p[i]>>c[i];
    voters[p[i]].push_back(c[i]);
  }
  for(int i = 0; i <= m; i++)
    sort(voters[i].begin(), voters[i].end());
  long long ans = 1e15;
  for(int i = 1; i <= n; i++)
  {
    all.clear();
    long long c = 0;
    int v = voters[1].size();
    for(int j = 2; j <= m; j++)
    {
      int in = 0;
      while(voters[j].size()-in >= i)
      {
        c += voters[j][in];
        in++;
      }
      v += in;
      while(in < voters[j].size())
      {
        all.push_back(voters[j][in]);
        in++;
      }
    }
    sort(all.begin(), all.end());
    int in = 0;
    while(v < i)
    {
      c += all[in];
      in++;
      v++;
    }
    ans = min(ans, c);
  }
  cout<<ans<<endl;
  return 0;
}