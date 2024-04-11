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

ll naive(ll n, ll m, ll s, ll t)
{
	ll cur = s;
	while(t>0)
	{
		if(cur%n>=m)
		{
			cur-=t;
		}
		else
		{
			cur+=t;
		}
		cur%=n;
		if(cur<0) cur+=n;
		t--;
	}
	return cur;
}

const ll C = 0;
ll md[111111];
vector<ll> M[111111];

ll fast(ll n, ll m, ll s, ll t)
{
	if(t<=n) return naive(n,m,s,t);
	while(t%n!=0)
	{
		if(s%n>=m)
		{
			s-=t;
		}
		else
		{
			s+=t;
		}
		s%=n;
		if(s<0) s+=n;
		t--;
	}
	if(t==0) return s;
	//solve t/n copies of the problem, sort of
	if(m>n-m)
	{
		return n - 1 - fast(n, n-m, n-1-s, t); //check later
	}
	for(ll i=0;i<=n+5;i++)
	{
		ll s = (i*(i-1))/2;
		md[i] = s%n; M[i].clear();
	}
	for(ll i=1;i<=n+5;i++) M[md[i]].pb(i);
	//m <= n - m
	if(m<=C) //small
	{
		vector<vector<ll> > dp(m+2);
		for(int i=0;i<=m;i++)
		{
			dp[i].assign(n,0);
			dp[i][0]=i;
		}
		for(int j=1;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				ll times = j; ll cur = k;
				while(times>0)
				{
					if(cur%n>=m)
					{
						cur-=times;
					}
					else
					{
						cur+=times;
					}
					cur%=n;
					if(cur<0) cur+=n;
					times--;
					if(cur<=m) break;
				}
				dp[k][j]=dp[cur][times];
			}
			ll ext = -1; ll besti = -1;
			for(int k=0;k<m;k++)
			{
				ll r = k - m + md[j+1];
				r%=n; if(r<0) r+=n;
				int lb = lower_bound(M[r].begin(),M[r].end(),j+1)-M[r].begin();
				lb--;
				if(lb>=0)
				{
					ll curi = M[r][lb];
					if(curi>besti)
					{
						besti=curi; ext=k;
					}
				}
			}
			if(besti==-1)
			{
				ll r = m - md[j+1];
				r%=n; if(r<0) r+=n;
				dp[m][j] = r;
			}
			else
			{
				dp[m][j] = dp[ext][besti-1];
			}
		}
		vector<ll> F(n+2,0);
		for(int i=0;i<=m;i++) F[i]=dp[i][n-1];
		for(int i=m+1;i<n;i++)
		{
			ll ext = -1; ll besti = -1; ll j = n - 1;
			for(int k=0;k<m;k++)
			{
				ll r = k - i + md[j+1];
				r%=n; if(r<0) r+=n;
				int lb = lower_bound(M[r].begin(),M[r].end(),j+1)-M[r].begin();
				lb--;
				if(lb>=0)
				{
					ll curi = M[r][lb];
					if(curi>besti)
					{
						besti=curi; ext=k;
					}
				}
			}
			if(besti==-1)
			{
				ll r = i - md[j+1];
				r%=n; if(r<0) r+=n;
				F[i] = r;
			}
			else
			{
				F[i] = dp[ext][besti-1];
			}
		}
		/*
		for(int i=0;i<n;i++) cerr<<F[i]<<' ';
		cerr<<'\n';
		*/
		ll cyc = t/n;
		//solve cyc cycles tbh
		map<ll,ll> ma;
		ma[s] = cyc;
		vector<ll> V; V.pb(s);
		ll len = -1;
		while(cyc>0)
		{
			cyc--;
			ll news = F[s]; s = news; V.pb(s);
			if(ma.find(news)==ma.end())
			{
				ma[news]=cyc;
			}
			else
			{
				ll cur = ma[news];
				len = cur - cyc;
				break;
			}
		}
		if(cyc==0) return s;
		//I still need cyc times :(
		cyc%=len;
		int id=0;
		for(int i=0;i<V.size();i++)
		{
			if(V[i]==s){id=i; break;}
		}
		return V[id+cyc];
	}
	else //do big
	{
		ll cyc = t/n;
		//solve cyc cycles tbh
		map<ll,ll> ma;
		ma[s] = cyc;
		vector<ll> V; V.pb(s);
		ll len = -1;
		while(cyc>0)
		{
			cyc--;
			ll news = naive(n, m, s, n); s = news; V.pb(s);
			if(ma.find(news)==ma.end())
			{
				ma[news]=cyc;
			}
			else
			{
				ll cur = ma[news];
				len = cur - cyc;
				break;
			}
		}
		if(cyc==0) return s;
		//I still need cyc times :(
		cyc%=len;
		int id=0;
		for(int i=0;i<V.size();i++)
		{
			if(V[i]==s){id=i; break;}
		}
		return V[id+cyc];
	}
}


void test(ll n, ll m)
{
	{
		cout<<"TEST "<<m<<" : ";
		//set<ll> S;
		for(ll s=0;s<n;s++)
		{
			//S.insert(naive(n,m,s,n-1));
			cout<<naive(n,m,s,n-1)<<' ';
		}
		//cout<<S.size()<<'\n';
	}
}

const bool DEBUG = 0;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//test(1882,22); return 0;
	//ll n; cin>>n; test(n);
	for(int cc=1;;cc++)
	{
		ll n,m,s,t;
		if(!DEBUG)
		{
			cin>>n>>m>>s>>t; s--;
		}
		else
		{
			n=rand()%2500+1;m=rand()%(n-1)+1;s=rand()%n;t=rand()+1;
		}
		ll f=fast(n,m,s,t);
		if(!DEBUG){cout<<f+1<<'\n'; return 0;}
		ll ss=naive(n,m,s,t);
		cerr<<"FAST : "<<f<<'\n';
		cerr<<"ANSWER : "<<ss<<'\n';
		if(f!=ss)
		{
			freopen("metro.out","w",stdout);
			cout<<n<<' '<<m<<' '<<s+1<<' '<<t<<'\n';
			return 0;
		}
		cerr<<"Case #"<<cc<<" complete\n";
	}
}