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

const int DEBUG = 0;
int dist[1111];
deque<int> vec;
int n,k;
int querycnt=0;
int a[1111][1111];
int b[1111][1111];
int cnt[1111];
int cntbad;

void reset()
{
	for(int i=0;i<n;i++)
	{
		dist[i]=1; 
	}
	vec.clear();
	memset(a,0,sizeof(a));
	querycnt=0;
}

void resetsmall(int n2)
{
	memset(b,0,sizeof(b));
	for(int i=0;i<n2;i++)
	{
		cnt[i]=n2-1-i;
	}
	cntbad=(n2*(n2-1))/2;
}

void clr()
{
	if(!DEBUG)
	{
		cout<<"R"<<'\n'; fflush(stdout);
	}
	vec.clear();	
}

void query(int x)
{
	querycnt++;
	if(!DEBUG)
	{
		cout<<"? "<<x+1<<'\n';
		fflush(stdout);
		char c; cin>>c;
		if(c=='Y')
		{
			dist[x]=0;
		}
	}
	else
	{
		for(int v:vec)
		{
			assert(v<x);
			a[v][x]=1;
		}
	}
	vec.pb(x);
	if(int(vec.size())>k) vec.pop_front();
}

void answer()
{
	if(DEBUG)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(!a[i][j])
				{
					cerr<<"FAIL "<<i<<' '<<j<<'\n';
				}
			}
		}
		cerr<<"Number of queries: "<<querycnt<<"/"<<(n*n)/(2*k)<<'\n';
		return ;
	}
	int distcnt=0;
	for(int i=0;i<n;i++) distcnt+=dist[i];
	cout<<"! "<<distcnt<<'\n';
	fflush(stdout);
}

void clot(int l)
{
	l*=(k/2);
	for(int i=l;i<l+k/2;i++) query(i);
}


void solve(int _n, int _k)
{
	n=_n; k=_k;
	reset();
	if(k==1)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				clr();
				query(i);
				query(j);
			}
		}
	}
	else 
	{
		vi vec;
		for(int i=0;i<n;i+=k/2) vec.pb(i);
		int n2 = vec.size();
		//problem is equivalent to N = n2, K = 2
		resetsmall(n2);
		while(cntbad>0)
		{
			int s=0;
			for(int i=0;i<n2;i++)
			{
				if(cnt[i]>0)
				{
					s=i; break;
				}
			}
			clr();
			while(cnt[s]>0)
			{
				clot(s);
				for(int i=s+1;i<n2;i++)
				{
					if(!b[s][i])
					{
						cnt[s]--; cntbad--; b[s][i]=1;
						s=i; break;
					}
				}
			}
			clot(s);
		}
	}
	answer();
}

int main()
{
	int n,k; cin>>n>>k;
	solve(n,k);
}