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

const int MOD = 998244353;
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
void radd(int &a, int b)
{
	a=add(a,b); 
}

const int LG = 31;

int minbit(int x)
{
	if(x==0) return int(1e9);
	x=abs(x);
	for(int i=0;i<LG;i++)
	{
		if(x&(1<<i))
		{
			return i;
		}
	}
	assert(0);
}

bool cmp(const ii &a, const ii &b)
{
	return (min(minbit(a.fi),minbit(a.se))>min(minbit(b.fi),minbit(b.se)));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	m*=2;
	vector<ii> vec;
	for(int i=0;i<n;i++)
	{
		int x,y; cin>>x>>y;
		ll cx=x; ll cy=y;
		while(max(abs(cx),abs(cy))<=m)
		{
			vec.pb({cx,cy});
			cx<<=1; cy<<=1;
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	map<vi,int> old_dp; //state = {sum_x, sum_y, sum_abs_x, sum_abs_y} (sum_abs is -1 if I don't care about the prefix anymore)
	old_dp[{0,0,0,0}]=1;
	for(int z=0;z<vec.size();z++)
	{
		int x=vec[z].fi; int y=vec[z].se;
		ll sumabsx = 0; ll sumabsy=0;
		for(int z2=z+1;z2<vec.size();z2++)
		{
			sumabsx+=abs(vec[z2].fi);
			sumabsy+=abs(vec[z2].se);
		}
		map<vi,int> new_dp;
		for(auto X:old_dp)
		{
			vi state = X.fi; int val = X.se;
			if(val==0) continue;
			if(abs(state[0])<=sumabsx&&abs(state[1])<=sumabsy) 
			{
				ii tmp = {state[2],state[3]};
				if(state[2]!=-1&&state[2]+sumabsx<=m) state[2]=-1;
				if(state[3]!=-1&&state[3]+sumabsy<=m) state[3]=-1;
				radd(new_dp[state],val); //don't take (x,y)
				state[2]=tmp.fi; state[3]=tmp.se;
			}
			//take (x,y)
			ll nwx=state[0]+1LL*x;
			ll nwy=state[1]+1LL*y;
			if(abs(nwx)>sumabsx||abs(nwy)>sumabsy) continue;
			state[0]+=x; state[1]+=y;
			if(state[2]!=-1) 
			{
				ll tmp = state[2]+1LL*abs(x);
				if(tmp>m) continue;
				state[2]+=abs(x);
				if(state[2]+sumabsx<=m) state[2]=-1;
			}
			if(state[3]!=-1)
			{
				ll tmp = state[3]+1LL*abs(y);
				if(tmp>m) continue;
				state[3]+=abs(y);
				if(state[3]+sumabsy<=m) state[3]=-1;
			}
			radd(new_dp[state],val);
		}
		old_dp = new_dp;
	}
	//answer minus 1 because empty polygon
	int ans=MOD-1;
	for(auto X:old_dp)
	{
		if(X.fi[0]==0&&X.fi[1]==0) radd(ans,X.se);
	}
	cout<<ans<<'\n';
}