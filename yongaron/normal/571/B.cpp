#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long

using namespace std;

const int N = 3e5+5;
const int K = 5005;

int n, k, l;

ll dp[K][K], a[N];


int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>n>>k;
  l = n/k;
  for(int i = 0; i < n; i++)
    cin>>a[i];
  sort(a, a+n);
  for(int i = 0; i <= k; i++)
  {
    for(int j = 0; j <= k; j++)
    {
      int p = (i+j)*l+j-1;
      if(p >= n || p < 0)
        continue;
      dp[i][j] = 1e16;
      if(i)
        dp[i][j] = min(dp[i][j], dp[i-1][j]+a[p]-a[p-l+1]);
      if(j)
        dp[i][j] = min(dp[i][j], dp[i][j-1]+a[p]-a[p-l]);
    }
  }
  cout<<dp[k-(n%k)][n%k]<<endl;
  return 0;
}