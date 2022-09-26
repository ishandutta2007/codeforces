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

ll x[111111];
bool available[5001];
const bool DEBUG=0;
const int MX=50;
const int MX2=10;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll N; int n; ll a, d; 
	for(int cc=1;;cc++)
	{
		if(DEBUG)
		{
			N=rand()%MX+1;
			n=rand()%MX2+1;
			a=rand()%MX+1;
			d=rand()%MX+1;
			for(int i=0;i<n;i++)
			{
				x[i]=rand()%MX+1;
			}
			sort(x,x+n);
		}
		else
		{
			cin>>N>>n>>a>>d;
			for(int i=0;i<n;i++)
			{
				cin>>x[i];
			}
		}
		ll res=0;
		if(DEBUG)
		{
			memset(available,0,sizeof(available));
			for(int i=1;i<=5001;i++)
			{
				for(int j=1;j<=N;j++)
				{
					available[j*a] = 1;
				}
			}
			for(int i=0;i<n;i++) available[x[i]]=1;
			for(int i=1;i<=5001;)
			{
				if(available[i])
				{
					res++;
					i+=d+1;
					continue;
				}
				i++;
			}
			cerr<<"NAIVE : "<<res<<'\n';
		}
		n++; x[n-1] = ll(9e18);
		ll opentime = -ll(2e18);
		ll ans = 0;
		ll eachtime = d/a + 1;
		for(int i=0;i<n;i++)
		{
			ll X = x[i];
			ll closetime = opentime+d;
			ll nexta = max(0LL, closetime)/a + 1;
			ll k = max(0LL, min((N - nexta)/eachtime, ((X/a)-nexta)/eachtime));
			//cerr<<i<<' '<<X<<' '<<N<<' '<<X/a<<' '<<nexta<<' '<<eachtime<<' '<<k<<'\n';
			if(nexta<=N&&nexta*a<=X)
			{
				ans+=k+1;
				opentime = (nexta+k*eachtime)*a;
			}
			closetime = opentime + d;
			//cerr<<i<<' '<<ans<<' '<<opentime<<' '<<X<<'\n';
			if(X<=closetime)
			{
				continue;
			}
			opentime = X;
			ans++;
		}	
		ans--;
		if(DEBUG) cerr<<"FAST : "<<ans<<'\n';
		else cout<<ans<<'\n';
		if(DEBUG)
		{
			if(res!=ans)
			{
				freopen("automatic-door.txt","w",stdout);
				cout<<N<<' '<<n-1<<' '<<a<<' '<<d<<'\n';
				for(int i=0;i<n-1;i++)
				{
					cout<<x[i]<<' ';
				}
				cout<<'\n';
				return 0;
			}
			cerr<<"Case "<<cc<<" complete\n";
		}
		else return 0;
	}
}