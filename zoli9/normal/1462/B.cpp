#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

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
      string s;
      cin>>s;
      if(s[0]=='2' && s[1]=='0' && s[2]=='2' && s[3]=='0') cout<<"YES"<<'\n';
      else if(s[0]=='2' && s[1]=='0' && s[2]=='2' && s[n-1]=='0') cout<<"YES"<<'\n';
      else if(s[0]=='2' && s[1]=='0' && s[n-2]=='2' && s[n-1]=='0') cout<<"YES"<<'\n';
      else if(s[0]=='2' && s[n-3]=='0' && s[n-2]=='2' && s[n-1]=='0') cout<<"YES"<<'\n';
      else if(s[n-4]=='2' && s[n-3]=='0' && s[n-2]=='2' && s[n-1]=='0') cout<<"YES"<<'\n';
      else cout<<"NO"<<'\n';
    }
    return 0;
}