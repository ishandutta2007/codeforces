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

int sod(int x)
{
	int ans=0;
	while(x)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}

void solve(ll x)
{
	if(x<=9) 
	{
		cout<<x<<'\n';
		cout<<x<<'\n';
		exit(0);
	}
	vi dig;
	while(x)
	{
		dig.pb(x%10);
		x/=10;
	}
	reverse(dig.begin(),dig.end());
	int n=dig.size();
	for(int i=0;i<(1<<(n-1));i++)
	{
		int cur = dig[0];
		int ans = 0;
		for(int j=1;j<n;j++)
		{
			if(i&(1<<(j-1)))
			{
				ans+=cur;
				cur=0;
				cur*=10;
				cur+=dig[j];
			}
			else
			{
				cur*=10;
				cur+=dig[j];
			}
		}
		ans+=cur;
		if(sod(ans)<=9) 
		{
			for(int j=0;j<n;j++)
			{
				if(j>0&&(i&(1<<(j-1)))) cout<<"+"; 
				cout<<dig[j];
			}
			cout<<'\n';
			vi emp;
			if(ans==0) emp.pb(0);
			while(ans)
			{
				emp.pb(ans%10);
				ans/=10;
			}
			reverse(emp.begin(),emp.end());
			for(int j=0;j<emp.size();j++)
			{
				cout<<emp[j];
				if(j+1<int(emp.size())) cout<<'+';
			}
			cout<<'\n';
			exit(0);
		}
	}
	return ;
}

bool valid(ll x)
{
	if(x<=9) return 1;
	vi dig;
	while(x)
	{
		dig.pb(x%10);
		x/=10;
	}
	reverse(dig.begin(),dig.end());
	int n=dig.size();
	for(int i=0;i<(1<<(n-1));i++)
	{
		int cur = dig[0];
		int ans = 0;
		for(int j=1;j<n;j++)
		{
			if(i&(1<<(j-1)))
			{
				ans+=cur;
				cur=0;
				cur*=10;
				cur+=dig[j];
			}
			else
			{
				cur*=10;
				cur+=dig[j];
			}
		}
		ans+=cur;
		if(sod(ans)<=9) 
		{
			return 1;
		}
	}
	return 0;
}

ll rnd()
{
	return (rand()<<15)^rand();
}

int a[222222];
bool x[2000001];
vi R;
vi odd[11];
vi even[11];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	/*
	freopen("digits-fail.txt","w",stdout);
	for(int i=1;i<=200000*9;i++)
	{
		if(!valid(i))
		{
			if(i%9==1)
			{
				x[i]=1; cout<<i<<'\n';
			}
		}
	}
	int maxr=0; int r=0;
	for(int i=1;i<=200000*9;i+=9)
	{
		if(x[i])
		{
			r++;
		}
		else
		{
			maxr=max(maxr,r);
			r=0;
		}
	}
	cerr<<maxr<<'\n';
	return 0;
	*/
	int n;cin>>n;
	string s; cin>>s;
	ll cur = 0;
	for(int i=0;i<s.length();i++) 
	{
		a[i]=s[i]-'0';
		cur+=s[i]-'0';
	}
	if(valid(cur))
	{
		for(int i=0;i<s.length();i++)
		{
			cout<<s[i];
			if(i+1<s.length()) cout<<'+';
		}
		cout<<'\n';
		solve(cur);
		return 0;
	}
	//cerr<<cur<<'\n';
	
	for(int i=0;i+1<s.length();i++)
	{
		ll cur2 = cur - a[i] - a[i+1];
		cur2 += 10*a[i]+a[i+1];
		R.pb(9*a[i]);
		if(i&1) odd[a[i]].pb(i);
		else even[a[i]].pb(i);
		if(valid(cur2))
		{
			for(int j=0;j<s.length();j++)
			{
				cout<<s[j];
				if(j+1<s.length()&&j!=i) cout<<'+';
			}
			cout<<'\n';
			solve(cur2);
			return 0;
		}
		
	}
	
	ll tmp = cur;
	for(int i = 0; i < R.size(); i+=2)
	{
		 tmp+=R[i];
		 //cerr<<tmp<<'\n';
		 if(valid(tmp))
		 {
			for(int j=0;j<s.length();j++)
			{
				cout<<s[j];
				if(j+1<s.length()&&((j&1)||(j>i))) cout<<'+';
			}
			cout<<'\n';
			solve(tmp);
			return 0;
		 }
	}
	tmp = cur;
	for(int i = 1; i < R.size(); i+=2)
	{
		 tmp+=R[i];
		 //cerr<<tmp<<'\n';
		 if(valid(tmp))
		 {
			for(int j=0;j<s.length();j++)
			{
				cout<<s[j];
				if(j+1<s.length()&&((j%2==0)||(j>i))) cout<<'+';
			}
			cout<<'\n';
			solve(tmp);
			return 0;
		 }
	}
	
	for(ll i = cur; i <= cur + 3000000; i += 9)
	{
		if(valid(i))
		{
			ll ext = (i - cur)/9;
			vi C(10);
			for(int j = 9; j >= 1; j--)
			{
				ll mx = ext/j;
				mx = min(mx, ll(odd[j].size()));
				C[j] = mx;
				ext -= mx*j;
			}
			if(ext==0)
			{
				set<int> S;
				for(int j=9;j>=1;j--)
				{
					for(int k=0;k<C[j];k++)
					{
						S.insert(odd[j][k]);
					}
				}
				for(int j=0;j<s.length();j++)
				{
					cout<<s[j];
					if(j+1<s.length()&&(S.find(j)==S.end())) cout<<'+';
				}
				cout<<'\n';
				solve(i);
				return 0;
			}
			ext = (i-cur)/9;
			for(int j = 9; j >= 1; j--)
			{
				ll mx = ext/j;
				mx = min(mx, ll(even[j].size()));
				C[j] = mx;
				ext -= mx*j;
			}
			if(ext==0)
			{
				set<int> S;
				for(int j=9;j>=1;j--)
				{
					for(int k=0;k<C[j];k++)
					{
						S.insert(even[j][k]);
					}
				}
				for(int j=0;j<s.length();j++)
				{
					cout<<s[j];
					if(j+1<s.length()&&(S.find(j)==S.end())) cout<<'+';
				}
				cout<<'\n';
				solve(i);
				return 0;
			}
		}
	}
	
	for(int i = 0; i < 100000; i++)
	{
		vi V;
		for(int j = 0; j < rnd()%50+1; j++)
		{
			V.pb(rnd()%(int(s.length()) - 1));
		}
		sort(V.begin(),V.end());
		V.erase(unique(V.begin(),V.end()),V.end());
		vi W;
		for(int j=0;j<V.size();j++)
		{
			if(W.empty()) W.pb(V[j]);
			else
			{
				if(W.back()+1==V[j])
				{
					continue;
				}
				else
				{
					W.pb(V[j]);
				}
			}
		}
		ll cur2 = cur;
		for(int i=0;i<W.size();i++)
		{
			cur2 -= a[W[i]] + a[W[i]+1];
			cur2 += 10*a[W[i]]+a[W[i]+1];
		}
		if(valid(cur2))
		{
			for(int j=0;j<s.length();j++)
			{
				cout<<s[j];
				if(j+1<s.length()&&!binary_search(W.begin(),W.end(),j)) cout<<'+';
			}
			cout<<'\n';
			solve(cur2);
			return 0;
		}
	}
	for(int i = 0; i < 30000; i++)
	{
		vi V;
		for(int j = 0; j < rnd()%100+1; j++)
		{
			V.pb(rnd()%(int(s.length()) - 1));
		}
		sort(V.begin(),V.end());
		V.erase(unique(V.begin(),V.end()),V.end());
		vi W;
		for(int j=0;j<V.size();j++)
		{
			if(W.empty()) W.pb(V[j]);
			else
			{
				if(W.back()+1==V[j])
				{
					continue;
				}
				else
				{
					W.pb(V[j]);
				}
			}
		}
		ll cur2 = cur;
		for(int i=0;i<W.size();i++)
		{
			cur2 -= a[W[i]] + a[W[i]+1];
			cur2 += 10*a[W[i]]+a[W[i]+1];
		}
		if(valid(cur2))
		{
			for(int j=0;j<s.length();j++)
			{
				cout<<s[j];
				if(j+1<s.length()&&!binary_search(W.begin(),W.end(),j)) cout<<'+';
			}
			cout<<'\n';
			solve(cur2);
			return 0;
		}
	}
	for(int i = 0; i < 10000; i++)
	{
		vi V;
		for(int j = 0; j < rnd()%10+1; j++)
		{
			V.pb(rnd()%(int(s.length()) - 1));
		}
		sort(V.begin(),V.end());
		V.erase(unique(V.begin(),V.end()),V.end());
		vi W;
		for(int j=0;j<V.size();j++)
		{
			if(W.empty()) W.pb(V[j]);
			else
			{
				if(W.back()+1==V[j])
				{
					continue;
				}
				else
				{
					W.pb(V[j]);
				}
			}
		}
		ll cur2 = cur;
		for(int i=0;i<W.size();i++)
		{
			cur2 -= a[W[i]] + a[W[i]+1];
			cur2 += 10*a[W[i]]+a[W[i]+1];
		}
		if(valid(cur2))
		{
			for(int j=0;j<s.length();j++)
			{
				cout<<s[j];
				if(j+1<s.length()&&!binary_search(W.begin(),W.end(),j)) cout<<'+';
			}
			cout<<'\n';
			solve(cur2);
			return 0;
		}
	}
}