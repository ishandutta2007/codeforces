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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int V[2222];
int a[2222];
int L[2222];
int n,s,m,k; 
int dp[1666][1666][2];
int cnt[2222];
int par[2222];
int MX[1666][1666];
int get(int l, int r)
{
	if(l==0) return cnt[r];
	else return cnt[r]-cnt[l-1];
}

int solve(int mid)
{
	for(int i=0;i<n;i++)
	{
		a[i]=(V[i]<=mid);
		cnt[i]=a[i];
		if(i>0) cnt[i]+=cnt[i-1];
	}
	/*
	cerr<<"MID : "<<mid<<'\n';
	for(int i=0;i<n;i++)
	{
		cerr<<a[i]<<' ';
	}
	cerr<<'\n';
	*/
	for(int i=0;i<n;i++)
	{
		dp[i][0][0]=dp[i][0][1]=MX[i][0]=0;
		for(int j=1;j<=m;j++)
		{
			dp[i][j][0]=dp[i][j][1]=-int(1e9);
			MX[i][j]=-int(1e9);
		}
	}
	for(int i=0;i<n;i++)
	{
		par[i]=-1;
		if(L[i]>=n) continue;
		int mn = int(1e9);
		for(int j=i-1;j>=L[i];j--)
		{
			if(L[j]<n&&L[j]<mn)
			{
				mn=L[j]; par[i]=j;
			}
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		//if(L[i]>=n) continue;
		for(int j=1;j<=m;j++)
		{
			for(int z=0;z<2;z++)
			{
				if(L[i]<n)
				{
					dp[i][j][z]=max(dp[i][j][z],dp[i][j-1][z]);
					if(!z)
					{
						if(L[i]==0) dp[i][j][z] = max(dp[i][j][z], get(L[i], i));
						else dp[i][j][z] = max(dp[i][j][z], MX[L[i]-1][j-1] + get(L[i], i));
					}
					else
					{
						if(par[i]>=0&&j>0)
						{
							dp[i][j][z] = max(dp[i][j][z], max(dp[par[i]][j-1][0],dp[par[i]][j-1][1])+get(par[i]+1,i));
						}
					}
				}
				//cerr<<i<<' '<<j<<' '<<z<<' '<<dp[i][j][z]<<'\n';
				ans = max(ans, dp[i][j][z]);
				MX[i][j] = max(MX[i][j], max((i>0?MX[i-1][j]:-int(1e9)), dp[i][j][z]));
			}
		}
	}
	return ans;
}

int brute()
{
	vector<ii> seg;
	for(int i=0;i<n;i++)
	{
		if(L[i]<n) seg.pb(mp(L[i],i));
	}
	int z=seg.size();
	int ans=int(1e9)+11;
	for(int i=0;i<(1<<z);i++)
	{
		vector<bool> vec(z,0);
		if(__builtin_popcount(i)>m) continue;
		//cerr<<"I : "<<i<<'\n';
		for(int j=0;j<z;j++)
		{
			if(i&(1<<j))
			{
				for(int x=seg[j].fi;x<=seg[j].se;x++) vec[x]=1;
			}
		}
		vi VV;
		for(int i=0;i<n;i++)
		{
			if(vec[i]) VV.pb(V[i]);
		}
		sort(VV.begin(),VV.end());
		if(VV.size()>=k) ans=min(ans,VV[k-1]);
	}
	if(ans>int(1e9)) ans=-1;
	return ans;
}

const bool DEBUG=0;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);	
	for(int cc=1;;cc++)
	{
		if(!DEBUG){cin>>n>>s>>m>>k;}
		else
		{
			n=rand()%10+1; s=rand()%10+1; m=rand()%s+1; k=rand()%n+1;
		}
		vi v;
		for(int i=0;i<n;i++) {L[i] = n+1; if(DEBUG){V[i]=rand()+1;} else{cin>>V[i];} v.pb(V[i]);}
		vector<ii> VV;
		for(int i=0;i<s;i++)
		{
			int l,r; 
			if(!DEBUG) cin>>l>>r; 
			else
			{
				l=rand()%n+1; r=rand()%n+1;
				if(l>r) swap(l,r);
			}
			VV.pb(mp(l,r)); l--; r--; 
			L[r] = min(L[r], l);
		}
		int br = 0;
		if(DEBUG) br = brute();
		sort(v.begin(),v.end());
		int ans=-1;
		int lo=0; int hi=n-1;
		while(lo<=hi)
		{
			ll mid=(lo+hi)>>1;
			if(solve(v[mid])<k)
			{
				lo=mid+1;
			}
			else 
			{
				ans=mid; hi=mid-1;
			}
		}
		int res=0;
		if(ans==-1){res=-1;}
		else res=v[ans];
		if(!DEBUG)
		{
			if(ans==-1){cout<<-1<<'\n'; return 0;}
			cout<<v[ans]<<'\n';
			return 0;
		}
		else
		{
			cerr<<"BRUTE : "<<br<<'\n';
			cerr<<"ANS : "<<res<<'\n';
			if(br!=res)
			{
				freopen("segments.txt","w",stdout);
				cout<<n<<' '<<s<<' '<<m<<' '<<k<<'\n';
				for(int i=0;i<n;i++) cout<<V[i]<<' ';
				cout<<'\n';
				for(int i=0;i<s;i++)
				{
					cout<<VV[i].fi<<' '<<VV[i].se<<'\n';
				}
				return 0;
			}
		}
		cerr<<"Case "<<cc<<" complete\n";
	}
}