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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int C = 30;
set<string> a[210][C+1];
string pre[210];
string suf[210];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
		suf[i]=pre[i];
		for(int j = 0; j < pre[i].length(); j++)
		{
			string tmp;
			for(int k = j; k < pre[i].length(); k++)
			{
				tmp+=pre[i][k];
				if(k-j+1>=C) continue;
				a[i][k-j+1].insert(tmp);
			}
		}
		suf[i] = suf[i].substr(max(0,int(suf[i].length()) - C), min(int(suf[i].length()), C));
		pre[i] = pre[i].substr(0, min(int(pre[i].length()), C));
	}
	int m; cin>>m;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v;
		u--; v--;
		for(int j = 1; j < C; j++)
		{
			for(auto it = a[u][j].begin(); it != a[u][j].end(); it++)
			{
				a[i+n][j].insert((*it));
			}
			for(auto it = a[v][j].begin(); it != a[v][j].end(); it++)
			{
				a[i+n][j].insert((*it));
			}
		}
		for(int l = 1; l < C; l++)
		{
			for(int r = 1; l + r < C; r++)
			{
				if(suf[u].length()>=l&&pre[v].length()>=r)
				{
					string t1 = suf[u].substr(int(suf[u].length()) - l, l);
					string t2 = pre[v].substr(0, r);
					t1+=t2;
					//cerr<<"S : "<<t1<<'\n';
					a[i+n][l+r].insert(t1);
				}
			}
		}
		string SUF,PRE;
		PRE=pre[u];
		if(pre[u].length()<C) PRE+=pre[v];
		SUF=suf[v];
		if(suf[v].length()<C) SUF = suf[u]+suf[v];
		suf[i+n]=SUF; pre[i+n]=PRE;
		suf[i+n] = suf[i+n].substr(max(0,int(suf[i+n].length()) - C), min(int(suf[i+n].length()), C));
		pre[i+n] = pre[i+n].substr(0, min(int(pre[i+n].length()), C));
		//cerr<<i+n<<' '<<pre[i+n]<<' '<<suf[i+n]<<'\n';
		int ans = 0;
		for(int j=1;j<C;j++)
		{
			//if(j<5) cerr<<i<<' '<<j<<' '<<a[i+n][j].size()<<'\n';
			if(a[i+n][j].size()>=(1LL<<j))
			{
				ans=j;
			}
		}
		cout<<ans<<'\n';
	}
}