#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  
  int test;
  cin>>test;
  while(test--)
  {
    int n;
    cin>>n;
    vi a(n);
    bool same=true;
    for(int i=0; i<n; i++)
    {
      cin>>a[i];
      if(i>0 && a[i]!=a[i-1]) same=false;
    }
    if(same) cout<<n<<'\n';
    else cout<<1<<'\n';
  }
  
	return 0;
}