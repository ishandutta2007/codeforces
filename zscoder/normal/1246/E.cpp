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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef bitset<2111> b100;

int a[22];
int n,k;
b100 dp[(1<<16)+10];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	dp[0].set(0,1);
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=2000;j>=1;j--)
		{
			if(j%k==0&&dp[i][j])
			{
				dp[i].set(j/k,1);
			}
		}
		for(int j=0;j<n;j++)
		{
			if(!(i&(1<<j)))
			{
				dp[i^(1<<j)]|=(dp[i]<<a[j]);
			}
		}
		/*
		cerr<<setw(2)<<i<<' ';
		for(int j=0;j<50;j++) cerr<<dp[i][j];
		cerr<<'\n';
		*/
	}
	if(dp[(1<<n)-1][1])
	{
		cout<<"YES\n";
		int curs=(1<<n)-1;
		vi powers(n+2,0);
		int pw=18;
		int cursum=1;
		while(curs)
		{
			while(cursum*k<=2000&&dp[curs][cursum*k]) 
			{
				cursum*=k; pw--;
			}
			for(int j=0;j<n;j++)
			{
				if(curs&(1<<j))
				{
					if(cursum>=a[j]&&dp[curs^(1<<j)][cursum-a[j]])
					{
						powers[j]=pw;
						cursum-=a[j];
						curs^=(1<<j); break;
					}
				}
			}
		}
		vi V[40]={};
		for(int i=0;i<n;i++)
		{
			V[powers[i]].pb(a[i]);
		}
		vector<ii> vec;
		int curp=0;
		while(curp<=35)
		{
			if(V[curp].empty()) {curp++; continue;}
			if(V[curp].size()==1) break;
			int u=V[curp].back();
			V[curp].pop_back();
			int v=V[curp].back();
			V[curp].pop_back();
			vec.pb({u,v});
			int s=u+v;
			int newp=curp;
			while(s%k==0)
			{
				newp++;
				s/=k;
			}
			V[newp].pb(s);
		}
		for(auto x:vec)
		{
			cout<<x.fi<<' '<<x.se<<'\n';
		}
		return 0;
	}
	cout<<"NO\n";
}