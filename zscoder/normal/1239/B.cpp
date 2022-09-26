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

int match[333333];
int par[333333];
int h[333333];
vi adj[333333];
int pre[333333];
int suf[333333];
int a[333333];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=(s[i]=='('?1:-1);
	}
	if(sum!=0)
	{
		cout<<0<<'\n'; cout<<1<<' '<<1<<'\n'; return 0;
	}
	sum=0;
	int id=-1;
	int mn=int(1e9);
	for(int i=0;i<n;i++)
	{
		sum+=(s[i]=='('?1:-1);
		if(sum<mn)
		{
			mn=sum; id=i;
		}
	}
	id++;
	int sft = id;
	string t = s.substr(id,n-id)+s.substr(0,id);
	s=t;
	//find first occurrence of (( and it's match
	stack<int> S;
	vi interested;
	int beg=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
		{
			S.push(i);
		}
		else
		{
			match[S.top()]=i;
			match[i]=S.top();
			S.pop();
		}
		h[i]=S.size();
		if(S.empty()) 
		{
			interested.pb(beg);
			beg=i+1;
		}
	}
	/*
	int rt=n+1;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
		{
			adj[rt].pb(i); par[i]=rt;
			rt=i;
		}
		else
		{
			rt=par[rt];
		}
	}
	if(beg<n) interested.pb(beg);
	if(interested.size()>1)
	{
		int mx=interested.size();
		ii pr=mp(1,1);
		for(int i=0;i<n;i++)
		{
			if(h[i]>1&&s[i]=='(')
			{
				int l=i; int r=match[i];
				int newcnt=interested.size()+1+adj[l].size();
				if(newcnt>mx)
				{
					mx=newcnt;
					pr.fi=(l+sft)%n+1;
					pr.se=(r+sft)%n+1;
					}
			}
		}
		cout<<mx<<'\n';
		cout<<pr.fi<<' '<<pr.se<<'\n';
		return 0;
	}
	id=-1; int mx=-1;
	for(int l:interested)
	{
		int r = match[l];
		int cnt=0;
		int i=l+1;
		while(i<r)
		{
			cnt++;
			i=match[i]+1;
		}
		if(cnt>mx)
		{
			mx=cnt; id=r;
		}
	}
	cout<<interested.size()+mx<<'\n';
	cout<<(id+sft)%n+1<<' '<<(match[id]+sft)%n+1<<'\n';
	*/
	sum=0; int mncnt=0;
	for(int i=0;i<n;i++)
	{
		sum+=(s[i]=='('?1:-1);
		a[i]=sum;
		if(a[i]==0) mncnt++;
	}
	int l=-1; int cnt=0;
	int ans=mncnt;
	ii bestp = mp(1,1);
	for(int i=0;i<n;i++)
	{
		if(a[i]<2)
		{
			l=-1; cnt=0; continue;
		}
		if(a[i]==2)
		{
			if(l==-1)
			{
				l=i;
				assert(s[i]=='(');
			}
			cnt++;
			if(s[i+1]==')'&&mncnt+cnt>ans)
			{
				ans=mncnt+cnt;
				bestp=mp((l+sft)%n+1,(i+1+sft)%n+1);
			}
		}
	}
	l=-1;
	for(int i=0;i<n;i++)
	{
		if(a[i]<1)
		{
			l=-1; cnt=0; continue;
		}
		if(a[i]==1)
		{
			if(l==-1)
			{
				l=i;
				assert(s[i]=='(');
			}
			cnt++;
			if(s[i+1]==')'&&cnt>ans)
			{
				ans=cnt;
				bestp=mp((l+sft)%n+1,(i+1+sft)%n+1);
			}
		}
		
	}
	cout<<ans<<'\n';
	cout<<bestp.fi<<' '<<bestp.se<<'\n';
}