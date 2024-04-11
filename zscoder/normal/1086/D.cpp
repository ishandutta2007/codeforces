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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

string s;
int a[222222];
map<char,int> ma;

pbds pos[3];
int n,q; 
const int INF = int(1e8);

int getval(int id, int l, int r)
{
	return (pos[id].order_of_key(r+1)-pos[id].order_of_key(l));
}

int solve()
{
	int ans=0;
	for(int c=0;c<3;c++)
	{
		int w=(c+1)%3; int l=(c+2)%3;
		vector<ii> V;
		{
			int id=INF;
			if(!pos[w].empty()) id=(*pos[w].begin());
			int id2=INF-1;
			if(!pos[l].empty()) id2=(*pos[l].begin());
			//cerr<<c<<' '<<id<<' '<<id2<<'\n';
			if(id<INF&&id<=id2) V.pb(mp(id,id2));
		}
		{
			int id=INF-1;
			if(!pos[w].empty()) id=(*prev(pos[w].end()));
			int id2=-INF;
			if(!pos[l].empty()) id2=(*prev(pos[l].end()));
			//cerr<<c<<' '<<id2<<' '<<id<<'\n';
			if(id<INF-1&&id2<=id) V.pb(mp(id2,id));
		}
		if(V.empty()) continue;
		if(V.size()==1)
		{
			ans += getval(c,V[0].fi,V[0].se);
			continue;
		}
		sort(V.begin(),V.end());
		if(V[1].fi<=V[0].se)
		{
			ans+=getval(c,V[0].fi,max(V[0].se,V[1].se));
		}
		else
		{
			ans+=getval(c,V[0].fi,V[0].se);
			ans+=getval(c,V[1].fi,V[1].se);
		}
	}
	return n-ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>q;
	cin>>s;
	ma['R']=2; ma['S']=1; ma['P']=0;
	for(int i=0;i<n;i++)
	{
		a[i]=ma[s[i]]; pos[a[i]].insert(i);
	}
	cout<<solve()<<'\n';
	for(int z=0;z<q;z++)
	{
		int p; char c; cin>>p>>c; p--;
		pos[a[p]].erase(p); pos[ma[c]].insert(p);
		a[p]=ma[c];
		cout<<solve()<<'\n';
	}
}