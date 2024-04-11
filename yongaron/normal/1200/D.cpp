#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, k;
string lines[2222];
int lc[2222], lr[2222];
int fc[2222], fr[2222];
int pc[2222][2222], pr[2222][2222];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>k;
  for(int i = 0; i < n; i++)
  {
    cin>>lines[i];
    fc[i] = fr[i] = n;
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(lines[i][j] == 'B')
      {
        lc[i] = j;
        lr[j] = i;
        fc[i] = min(fc[i], j);
        fr[j] = min(fr[j], i);
      }
    }
  }
  int white = 0;
  for(int i = 0; i < n; i++)
  {
    if(fc[i] == n) white++;
    if(fr[i] == n) white++;
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      pc[i+1][j+1] = pc[i][j+1];
      pr[i+1][j+1] = pr[i+1][j];
      if(fc[i] != n && lc[i] < j+k && fc[i] >= j)
        pc[i+1][j+1]++;
      if(fr[j] != n && lr[j] < i+k && fr[j] >= i)
        pr[i+1][j+1]++;
    }
  }
  int ans = white;
  for(int i = 0; i+k-1 <= n; i++)
    for(int j = 0; j+k-1 <= n; j++)
      ans = max(ans, white+pr[i][j+k-1]-pr[i][j-1]+pc[i+k-1][j]-pc[i-1][j]);
  cout<<ans<<endl;
  return 0;
}