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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ii a[2222];

struct fraction
{
	ii x;
	fraction(ll _x,ll _y)
	{
		if(_y<0)
		{
			_x*=-1; _y*=-1;
		}
		x=mp(_x,_y);
	}
};

bool operator < (fraction a, fraction b)
{
	return (a.x.fi*b.x.se<a.x.se*b.x.fi);
}

bool operator <= (fraction a, fraction b)
{
	return (a.x.fi*b.x.se<=a.x.se*b.x.fi);
}
vector<pair<pair<fraction,fraction>,pair<int,int> > > pts;
vector<pair<fraction,pair<int,int> > > intersections;

struct line
{
	ll m, c; int id;
	line(ll _m=0, ll _c=0, int _id=0){m=_m; c=_c; id=_id;}
	/*
	ll get(fraction x)
	{
		return fraction(m*x.x.fi+c*x.x.se, x.x.se); //overflow in first expression :(
	}
	*/
};
line L[2222];
bool operator < (line a, line b)
{
	if(a.m!=b.m) return (a.m>b.m);
	else return a.c<b.c;
}

int pos[2222];

void out(int d, int b, int c)
{
	cout<<"Yes\n";
	cout<<a[d].fi<<' '<<a[d].se<<'\n';
	cout<<a[b].fi<<' '<<a[b].se<<'\n';
	cout<<a[c].fi<<' '<<a[c].se<<'\n';
	exit(0);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ll s; cin>>n>>s; s*=2;
	map<int,vi> ma;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].fi>>a[i].se;
		ma[a[i].fi].pb(i);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ll tmp = a[i].fi*a[j].se-a[i].se*a[j].fi;
			ll B = (a[j].fi-a[i].fi);
			ll A = a[i].se-a[j].se;
			for(ll k=-1;k<=1;k+=2)
			{
				ll C = k*s-tmp;
				if(B==0)
				{
					if(A==0)
					{
						if(C==0)
						{
							int k=0;
							while(k==i||k==j) k++;
							out(i,j,k);
						}
					}
					else
					{
						if(C%A==0)
						{
							for(auto x:ma[C/A])
							{
								if(x!=i&&x!=j) out(i,j,x);
							}
						}
					}
				}
				pts.pb(mp(mp(fraction(-A,B),fraction(C,B)),mp(i,j)));
			}
		}
	}
	sort(pts.begin(),pts.end()); //dont care about overflow on coordinate 2
	for(int i=0;i<n;i++)
	{
		//Line : (-x,y)
		L[i] = line(-a[i].fi,a[i].se,i);
	}
	sort(L,L+n);
	vi order;
	for(int i=0;i<n;i++) {pos[i]=i;order.pb(i);}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(L[i].m!=L[j].m) intersections.pb(mp(fraction(L[j].c-L[i].c,L[i].m-L[j].m),mp(i,j)));
			else
			{
				//cerr<<"NO INTERSECT "<<i<<' '<<j<<'\n';
			}
		}
	}
	sort(intersections.begin(),intersections.end());
	/*
	for(int i=0;i<intersections.size();i++)
	{
		cerr<<intersections[i].fi.x.fi<<' '<<intersections[i].fi.x.se<<' '<<intersections[i].se.fi<<' '<<intersections[i].se.se<<'\n';
	}
	*/
	int ptr=0;
	for(int i=0;i<pts.size();i++)
	{
		fraction A = pts[i].fi.fi; fraction B = pts[i].fi.se; int labx = pts[i].se.fi; int laby = pts[i].se.se;
		//cerr<<"A : "<<A.x.fi<<' '<<A.x.se<<'\n';
		while(ptr<intersections.size()&&intersections[ptr].fi<A)
		{
			int lx = intersections[ptr].se.fi; int ly = intersections[ptr].se.se;
			//cerr<<"SWAP "<<pos[lx]<<' '<<pos[ly]<<' '<<lx<<' '<<ly<<'\n';
			assert(abs(pos[lx]-pos[ly])==1);
			swap(order[pos[lx]], order[pos[ly]]); swap(pos[lx],pos[ly]);
			ptr++;
		}
		int lo = 0; int hi = n - 1;
		if(i<1000)
		{
			for(int i=1;i<n;i++)
			{
				//cerr<<"ORDER : "<<L[order[i]].m<<' '<<L[order[i]].c<<' '<<L[order[i-1]].m<<' '<<L[order[i-1]].c<<'\n';
				assert(A.x.fi*L[order[i]].m+L[order[i]].c*A.x.se>=A.x.fi*L[order[i-1]].m+L[order[i-1]].c*A.x.se);
			}
		}
		while(lo<=hi)
		{
			int mid=(lo+hi)>>1;
			ll m = L[order[mid]].m; ll c = L[order[mid]].c;
			assert(A.x.se==B.x.se);
			ll F1 = A.x.fi*m+A.x.se*c;
			ll F2 = B.x.fi;
			if(F1==F2)
			{
				out(labx,laby,L[order[mid]].id);
				return 0;
			}
			else if((A.x.se>0&&F1>F2)||(A.x.se<0&&F1<F2))
			{
				hi=mid-1;
			}
			else
			{
				lo=mid+1;
			}
		}
	}
	cout<<"No\n";
}