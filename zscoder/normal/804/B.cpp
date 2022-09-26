#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int MOD = 1e9 + 7;

ll pow2[1000001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	int n = s.length();
	pow2[0]=1;
	for(int i=1;i<=n;i++)
	{
		pow2[i]=(pow2[i-1]*2)%MOD;
		if(pow2[i]<0) pow2[i]+=MOD;
	}
	deque<int> vec;
	bool st = 0;
	if(s[0]=='b') st=1;
	int cnt=1;
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i-1])
		{
			cnt++;
		}
		else
		{
			vec.pb(cnt);
			cnt=1;
		}
	}
	vec.pb(cnt);
	ll ans = 0;
	if(st) vec.pop_front();
	ll sum = 0;
	while(!vec.empty())
	{
		if(vec.size()==1) break;
		ll a = vec[0]; ll b = vec[1];
		sum+=a;
		ll ways = ((pow2[sum]+MOD-1)%MOD*b)%MOD;
		if(ways<0) ways+=MOD;
		ans+=ways;
		ans%=MOD;
		if(ans<0) ans+=MOD;
		vec.pop_front();vec.pop_front();
	}
	ans%=MOD;
	if(ans<0) ans+=MOD;
	cout<<ans<<'\n';
}