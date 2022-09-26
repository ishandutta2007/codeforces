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
  
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi a[1511];
vi b[1511];
vi ha[1511];
vi hb[1511];

int MOD[3] = {int(1e9)+7, int(1e9)+9, 1000001887};
int C[3];

int rnd(int l, int r)
{
	return uniform_int_distribution<int>(l,r)(rng);
}

int add(int a, int b, int mod)
{
	a+=b;
	while(a>=mod) a-=mod;
	return a;
}

int mult(int a, int b, int mod)
{
	return (a*1LL*b)%mod;
}

vi hsh(vi &v)
{
	vi coeff = {1,1,1};
	vi cur = {0,0,0};
	
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<3;j++)
		{
			cur[j] = add(cur[j],mult(v[i]+1,coeff[j],MOD[j]),MOD[j]);
			coeff[j]=mult(coeff[j],C[j],MOD[j]);
		}
	}
	return cur;
}

int realid[1511];
vi ans;
int n,m; 
vi sortings[1511];

vi compute(int col)
{
	vi f(n-1,0); //1 is when it's good, -1 is bad
	for(int i=0;i<n-1;i++)
	{
		if(b[i][col]>b[i+1][col])
		{
			f[i]=-1;
		}
		else if(b[i][col]<b[i+1][col])
		{
			f[i]=1;
		}
	}
	return f;
}

int cnt[1511][2];

void deactivate(int i)
{
	for(int col=0;col<m;col++)
	{
		if(sortings[col][i]==1) cnt[col][1]--;
		if(sortings[col][i]==-1) cnt[col][0]--;
	}
}

bool used[1511];
int nice[1511];
int pos[1511];


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<3;i++) C[i]=rnd(int(1e5),int(1e6));
	for(int i=0;i<n;i++)
	{
		vi vec(m);
		for(int j=0;j<m;j++)
		{
			cin>>vec[j];
		}
		a[i]=vec;
		ha[i] = hsh(vec);
	}
	for(int i=0;i<n;i++)
	{
		vi vec(m);
		for(int j=0;j<m;j++)
		{
			cin>>vec[j];
		}
		b[i]=vec;
		hb[i] = hsh(vec);
	}
	map<vi,vi> ma;
	for(int i=0;i<n;i++)
	{
		ma[hb[i]].pb(i);
	}
	for(int i=n-1;i>=0;i--)
	{
		if(ma[ha[i]].empty())
		{
			cout<<-1<<'\n'; return 0;
		}
		realid[i] = ma[ha[i]].back();
		ma[ha[i]].pop_back();
	}
	
	//characterize column sorts
	for(int i=0;i<m;i++)
	{
		sortings[i] = compute(i);
	}
	
	for(int col=0;col<m;col++)
	{
		for(int i=0;i<n-1;i++)
		{
			if(sortings[col][i]==1) cnt[col][1]++;
			if(sortings[col][i]==-1) cnt[col][0]++;
		}
	}
	/*
	for(int col=0;col<m;col++)
	{
		cerr<<"COL "<<col<<": ";
		for(int v:sortings[col]) cerr<<v<<' ';
		cerr<<'\n';
	}
	*/
	//do greedy sortings
	for(int z=0;z<n;z++)
	{
		int pos=-1;
		for(int i=0;i<m;i++)
		{
			if(used[i]) continue;
			if(cnt[i][0]==0)
			{
				pos=i; break;
			}
		}
		if(pos==-1) break;
		used[pos]=1;
		//sort by col pos
		ans.pb(pos+1);
		for(int i=0;i<n-1;i++)
		{
			if(nice[i]) continue;
			assert(sortings[pos][i]!=-1);
			if(sortings[pos][i]==1) 
			{
				nice[i]=1; deactivate(i);
			}
		}
	}
	
	//inverse of original
	for(int i=0;i<n;i++)
	{
		pos[realid[i]] = i;
	}
	
	//check
	for(int i=0;i<n-1;i++)
	{
		if(!nice[i])
		{
			//need pos[i] < pos[i+1] in the beginning
			if(pos[i]>pos[i+1])
			{
				cout<<-1<<'\n'; return 0;
			}
		}
	}
	
	reverse(ans.begin(),ans.end());
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i];
		if(i+1<ans.size()) cout<<' ';
	}
	cout<<'\n';
}