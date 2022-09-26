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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int bestbit;
int bestcnt;
int pow3[19];

void printvec(vi v)
{
	for(int x:v)
	{
		cerr<<x<<' ';
	}
	cerr<<endl;
}

void solve(vi v, int bit, int lvl, int cnt)
{
	if(lvl>=19) return ;
	//printvec(v);
	//cerr<<"B : "<<bit<<' '<<lvl<<' '<<cnt<<endl;
	if(v.size()==1&&v[0]==0)
	{
		if(cnt<bestcnt)
		{
			bestcnt=cnt;
			bestbit=bit;
		}
		return ;
	}
	vi odd; vi vnw;
	for(int x:v)
	{
		if(abs(x)&1)
		{
			odd.pb(x);
		}
		else
		{
			vnw.pb(x/2);
		}
	}
	if(odd.empty())
	{
		solve(vnw, bit, lvl+1, cnt);
		return ;
	}
	//cnt + 1
	//choose +2^lvl
	vi v2;
	for(int x:v)
	{
		if(abs(x)&1)
		{
			v2.pb((x-1)/2);
		}
	}
	vi NW(int(vnw.size())+int(v2.size()));
	merge(vnw.begin(),vnw.end(),v2.begin(),v2.end(),NW.begin());
	NW.erase(unique(NW.begin(),NW.end()),NW.end());
	solve(NW, bit+pow3[lvl], lvl+1, cnt+1);
	//choose -2^lvl
	for(int i=0;i<v2.size();i++)
	{
		v2[i]++;
	}
	NW.resize(int(vnw.size())+int(v2.size()));
	merge(vnw.begin(),vnw.end(),v2.begin(),v2.end(),NW.begin());
	NW.erase(unique(NW.begin(),NW.end()),NW.end());
	solve(NW, bit+(pow3[lvl]<<1), lvl+1, cnt+1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	pow3[0]=1;
	for(int i=1;i<19;i++) pow3[i]=pow3[i-1]*3;
	int n; cin>>n;
	vi vec;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; vec.pb(x);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	bestcnt=100;
	solve(vec, 0, 0, 0);
	vi ans;
	for(int i=0;i<18;i++)
	{
		if(bestbit%3==1)
		{
			ans.pb((1<<i));
		}
		else if(bestbit%3==2)
		{
			ans.pb(-(1<<i));
		}
		bestbit/=3;
	}
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i];
		if(i+1<ans.size()) cout<<' ';
	}
	cout<<'\n';
}