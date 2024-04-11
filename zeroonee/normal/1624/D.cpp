#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int a[26];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while (t--)
	{
		int n,m,i,r=0,rr=0;
		string s;
		cin>>n>>m>>s;
		memset(a,0,sizeof a);
		for (auto c:s) ++a[c-'a'];
		for (i=0;i<26;i++) if (a[i]&1) ++r;
		//for (i=0;i<26;i++) if (a[i]) cerr<<a[i]<<' ';cerr<<endl;
		for (i=0;i<26;i++) rr+=a[i]>>1<<1;
		int ans=rr/2/m*2;
		r+=rr-ans*m;
		cout<<ans+(r>=m)<<'\n';
	}
}