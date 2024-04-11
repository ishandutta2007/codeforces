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
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	n=s.length();
	int lo=0; int hi=2*n+1;
	int ans=hi;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		deque<int> pacman;
		deque<int> bad;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='P') pacman.pb(i);
			else if(s[i]=='*') bad.pb(i);
		}
		bool pos=1;
		while(!bad.empty())
		{
			if(pacman.empty())
			{
				pos=0;
				break;
			}
			int f = pacman[0];
			int hd = bad[0];
			if(f<hd)
			{
				//[f, f+mid]
				while(!bad.empty()&&bad.front()<=f+mid)
				{
					bad.pop_front();
				}
				pacman.pop_front();
			}
			else
			{
				int dist = f - hd;
				if(dist<=mid)
				{
					if(mid-2*dist >= max(0,(mid-dist)/2))
					{
						while(!bad.empty()&&bad.front()<f)
						{
							bad.pop_front();
						}
						dist += f-hd;
						dist = mid - dist;
						if(dist>=0)
						{
							while(!bad.empty()&&bad.front()<=f+dist)
							{
								bad.pop_front();
							}
						}
					}
					else
					{
						while(!bad.empty()&&bad.front()<f)
						{
							bad.pop_front();
						}
						dist = (mid - dist);
						if(dist>=0)
						{
							dist/=2;
							while(!bad.empty()&&bad.front()<=f+dist)
							{
								bad.pop_front();
							}
						}
					}
				}
				pacman.pop_front();
			}
		}
		if(pos)
		{
			ans=mid;
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}
	cout<<ans<<'\n';
}