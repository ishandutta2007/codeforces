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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll dist[10111*1011];
const ll INF = ll(1e18);

int m,g;

int getid(int x, int y)
{
	assert(y>0); assert(y<=g);
	y--;
	return (x*g+y);
}

deque<int> dq;
vi pos;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x; cin>>x; pos.pb(x);
	}
	sort(pos.begin(),pos.end());
	pos.erase(unique(pos.begin(),pos.end()),pos.end());
	m=pos.size();
	cin>>g; int r; cin>>r;
	for(int i=0;i<m;i++)
	{
		for(int j=1;j<=g;j++)
		{
			dist[getid(i,j)]=INF;
		}
	}
	assert(pos[m-1]==n);
	for(int i=g;i>=1;i--)
	{
		dist[getid(m-1,i)]=g-i;
		if(i==g) dist[getid(m-1,i)]=-r;
		dq.push_back(getid(m-1,i));
	}
	ll lastd=-ll(1e18);
	while(!dq.empty())
	{
		ll d = dist[dq.front()];
		//assert(d>=lastd); lastd=d;
		int id = dq.front()/g;
		int t = dq.front()%g+1;
		dq.pop_front();
		//go to id-1
		if(id-1>=0&&id-1<m)
		{
			int distance = pos[id]-pos[id-1];
			if(t==g)
			{
				if(distance<=g&&dist[getid(id-1,distance)]>d+g+r)
				{
					dist[getid(id-1,distance)]=d+g+r;
					dq.push_back(getid(id-1,distance));
				}
			}
			else
			{
				if(distance+t<=g&&dist[getid(id-1,distance+t)]>d)
				{
					dist[getid(id-1,distance+t)]=d;
					dq.push_front(getid(id-1,distance+t));
				}
			}
		}
		//go to id+1
		if(id+1>=0&&id+1<m)
		{
			int distance = pos[id+1]-pos[id];
			if(t==g)
			{
				if(distance<=g&&dist[getid(id+1,distance)]>d+g+r)
				{
					dist[getid(id+1,distance)]=d+g+r;
					dq.push_back(getid(id+1,distance));
				}
			}
			else
			{
				if(distance+t<=g&&dist[getid(id+1,distance+t)]>d)
				{
					dist[getid(id+1,distance+t)]=d;
					dq.push_front(getid(id+1,distance+t));
				}
			}
		}
	}
	if(dist[getid(0,g)]>=INF) dist[getid(0,g)]=-1;
	cout<<dist[getid(0,g)]<<'\n';
}