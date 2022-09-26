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
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int par[101][101];
bool avi[101][101];
string user[101];

bool bad(char c)
{
	if(c=='.'||c==','||c==' '||c=='?'||c=='!') return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		map<string,int> ma;
		
		for(int i = 0; i < n; i++)
		{
			string s; cin>>s;
			ma[s]=i+1;
			user[i+1]=s;
		}
		int q; 
		cin>>q;
		vector<string> sender;
		vector<string> message;
		string dummy; getline(cin,dummy);
		for(int i = 0; i < q; i++)
		{
			string s; getline(cin,s);
			//cerr<<s<<'\n';
			string t;
			int ptr = 0;
			for(int j = 0; s[j]!=':'; j++)
			{
				t+=s[j];
				ptr=j;
			}
			string r;
			for(int j = ptr+2; j < s.length(); j++)
			{
				r+=s[j];
			}
			sender.pb(t);
			message.pb(r);
		}
		memset(par,-1,sizeof(par));
		for(int i = 0; i <= 100; i++)
		{
			for(int j = 0; j <= 100; j++)
			{
				avi[i][j] = 1;
			}
		}
		for(int i = 0; i < q; i++)
		{
			vector<string> vec;
			for(int k = 1; k <= 10; k++)
			{
				for(int j = 0; j < message[i].length(); j++)
				{
					if(j+k-1<message[i].length()) 
					{
						string tm = message[i].substr(j,k);
						
						//cerr<<tm<<'\n';
						int tmp = ma[tm];
						if(tmp)
						{
							//cur = [j,j+k-1];
							bool tt = 1;
							if(j-1>=0&&!bad(message[i][j-1]))
							{
								tt=0;
							}
							
							if(j+k<message[i].length()&&!bad(message[i][j+k]))
							{
								tt=0;
							}
							
							if(tt)
							{
								avi[i][tmp]=0;
							}
						}
					}
				}
			}
			int tt = ma[sender[i]];
			//cerr<<tt<<'\n';
			if(tt)
			{
				for(int j = 1; j <= n; j++)
				{
					if(j!=tt) avi[i][j]=0;
				}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			if(avi[0][i])
			{
				par[0][i] = 0;
			}
		}
		for(int i = 1; i < q; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(avi[i][j])
				{
					for(int k = 1; k <= n; k++)
					{
						if(k!=j&&par[i-1][k]!=-1)
						{
							//cerr<<i<<' '<<j<<' '<<k<<'\n';
							par[i][j] = k;
							break;
						}
					}
				}
			}
		}
		vector<string> ans;
		int cur = -1;
		for(int i = 1; i <= n; i++)
		{
			//cerr<<i<<' '<<par[q-1][i]<<'\n';
			if(par[q-1][i]!=-1)
			{
				cur=par[q-1][i];
				string s = user[i];
				s+=":";
				s+=message[q-1];
				ans.pb(s);
				break;
			}
		}
		if(cur==-1)
		{
			cout<<"Impossible\n";
			continue;
		}
		int tmp = q-2;
		while(tmp>=0)
		{
			string s = user[cur];
			s+=":";
			s+=message[tmp];
			ans.pb(s);
			cur=par[tmp--][cur];
		}
		for(int i = int(ans.size())-1; i>=0;i--)
		{
			cout<<ans[i]<<'\n';
		}
	}
}