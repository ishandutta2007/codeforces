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

int a[31];
bool dp[101][3001][32];
int par[101][3001][32];
bool tour[101][101];
int d[101];
int N[101];
int d2[101];

void solve(vi &s)
{
	int n = s.size();
	/*
	for(int i=0;i<n;i++)
	{
		cerr<<s[i]<<' ';
	}
	cerr<<endl;
	*/
	cout<<n<<'\n';
	for(int i=0;i<n;i++)
	{
		d[i]=s[i]-i;
	}
	while(1)
	{
		memset(N,0,sizeof(N));
		int jj=-1;
		for(int i=0;i<n;i++)
		{
			if(d[i]>0&&jj<0)
			{
				jj=i;
			}
		}
		vector<ii> seg;
		for(int i=0;i<n;i++)
		{
			d2[i]=d[i];
		}
		int l=0;
		for(int i=1;i<n;i++)
		{
			if(d[i]<=d[i-1])
			{
				continue;
			}
			else
			{
				seg.pb(mp(l,i-1));
				l=i;
			}
		}
		seg.pb(mp(l,n-1));
		for(int i=0;i<seg.size();i++)
		{
			int L=seg[i].fi; int R=seg[i].se;
			for(int j=L;j<=R;j++)
			{
				if(d[j]<0)
				{
					N[i]++;
				}
			}
		}
		if(jj!=-1)
		{
			int q = -1;
			int sum=0;
			for(int i=0;i<seg.size();i++)
			{
				sum+=N[i];
				if(sum>=d[jj])
				{
					q=i;
					break;
				}
			}
			for(int i=0;i<q;i++)
			{
				int L=seg[i].fi; int R=seg[i].se;
				for(int j=L;j<=R;j++)
				{
					if(d[j]<0)
					{
						d2[j]=d[j]+1;
						tour[jj][j]=1;
					}
				}
			}
			int sigma=d[jj];
			for(int i=0;i<q;i++)
			{
				sigma-=N[i];
			}
			//cerr<<q<<' '<<sigma<<'\n';
			vector<ii> v;
			for(int j=seg[q].fi;j<=seg[q].se;j++)
			{
				v.pb(mp(d[j],j));
			}
			sort(v.begin(),v.end());
			for(int j=0;j<sigma;j++)
			{
				int pt=v[j].se;
				d2[pt]=d[pt]+1;
				tour[jj][pt]=1;
			}
			d2[jj]=0;
		}
		else
		{
			break;
		}
		bool all0=1;
		for(int i=0;i<n;i++)
		{
			d[i]=d2[i];
			//cerr<<d[i]<<' ';
			if(d[i]!=0) all0=0;
		}
		//cerr<<'\n';
		if(all0) break;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(!tour[i][j]) tour[j][i]=1;
		}
	}
	vi cnt;
	for(int i=0;i<n;i++)
	{
		int c=0;
		assert(tour[i][i]==0);
		for(int j=0;j<n;j++)
		{
			c+=tour[i][j];
			if(i!=j)
			{
				assert(tour[i][j]^tour[j][i]);
			}
		}
		cnt.pb(c);
	}
	sort(cnt.begin(),cnt.end());
	for(int i=0;i<n;i++) assert(cnt[i]==s[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(tour[i][j]) cout<<1;
			else cout<<0;
		}
		cout<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	dp[1][a[0]][0]=1;
	par[1][a[0]][0]=-1;
	for(int i=1;i<=99;i++)
	{
		int cap=(i*(i+1))/2;
		for(int j=0;j<=3000;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(dp[i][j][k])
				{
					//use a[k]?
					if(j+a[k]>=cap&&j+a[k]<=3000)
					{
						dp[i+1][j+a[k]][k]=1;
						par[i+1][j+a[k]][k]=k;
					}
					//use a[k+1]?
					if(k+1<n&&j+a[k+1]>=cap&&j+a[k+1]<=3000)
					{
						dp[i+1][j+a[k+1]][k+1]=1;
						par[i+1][j+a[k+1]][k+1]=k;
					}
				}
			}
		}
	}
	for(int i=1;i<=99;i++)
	{
		if(dp[i][(i*(i-1))/2][n-1])
		{
			vi vec;
			int j2 = i*(i-1)/2; int k2=n-1;
			for(int i2=i;i2>=1;i2--)
			{
				assert(dp[i2][j2][k2]);
				//cerr<<i2<<' '<<j2<<' '<<k2<<'\n';
				vec.pb(a[k2]);
				if(i2>1)
				{
					int p=par[i2][j2][k2];
					j2-=a[k2];
					k2=p;
				}
			}
			reverse(vec.begin(),vec.end());
			solve(vec);
			return 0;
		}
	}
	cout<<"=(";
}