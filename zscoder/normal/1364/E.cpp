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

int a[2222];
int n;
const bool DEBUG=0;
int queries=0;
int hidden[2222];
map<ii,int> ma;

int query(int l, int r)
{
	if(l>r) swap(l,r);
	assert(l!=r);
	if(ma.count({l,r})) return ma[{l,r}];
	queries++;
	if(!DEBUG)
	{
		cout<<"? "<<l+1<<' '<<r+1<<'\n';
		fflush(stdout);
		int x; cin>>x;
		if(x==-1) exit(0);
		ma[{l,r}]=x;
		return x;
	}
	else
	{
		return (ma[{l,r}]=hidden[l]|hidden[r]);
	}
}

void out()
{
	if(DEBUG)
	{
		for(int i=0;i<n;i++)
		{
			assert(hidden[i]==a[i]);
		}
		return ;
	}
	cout<<"! ";
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
	fflush(stdout);
}

int ban[2222];

int solve(vi vec, int bit)
{
	int vsiz=vec.size();
	int bitcount = __builtin_popcount(bit);
	/*
	cerr<<"SOLVE\n";
	for(int v:vec) cerr<<v<<' ';
	cerr<<'\n';
	cerr<<"BIT = "<<bit<<'\n';
	*/
	if(bitcount==1)
	{
		for(int v:vec)
		{
			if(!ban[v]) return v;
		}
		assert(0);
	}
	int halfsiz = (bitcount+1)/2; //adjust later
	int a=0; int b=1;
	while(__builtin_popcount(query(vec[a],vec[b]))>halfsiz)
	{
		a=rand()%vsiz;
		b=rand()%vsiz;
		while(b==a) b=rand()%vsiz;
	}
	//ok use i to screw everything
	vi res; int valuea = int(1e9);
	for(int i=0;i<vsiz;i++)
	{
		if(i==a) continue;
		valuea=min(valuea,query(vec[i],vec[a]));
		res.pb(query(vec[i],vec[a]));
		//cerr<<vec[a]<<' '<<vec[i]<<' '<<res.back()<<'\n';
	}
	sort(res.begin(),res.end());
	vi posvalue;
	for(int i=1;i<n;i++)
	{
		if((i&bit)==i) posvalue.pb(i);
	}
	assert(posvalue.size()==res.size());
	if(posvalue==res) return vec[a];
	ban[vec[a]]=1;
	vi nw; nw.pb(vec[a]);
	for(int x:vec)
	{
		if(x==vec[a]) continue;
		if(query(x,vec[a])==valuea)
		{
			nw.pb(x);
		}
	}
	return solve(nw,valuea);
	
}
 
int main()
{
	srand(123);
	for(int cc=1;;cc++)
	{
		ma.clear(); memset(ban,0,sizeof(ban)); queries=0;
		if(!DEBUG)
		{
			cin>>n;
		}
		else 
		{
			n=2048;
			vi h;
			for(int i=0;i<n;i++) h.pb(i);
			random_shuffle(h.begin(),h.end());
			for(int i=0;i<n;i++) hidden[i]=h[i];
			//for(int v:h) cout<<v<<' ';
			//cout<<endl;
		}
		vi vec(n);
		int bit=1;
		while(bit<n-1) bit=bit*2+1;
		for(int i=0;i<n;i++) vec[i]=i;
		random_shuffle(vec.begin(),vec.end());
		int zro = solve(vec,bit);
		a[zro]=0;
		cerr<<"ZERO = "<<zro<<'\n';
		for(int i=0;i<n;i++)
		{
			if(i==zro) continue;
			a[i]=query(zro,i);
		}
		out();
		if(!DEBUG) return 0;
		cerr<<"Queries:"<<' '<<queries<<'\n';
		assert(queries<=4269);
		cerr<<"Case #"<<cc<<" complete"<<'\n';
	}
}