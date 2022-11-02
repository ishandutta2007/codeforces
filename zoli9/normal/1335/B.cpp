#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll test;
	cin>>test;
	while(test--)
	{
		int n, a, b;
    cin>>n>>a>>b;
    string ans="";
    for(int i=0; i<a; i++)
    {
      if(i<b) ans+=((char)('a'+i));
      else ans+='a';
    }
    for(int i=a; i<n; i++)
    {
      ans+=ans[i-a];
    }
    cout<<ans<<'\n';
	}
	return 0;
}