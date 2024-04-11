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
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

set<vi> s;
vector<vi> V;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n,kk; cin>>n>>kk;
	for(int i=0;i<n;i++)
	{
		vi vec(kk);
		for(int j=0;j<kk;j++) cin>>vec[j];
		s.insert(vec);
	}
	for(auto it = s.begin(); it != s.end(); it++) V.pb((*it));
	int siz=int(V.size());
	for(int i=0;i<(1<<siz); i++)
	{
		if(i==0) continue;
		int cnt[4]={};
		for(int j=0;j<siz;j++)
		{
			if(i&(1<<j))
			{
				for(int k=0;k<kk;k++)
				{
					if(V[j][k]==1) cnt[k]--;
					else cnt[k]++;
				}
			}
		}
		bool pos=1;
		for(int j=0;j<kk;j++)
		{
			if(cnt[j]<0)
			{
				pos=0;
				break;
			}
		}
		if(pos)
		{
			cout<<"YES\n"; return 0;
		}
	}
	cout<<"NO\n";
}