#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  string s;
  while(test--)
  {
    cin>>s;
    int db[2];
    db[0]=0;
    db[1]=0;
    for(int i=0; i<s.size(); i++)
    {
      db[s[i]-'0']++;
    }
    if(min(db[0], db[1])%2==0) cout<<"NET"<<'\n';
    else cout<<"DA"<<'\n';
  }
	return 0;
}