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
typedef double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int bfs(string s)
{
	//cerr<<"SOLVE "<<s<<": ";
	map<string,int> D;
	D[s]=0;
	queue<string> q;
	q.push(s);
	int n=s.length();
	while(!q.empty())
	{
		string u=q.front(); q.pop();
		for(int i=2;i<=n;i+=2)
		{
			string t=u;
			reverse(t.begin(),t.begin()+i);
			if(D.find(t)==D.end())
			{
				D[t]=D[u]+1; q.push(t);
			}
		}
	}
	/*
	cerr<<D.size()<<'\n';
	for(auto S:D)
	{
		cerr<<S.fi<<'\n';
	}
	*/
	return D.size();
}

vi moves;
void did(vi &p, int x)
{
	x++; moves.pb(2*x);
	reverse(p.begin(),p.begin()+x);
	for(int i=0;i<x;i++)
	{
		if(p[i]>=2) p[i]^=1;
	}
}

void solve()
{
	string a,b; cin>>a>>b;
	vi p,q; moves.clear();
	int n=a.length();
	for(int i=0;i<n;i+=2)
	{
		int l=a[i]-'0'; int r=a[i+1]-'0';
		if(l==r)
		{
			p.pb(l);
		}
		else
		{
			p.pb(l+2);
		}
	}
	for(int i=0;i<n;i+=2)
	{
		int l=b[i]-'0'; int r=b[i+1]-'0';
		if(l==r)
		{
			q.pb(l);
		}
		else
		{
			q.pb(l+2);
		}
	}
	int cnt[4]={0,0,0,0};
	for(int i=0;i<n/2;i++)
	{
		cnt[p[i]]++; cnt[q[i]]--;
	}
	if(cnt[0]!=0||cnt[1]!=0){cout<<-1<<'\n'; return;}
	for(int i=n/2-1;i>=0;i--)
	{
		if(p[i]==q[i]) continue;
		if(q[i]<=1)
		{
			int pos=-1;
			for(int j=i-1;j>=0;j--)
			{
				if(p[j]==q[i])
				{
					pos=j; break;
				}
			}
			assert(pos!=-1);
			did(p,pos);
			did(p,i);
		}
		else
		{
			int pos=-1;
			do
			{
				if(p[0]>=2&&((p[0]^1)==q[i]))
				{
					did(p,i); break;
				}
				for(int j=i-1;j>=0;j--)
				{
					if(p[j]==q[i])
					{
						pos=j; break;
					}
				}
				if(pos==-1)
				{
					int cntq=0;
					for(int j=0;j<=i;j++)
					{
						if(q[j]==q[i]) cntq++;
					}
					int curcnt=0;
					for(int j=0;j<=i;j++)
					{
						if(p[j]==(q[i]^1)) curcnt++;
						if(curcnt==cntq)
						{
							did(p,j); break;
						}
					}
					//did(p,i);
					//cout<<-1<<'\n'; return ;
				}
				else
				{
					did(p,pos);
					did(p,i);
				}
			}while(pos==-1);
		}
	}
	cout<<moves.size()<<'\n';
	for(int x:moves)
	{
		cout<<x<<' ';
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//int n; cin>>n;
	/*
	for(int bit=0;bit<=n;bit++)
	{
		cerr<<"BITCOUNT = "<<bit<<'\n';
		for(int i=0;i<(1<<n);i++)
		{
			if(__builtin_popcount(i)!=bit) continue;
			string s;
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j)) s+='1';
				else s+='0';
			}
			bfs(s);
		}
	}
	*/
	/*
	map<int,vector<string> > ma;
	for(int i=0;i<(1<<n);i++)
	{
		string s;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j)) s+='1';
			else s+='0';
		}
		ma[bfs(s)].pb(s);
	}
	for(auto X:ma)
	{
		cerr<<"D = "<<X.fi<<'\n';
		
		sort(X.se.begin(),X.se.end());
		for(auto y:X.se)
		{
			cerr<<y<<'\n';
		}
		
	}
	*/
	int q; cin>>q;
	while(q--)
	{
		solve();
	}
}