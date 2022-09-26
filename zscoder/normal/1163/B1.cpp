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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi D[222222];
int cnt[222222];

multiset<int> S;

void ins(int x)
{
	S.insert(x);
}

void del(int x)
{
	S.erase(S.find(x));
}

int a[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j+=i) D[j].pb(i);
	}
	int ans=1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cnt[a[0]]++;
	ins(1);
	for(int i=1;i<n;i++)
	{
		bool pos=0;
		if(cnt[a[i]]>0) del(cnt[a[i]]);
		cnt[a[i]]++;
		ins(cnt[a[i]]);
		for(int d:D[i])
		{
			//cerr<<i<<' '<<d<<' '<<S.size()<<endl;
			if(S.size()==i/d&&(*(prev(S.end())))==d+1)
			{
				if(S.size()==1||(*S.begin())==d)	pos=1;
			}
			if(S.size()==i/d+1&&(*S.begin())==1)
			{
				if((*prev(S.end()))==d) pos=1;
			}
			//cerr<<"E: "<<i<<' '<<d<<' '<<S.size()<<endl;
		}
		
		if(pos) ans=i+1;
	}
	cout<<ans<<'\n';
}