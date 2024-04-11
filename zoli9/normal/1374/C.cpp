#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

string s;

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    int n;
    cin>>n;
    cin>>s;
    int cnt=0;
    int mini=0;
    for(int i=0; i<n; i++)
    {
      if(s[i]=='(')
      {
        cnt++;
      }
      else
      {
        cnt--;
        mini=min(mini, cnt);
      }
    }
    cout<<-mini<<'\n';
  }
	return 0;
}