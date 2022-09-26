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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int C = 111;
int hsh(pair<int,ii> &tmp)
{
	return (tmp.fi*C*C+tmp.se.fi*C+tmp.se.se);
}

pair<int,ii> unhsh(int x)
{
	int a,b,c;
	c=x%C;
	x/=C;
	b=x%C;
	x/=C;
	a=x%C;
	return mp(a,mp(b,c));
}

int vis[2000011];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	queue<pair<int,ii> > q;
	for(int i=0;i<2000010;i++) vis[i]=int(1e9);
	int n,pos,l,r; cin>>n>>pos>>l>>r;
	q.push(mp(pos,mp(1,n)));
	vis[hsh(q.front())]=0;
	while(!q.empty())
	{
		pair<int,ii> u = q.front(); q.pop();
		int h2=hsh(u);
		int a=u.se.fi; int b=u.se.se; int p=u.fi;
		vector<pair<int,ii> > vec = {{max(p-1,a),{a,b}}, {min(p+1,b),{a,b}}, {p,{p,b}}, {p,{a,p}}};
		for(int i=0;i<vec.size();i++)
		{
			int h = hsh(vec[i]);
			if(vis[h2]+1<vis[h])
			{
				vis[h]=vis[h2]+1;
				q.push(vec[i]);
			}
		}
	}
	int ans=100000;
	for(int i=l;i<=r;i++)
	{
		pair<int,ii> tmp = mp(i,mp(l,r));
		ans=min(ans,vis[hsh(tmp)]);
	}
	cout<<ans<<'\n';
}