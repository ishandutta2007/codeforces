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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const bool DEBUG=0;

bool check(string s, string t, string l, string r)
{
	for(int i=0;i<s.length();i++)
	{
		s[i]=t[s[i]-'a'];
	}
	return (s>=l&&s<=r);
}
string S;
string ss,L,R;
int K;
void gencase()
{
	int k=4; K=k;
	int n=66;ss="";L="";R="";
	for(int i=0;i<n;i++)
	{
		ss+=rand()%k+'a';
		L+=rand()%k+'a';
		R+=rand()%k+'a';
	}
	if(L>R) swap(L,R);
}

string solve_brute()
{
	int k=K; string s=ss; string l=L; string r=R;
	vi perm(k,0);
	for(int i=0;i<k;i++) perm[i]=i;
	do
	{
		string sz;
		for(int i=0;i<perm.size();i++)
		{
			sz+=char('a'+perm[i]);
		}
		if(check(s,sz,l,r)) return sz;
	}while(next_permutation(perm.begin(),perm.end()));
	return "";
}

bool solve_case()
{
	int k; 
	string s,l,r; 
	if(DEBUG)
	{
		gencase();
		s=ss;l=L;r=R;k=K;
	}
	else
	{
		cin>>k; cin>>s>>l>>r;
	}
	int n=s.length();
	int marked[33];
	memset(marked,-1,sizeof(marked));
	bool used[33];
	memset(used,0,sizeof(used));
	int i=0;
	string ans="";
	while(i<n)
	{
		if(l[i]==r[i])
		{
			if(marked[s[i]-'a']!=-1)
			{
				if(marked[s[i]-'a']!=l[i]-'a'){return false;}
			}
			else
			{
				if(used[l[i]-'a']){return false;}
				marked[s[i]-'a']=l[i]-'a';
				used[l[i]-'a']=1;
			}
		}
		else break;
		i++;
	}
	while(i<n&&marked[s[i]-'a']!=-1)
	{
		int c = marked[s[i]-'a'];
		if(c>l[i]-'a'&&c<r[i]-'a')
		{
			int ptr=0;
			for(int j=0;j<k;j++)
			{
				if(marked[j]!=-1) continue;
				while(ptr<k&&used[ptr]) ptr++;
				marked[j]=ptr; used[ptr]=1;
			}
			S="";
			for(int j=0;j<k;j++)
			{
				S+=char(marked[j]+'a');
			}
			return true;
		}
		if(c==l[i]-'a')
		{
			int marked2[33]; bool used2[33];
			for(int i=0;i<k;i++)
			{
				marked2[i]=marked[i]; used2[i]=used[i];
			}
			char x = l[i];
			{
				int ptr=k-1; bool pos=1;
				for(int j=i+1;j<n;j++)
				{
					if(marked2[s[j]-'a']!=-1)
					{
						if(marked2[s[j]-'a']<l[j]-'a')
						{
							pos=0; break;
						}
						if(marked2[s[j]-'a']>l[j]-'a')
						{
							break;
						}
					}
					else
					{
						while(ptr>=0&&used2[ptr]) ptr--;
						marked2[s[j]-'a']=ptr; used2[ptr]=1;
						if(ptr>l[j]-'a') break;
						if(ptr<l[j]-'a'){pos=0; break;}
					}
				}
				if(pos)
				{
					int ptr=0;
					for(int j=0;j<k;j++)
					{
						if(marked2[j]!=-1) continue;
						while(ptr<k&&used2[ptr]) ptr++;
						marked2[j]=ptr; used2[ptr]=1;
					}
					S="";
					for(int j=0;j<k;j++)
					{
						S+=char(marked2[j]+'a');
					}
					return true;
				}
			}
			return false;
		}
		else if(c==r[i]-'a')
		{
			int marked2[33]; bool used2[33];
			for(int i=0;i<k;i++)
			{
				marked2[i]=marked[i]; used2[i]=used[i];
			}
			char x = r[i];
			{
				int ptr=0; bool pos=1;
				for(int j=i+1;j<n;j++)
				{
					if(marked2[s[j]-'a']!=-1)
					{
						if(marked2[s[j]-'a']>r[j]-'a')
						{
							pos=0; break;
						}
						if(marked2[s[j]-'a']<r[j]-'a')
						{
							break;
						}
					}
					else
					{
						while(ptr<k&&used2[ptr]) ptr++;
						marked2[s[j]-'a']=ptr; used2[ptr]=1;
						if(ptr<r[j]-'a') break;
						if(ptr>r[j]-'a'){pos=0; break;}
					}
				}
				if(pos)
				{
					int ptr=0;
					for(int j=0;j<k;j++)
					{
						if(marked2[j]!=-1) continue;
						while(ptr<k&&used2[ptr]) ptr++;
						marked2[j]=ptr; used2[ptr]=1;
					}
					S="";
					for(int j=0;j<k;j++)
					{
						S+=char(marked2[j]+'a');
					}
					return true;
				}
			}
			return false;
		}
		else return false;
	}
	if(i==n)
	{
		int ptr=0;
		for(int j=0;j<k;j++)
		{
			if(marked[j]!=-1) continue;
			while(ptr<k&&used[ptr]) ptr++;
			marked[j]=ptr; used[ptr]=1;
		}
		S="";
		for(int j=0;j<k;j++)
		{
			S+=char(marked[j]+'a');
		}
		return true;
	}
	for(char x=l[i]+1;x<r[i];x++)
	{
		if(!used[x-'a']&&(marked[s[i]-'a']==-1||marked[s[i]-'a']==x-'a'))
		{
			marked[s[i]-'a']=x-'a';
			used[x-'a']=1; int ptr=0;
			for(int j=0;j<k;j++)
			{
				if(marked[j]!=-1) continue;
				while(ptr<k&&used[ptr]) ptr++;
				marked[j]=ptr; used[ptr]=1;
			}
			S="";
			for(int j=0;j<k;j++)
			{
				S+=char(marked[j]+'a');
			}
			return true;
		}
	}
	//must use l[i] or r[i]
	//use l[i]
	{
		int marked2[33]; bool used2[33];
		for(int i=0;i<k;i++)
		{
			marked2[i]=marked[i]; used2[i]=used[i];
		}
		char x = l[i];
		if(!used2[x-'a']&&(marked2[s[i]-'a']==-1||marked2[s[i]-'a']==x-'a'))
		{
			marked2[s[i]-'a']=x-'a'; used2[x-'a']=1; int ptr=k-1; bool pos=1;
			for(int j=i+1;j<n;j++)
			{
				if(marked2[s[j]-'a']!=-1)
				{
					if(marked2[s[j]-'a']<l[j]-'a')
					{
						pos=0; break;
					}
					if(marked2[s[j]-'a']>l[j]-'a')
					{
						break;
					}
				}
				else
				{
					while(ptr>=0&&used2[ptr]) ptr--;
					marked2[s[j]-'a']=ptr; used2[ptr]=1;
					if(ptr>l[j]-'a') break;
					if(ptr<l[j]-'a'){pos=0; break;}
				}
			}
			if(pos)
			{
				int ptr=0;
				for(int j=0;j<k;j++)
				{
					if(marked2[j]!=-1) continue;
					while(ptr<k&&used2[ptr]) ptr++;
					marked2[j]=ptr; used2[ptr]=1;
				}
				S="";
				for(int j=0;j<k;j++)
				{
					S+=char(marked2[j]+'a');
				}
				return true;
			}
		}
	}
	{
		int marked2[33]; bool used2[33];
		for(int i=0;i<k;i++)
		{
			marked2[i]=marked[i]; used2[i]=used[i];
		}
		char x = r[i];
		if(!used2[x-'a']&&(marked2[s[i]-'a']==-1||marked2[s[i]-'a']==x-'a'))
		{
			marked2[s[i]-'a']=x-'a'; used2[x-'a']=1; int ptr=0; bool pos=1;
			for(int j=i+1;j<n;j++)
			{
				if(marked2[s[j]-'a']!=-1)
				{
					if(marked2[s[j]-'a']>r[j]-'a')
					{
						pos=0; break;
					}
					if(marked2[s[j]-'a']<r[j]-'a')
					{
						break;
					}
				}
				else
				{
					while(ptr<k&&used2[ptr]) ptr++;
					marked2[s[j]-'a']=ptr; used2[ptr]=1;
					if(ptr<r[j]-'a') break;
					if(ptr>r[j]-'a'){pos=0; break;}
				}
			}
			if(pos)
			{
				int ptr=0;
				for(int j=0;j<k;j++)
				{
					if(marked2[j]!=-1) continue;
					while(ptr<k&&used2[ptr]) ptr++;
					marked2[j]=ptr; used2[ptr]=1;
				}
				S="";
				for(int j=0;j<k;j++)
				{
					S+=char(marked2[j]+'a');
				}
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(!DEBUG)
	{
		int t; cin>>t;
		while(t--)
		{
			if(solve_case())
			{
				cout<<"YES\n";
				cout<<S<<'\n';
			}
			else
			{
				cout<<"NO\n";
			}
		}
	}
	else
	{
		for(int cc=1;;cc++)
		{
			bool a = solve_case();
			string tmp = solve_brute();
			bool pos=1;
			if(a&&!check(ss,S,L,R))
			{
				pos=0;
			}
			bool b = (tmp==""?false:true);
			if(a!=b)
			{
				pos=0;
			}
			if(b&&!check(ss,tmp,L,R))
			{
				pos=0;
			}
			if(!pos)
			{
				freopen("vasya-and-templates.txt","w",stdout);
				cout<<1<<'\n'; cout<<K<<'\n';
				cout<<ss<<'\n';
				cout<<L<<'\n';
				cout<<R<<'\n';
				return 0;
			}
			cerr<<"Case #"<<cc<<" complete\n";
		}
	}
}