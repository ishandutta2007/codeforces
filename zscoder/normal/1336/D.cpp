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

const bool DEBUG = 0;
map<int,int> ma;
map<int,int> magic; //a[i-2]a[i-1]
map<int,int> incre;
int n;
map<int,int> secret;
int query_cnt=0;
map<int,int> inverse;
vector<int> move_history;
vector<ii> query_history;
vector<ii> diff_history;

int nc3(int n)
{
	return (n*(n-1)*(n-2))/6;
}

ii calc()
{
	int a,b;
	a=0; b=0;
	for(int i=1;i<=n;i++)
	{
		a+=nc3(ma[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int prod=1;
		for(int j=2;j>=0;j--) prod*=ma[i-j];//*(incre[i-j+1]+secret[i-j+1])*(incre[i-j+2]+secret[i-j+2]);
		b+=prod;
	}
	return {a,b};
}

ii query(int x)
{
	assert(x>=1&&x<=n);
	move_history.pb(x);	
	if(!DEBUG)
	{
		cout<<"+ "<<x<<'\n'; fflush(stdout);
	}
	incre[x]++;	
	int a,b; 
	if(!DEBUG)
	{
		cin>>a>>b;
	}
	else
	{
		a=0; b=0;
		for(int i=1;i<=n;i++)
		{
			a+=nc3(incre[i]+secret[i]);
		}
		for(int i=1;i<=n;i++)
		{
			int prod=1;
			for(int j=2;j>=0;j--) prod*=(incre[i-j]+secret[i-j]);//*(incre[i-j+1]+secret[i-j+1])*(incre[i-j+2]+secret[i-j+2]);
			b+=prod;
		}
	}
	query_cnt++;
	int add_a = a-query_history.back().fi;
	int add_b = b-query_history.back().se;
	diff_history.pb({add_a,add_b});
	query_history.pb({a,b});
	magic[x]=add_b;
	return {a,b};
}

void out()
{
	if(!DEBUG)
	{
		cout<<"! ";
		for(int i=1;i<=n;i++)
		{
			cout<<ma[i]-incre[i];
			if(i+1<=n) cout<<' ';
		}
		cout<<'\n';
		fflush(stdout);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			////cerr<<ma[i]-incre[i]<<' '<<secret[i]<<'\n';
			assert(ma[i]-incre[i]==secret[i]);
		}
	}
}

void solve()
{
	ma.clear(); incre.clear(); magic.clear(); secret.clear(); inverse.clear(); query_cnt=0;
	move_history.clear(); query_history.clear();
	int cur_a=0; int cur_b=0;
	int ia=0; int ib=0;
	if(!DEBUG) 
	{
		cin>>n;
		cin>>cur_a>>cur_b;
	}
	else n=6;
	for(int i=1;i<=n+10;i++)
	{
		inverse[nc3(i+1)-nc3(i)]=i+1;
	}
	if(DEBUG)
	{
		for(int i=1;i<=n;i++)
		{
			secret[i]=rand()%(n+1);
		}
		cur_a=0; cur_b=0;
		for(int i=1;i<=n;i++)
		{
			cur_a+=nc3(incre[i]+secret[i]);
		}
		for(int i=1;i<=n;i++)
		{
			int prod=1;
			for(int j=2;j>=0;j--)
			{
				prod*=(incre[i-j]+secret[i-j]);//*(incre[i-j+1]+secret[i-j+1])*(incre[i-j+2]+secret[i-j+2]);
			}
			cur_b+=prod;
		}
	}
	//cerr<<cur_a<<' '<<cur_b<<'\n';
	ia=cur_a; ib=cur_b;
	query_history.pb({ia,ib}); diff_history=query_history;
	//1 2 3 1
	query(1);
	query(2);
	query(3);
	query(1);
	//cerr<<diff_history.size()<<'\n';
	ma[1] = inverse[diff_history[4].fi];
	if(diff_history[2].se==0) ma[3]=1;
	else ma[3]=inverse[diff_history[3].fi];
	//cerr<<diff_history[3].fi<<' '<<ma[3]<<'\n';
	ma[2]=diff_history[4].se/ma[3];
	for(int i=4;i<=n;i++)
	{
		int sum = magic[i-1]-(ma[i-3]-incre[i-3]+1)*(ma[i-2]-incre[i-2]+1);
		//cerr<<i<<' '<<magic[i-1]<<' '<<diff_history.size()<<'\n';
		assert(sum>=0);
		if(sum==0)
		{
			ma[i]=(i<n); //final value
		}
		else
		{
			if(i==n)
			{
				ma[i]=sum/(ma[i-2]-incre[i-2]+1);
			}
		}
		if(i<n) 
		{
			query(i);
			if(ma.find(i)==ma.end()) ma[i]=inverse[diff_history.back().fi];
		}
	}
	if(query_cnt>n)
	{
		if(DEBUG)
		{
			for(int i=1;i<=n;i++)
			{
				cout<<secret[i]<<' ';
			}
			cout<<'\n';
			exit(0);
		}
		else assert(0);
	}
	out();
}

int main()
{
	srand(time(NULL));
	for(int cc=1;;cc++)
	{
		solve();	
		if(!DEBUG) return 0;
		cerr<<"Case #"<<cc<<" complete\n";
	}
}