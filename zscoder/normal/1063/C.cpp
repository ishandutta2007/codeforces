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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n;
const int INF = int(1e9);
const bool DEBUG=0;

bool out(int x, int y=0)
{
	cout<<x<<' '<<y<<'\n';
	fflush(stdout);
	string s; 
	if(!DEBUG) cin>>s;
	else 
	{
		if(x==0&&y==0) s="white";
		else s="black";
		//s=(rand()&1?"white":"black");
	}
	return (s[0]=='b');
}

void answer(int x, int mode)
{
	if(mode==0) cout<<x<<' '<<11<<' '<<x<<' '<<1<<'\n';
	else cout<<0<<' '<<INF-1<<' '<<x<<' '<<0<<'\n';
	fflush(stdout);
}
int main()
{
	for(int cc=1;cc<2;cc++){
		if(!DEBUG) cin>>n;
		else n=30;
		int l = 0; int r = int(1e9);
		int mode=0;
		int plan=0;
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				mode=out(l);
			}
			else if(i==n-1)
			{
				int tmp = out(0,INF);
				if(tmp!=mode){plan=1;}
			}
			else
			{
				int m = (l+r)>>1;
				int tmp = out(m);
				if(mode^tmp)
				{
					r=m;
				}
				else
				{
					l=m;
				}
			}
		}
		assert(l<r);
		answer(l+1,plan);
		if(DEBUG)
		{
			cerr<<"Case #"<<cc<<" complete\n";
		}
		else break;
	}
}