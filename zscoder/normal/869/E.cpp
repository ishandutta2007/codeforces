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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

set<ii> st[2][11111];

void update(int ty, int id, int l, int r, int ql, int qr, ii seg, bool ins) //ins = 1 if insert
{
	if(l>=qr||ql>=r) return ;
	if(ql<=l&&r<=qr)
	{
		////cerr<<ty<<' '<<id<<' '<<seg.fi<<' '<<seg.se<<'\n';
		if(ins) st[ty][id].insert(seg);
		else st[ty][id].erase(seg);
		return ;
	}
	int mid=(l+r)>>1;
	update(ty,id*2,l,mid,ql,qr,seg,ins);
	update(ty,id*2+1,mid,r,ql,qr,seg,ins);
}

ii query(int ty, int id, int l, int r, int pos, int v)
{
	if(pos>=r||pos<l) return mp(-1,1000000);
	ii inte = mp(-1,1000000);
	if(st[ty][id].empty()) inte=mp(-1,1000000);
	else
	{
		auto it = st[ty][id].lower_bound(mp(v+1,-1));
		while(it!=st[ty][id].begin())
		{
			it--;
			if(it->fi<=v&&it->se>=v)
			{
				////cerr<<"HADICAP : "<<it->fi<<' '<<it->se<<'\n';
				inte =(*it);
				break;
			}
		}
	}
	if(r-l<2) return inte;
	int mid=(l+r)>>1;
	ii t1 = query(ty,id*2,l,mid,pos,v);
	ii t2=query(ty,id*2+1,mid,r,pos,v);
	if(t1.fi>=0&&t1.fi>=inte.fi) inte=t1;
	if(t2.fi>=0&&t2.fi>=inte.fi) inte=t2;
	return inte;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	int q; cin>>q;
	for(int i=0;i<q;i++)
	{
		int t; cin>>t;
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		x1--;y1--;x2--;y2--;
		if(t==1)
		{
			update(0,1,0,n,x1,x2+1,mp(y1,y2),1);
			update(1,1,0,m,y1,y2+1,mp(x1,x2),1);
		}
		else if(t==2)
		{
			update(0,1,0,n,x1,x2+1,mp(y1,y2),0);
			update(1,1,0,m,y1,y2+1,mp(x1,x2),0);
		}
		else
		{
			ii tmp1 = query(0,1,0,n,x1,y1);
			ii tmp2 = query(1,1,0,m,y1,x1);
			ii t1 = query(0,1,0,n,x2,y2);
			ii t2 = query(1,1,0,m,y2,x2);
			//cerr<<"BLOCK 1 : "<<tmp1.fi<<' '<<tmp1.se<<' '<<tmp2.fi<<' '<<tmp2.se<<'\n';
			//cerr<<"BLOCK 2 : "<<t1.fi<<' '<<t1.se<<' '<<t2.fi<<' '<<t2.se<<'\n';
			//ii best=mp(max(tmp1.fi,t1.fi),min(tmp1.se,t2.se));
			//ii best2=mp(max(tmp2.fi,t2.fi),min(tmp2.se,t2.se	));
			//if(y1>=best.fi&&y1<=best.se&&y2>=best.fi&&y2<=best.se&&x1>=best2.fi&&x1<=best2.se&&x2>=best2.fi&&x2<=best2.se)
			if(tmp1==t1&&tmp2==t2)
			{
				cout<<"Yes\n";
			}
			else cout<<"No\n";
		}
	}
}