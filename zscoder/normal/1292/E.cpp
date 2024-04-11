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

string ans;

void answer()
{
	cout<<"! "<<ans<<'\n'; fflush(stdout);
	int x; cin>>x;
	if(x==0) exit(0);
}

int query(string s)
{
	cout<<"? "<<s<<'\n'; fflush(stdout);
	int k; cin>>k;
	if(k==-1) exit(0);
	for(int i=0;i<k;i++)
	{
		int x; cin>>x;
		x--;
		for(int j=0;j<s.length();j++)
		{
			ans[x+j]=s[j];
		}
	}
	return k;
}

int n;

int countnonempty()
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cnt+=(ans[i]!='?');
	}
	return cnt;
}

void solve()
{
	cin>>n;
	ans="";
	for(int i=0;i<n;i++) ans+="?";
	query("HO");
	query("HC");
	query("CO");
	query("CH");
	set<string> S = {"HO","HC","CO","CH"};
	if(countnonempty()==0)
	{
		query("OOO");
		if(countnonempty()==0)
		{
			query("HHH");
			query("CCC");
			if(countnonempty()==0)
			{
				string a = "OOHH";
				string b = "OOCC";
				query(a);
				if(countnonempty()==n)
				{
					answer();
					return ;
				}
				ans=b;
				answer();
				return ;
			}
			else
			{
				for(int i=0;i<n;i++)
				{
					if(ans[i]=='?') ans[i]='O';
				}
				answer();
			}
		}
		else
		{
			string a = ans; string b = ans;
			for(int i=0;i<n;i++)
			{
				if(a[i]=='?') a[i]='H';
			}
			for(int i=0;i<n;i++)
			{
				if(b[i]=='?') b[i]='C';
			}
			query(a);
			if(countnonempty()==n)
			{
				answer();
				return ;
			}
			ans=b;
			answer();
			return ;
		}
	}
	else
	{
		int mx=0;
		for(int i=n-1;i>=0;i--)
		{
			if(ans[i]!='?')
			{
				mx=i; break;
			}
		}
		string cur = "";
		for(int i=mx;i>=0;i--)
		{
			if(ans[i]=='?')
			{
				char c[3] = {'H','C','O'};
				set<char> T;
				for(int j=0;j<3;j++)
				{
					string tmp="";
					tmp+=c[j];
					tmp+=ans[i+1];
					if(S.find(tmp)==S.end())
					{
						T.insert(c[j]);
					}
				}
				int cc=0;
				while(!T.empty())
				{
					if(cc>=1) break;
					string nw = cur;
					nw = (*T.begin())+cur;
					cc++;
					query(nw);
					if(ans[i]!='?') 
					{
						cur=ans[i]+cur;
						break;
					}
					T.erase(T.begin());
				}
				if(ans[i]=='?') 
				{
					assert(!T.empty());
					ans[i]=(*T.begin());		
					cur = ans[i]+cur;
				}		
			}
			else
			{
				cur=ans[i]+cur;
			}
		}
		//left with OOOO...CCCC
		cur = ans.substr(0,mx+1);
		for(int i=mx+1;i<n;i++)
		{
			string nw = cur+"O";
			query(nw);
			if(ans[i]!='?')
			{
				cur+="O";
			}
			else
			{
				string a=ans; string b=ans;
				for(int i=0;i<n;i++)
				{
					if(a[i]=='?') a[i]='H';
				}
				for(int i=0;i<n;i++)
				{
					if(b[i]=='?') b[i]='C';
				}
				query(a);
				if(countnonempty()==n)
				{
					answer();
					return ;
				}
				ans=b;
				answer();
				return ;
			}
		}
		answer();
	}
}

int main()
{
	int t; cin>>t; 
	while(t--)
	{
		solve();
	}
}