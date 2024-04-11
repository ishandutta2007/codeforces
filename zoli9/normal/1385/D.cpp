#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

string s;
vi cnt[26];

int calc(int i1, int i2, int k)
{
  if(i1==i2)
  {
    if(cnt[k][i1]==cnt[k][i1-1]) return 1;
    else return 0;
  }
  int res=i2-i1+1;
  int len=i2-i1+1;
  int middle=(i1+i2)/2;
  int left=cnt[k][middle]-cnt[k][i1-1];
  int right=cnt[k][i2]-cnt[k][middle];
  res=min(res, len/2-left+calc(middle+1, i2, k+1));
  res=min(res, len/2-right+calc(i1, middle, k+1));
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    int n;
    cin>>n;
    cin>>s;
    for(int j=0; j<26; j++)
    {
      cnt[j].clear();
      cnt[j].push_back(0);
      for(int i=0; i<n; i++)
      {
        cnt[j].push_back(cnt[j].back());
        if((s[i]-'a')==j) cnt[j].back()++;
      }
    }
    cout<<calc(1, n, 0)<<'\n';
  }
  return 0;
}