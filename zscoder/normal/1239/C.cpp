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

ll ans[123456];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ll p; cin>>n>>p;
	set<int> Q;
	set<int> wait;
	priority_queue<pair<ii,int> ,vector<pair<ii,int> >,greater<pair<ii,int> > > pq;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		pq.push({{x,-1},i});
	}
	int active=1;
	queue<int> q;
	while(!pq.empty())
	{
		pair<ii,int> tp = pq.top(); pq.pop();
		ll t = tp.fi.fi; int id = tp.se; int ev=tp.fi.se;
		if(ev==-1)
		{
			if(active)
			{
				active=0;
				ans[id]=t+p;
				q.push(id); Q.insert(id);
				pq.push({{ans[id],0},id});
			}
			else
			{
				if(Q.empty()||(*Q.begin())>id)
				{
					Q.insert(id); q.push(id);
				}
				else
				{
					wait.insert(id);
				}
			}
		}
		else
		{
			Q.erase(id); assert(q.front()==id); q.pop();
			active=1;
			if(!Q.empty())
			{
				active=0;
				int id=q.front();
				ans[id]=t+p;
				pq.push({{ans[id],0},id});
				if(!wait.empty())
				{
					int x=(*wait.begin());
					if(Q.empty()||(*Q.begin())>x)
					{
						Q.insert(x); q.push(x); wait.erase(wait.begin());
					}
				}
			}
			else
			{
				if(!wait.empty())
				{
					int x=(*wait.begin());
					Q.insert(x); q.push(x); ans[x]=t+p; wait.erase(wait.begin()); pq.push({{t+p,0},x}); active=0;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}