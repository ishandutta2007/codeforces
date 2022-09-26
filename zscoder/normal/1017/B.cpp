#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll cnt[4];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s[2];
	for(int i=0;i<2;i++) cin>>s[i];
	for(int i=0;i<n;i++)
	{
		int bit=(s[0][i]-'0')*2+s[1][i]-'0';
		cnt[bit]++;
	}
	ll ans=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			ll ct=0;
			if(i==j) ct=(cnt[i]*(cnt[i]-1));
			else ct=cnt[i]*cnt[j];
			int b1 = ((((i&2)>0?1:0)|(i&1))<<1) + (((j&2)>0?1:0)|(j&1));
			int b2 = ((((j&2)>0?1:0)|(i&1))<<1) + (((i&2)>0?1:0)|(j&1));
			if(b1!=b2) ans+=ct;
		}
	}
	ans>>=1;
	cout<<ans<<'\n';
}