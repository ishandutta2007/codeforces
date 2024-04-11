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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

struct node
{
	int sum;
	int ans;
	node(int _sum=0, int _ans=-int(1e9)): sum(_sum), ans(_ans){};
};

node st[430000*4];

void combine(int id)
{
	st[id].sum=st[id*2].sum+st[id*2+1].sum;
	st[id].ans=max(st[id*2+1].ans,st[id*2].ans+st[id*2+1].sum);
}

void update(int id, int l, int r, int pos, int v)
{
	if(pos>=r||pos<l) return ;
	if(r-l<2)
	{
		st[id].sum+=v;
		if(st[id].sum==0) st[id].ans=-int(1e9);
		else st[id].ans=st[id].sum+l;
		return ;
	}
	int mid=(l+r)>>1;
	update(id*2,l,mid,pos,v); update(id*2+1,mid,r,pos,v);
	combine(id);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,m; cin>>n>>k>>m;
	set<ii> S;
	for(int i=0;i<m;i++)
	{
		int x,y; cin>>x>>y;
		int val = abs(x-k)+y;
		if(S.find({x,y})==S.end())
		{
			update(1,0,410000,val,1);
			S.insert({x,y});
		}
		else
		{
			update(1,0,410000,val,-1);
			S.erase({x,y});
		}
		//cerr<<"F: "<<val<<' '<<st[1].ans<<'\n';
		cout<<max(0,(st[1].ans-1)-n)<<'\n';
	}
}