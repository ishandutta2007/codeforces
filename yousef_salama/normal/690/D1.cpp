#include <bits/stdc++.h>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define EPS 1e-8
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))
#define bits(a) __builtin_popcount(a)

using namespace std;

char s[555];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i=0;i<n;i++)
    scanf("%s", s);
  int c = 0;
  for(int i=0;i<m;i++)
  {
    if(s[i] == '.') continue;
    if(i == 0 || s[i-1] == '.')
      c++;
  }
  cout << c;
  return 0;
}