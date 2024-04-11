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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

set<string> S[22];

bool tristackable(string &s)
{
	vi v;
	for(int i=0;i<s.length();i++)
	{
		v.pb(s[i]);
		if(v.size()>=3&&v[int(v.size())-2]==v[int(v.size())-1]&&v[int(v.size())-2]==v[int(v.size())-3])
		{
			v.pop_back();v.pop_back();v.pop_back();
		}
	}
	return (v.empty());
}

void brute(int n)
{
	for(auto s:S[n-1])
	{
		int len = s.length();
		string lul = "111";
		if(n%2==0) lul="000";
		for(int i=0;i<=len;i++)
		{
			string nw = s.substr(0,i)+lul+s.substr(i,len-i);
			S[n].insert(nw);
		}
	}
}

string conv(int bit, int n)
{
	string s;
	for(int i=0;i<n;i++)
	{
		if(bit&(1<<i)) s+="1";
		else s+="0";
	}
	return s;
}

vi adj[1222];
int par[1222];
int val[1222];
vi score[1222];

set<int> good[2]; //score.fi,.se>0
set<ii> SS[2][2]; //value, score type

void add(int u)
{
	if(score[u][0]>0&&score[u][1]>0)
	{
		good[val[u]].insert(u);
		return ;
	}
	int ty = (score[u][1]>0?1:0); //can i contribute to 1's economy?
	SS[val[u]][ty].insert({-score[u][ty],u});
}

void del(int u)
{
	if(score[u][0]>0&&score[u][1]>0)
	{
		good[val[u]].erase(u);
		return ;
	}
	int ty = (score[u][1]>0?1:0); //can i contribute to 1's economy?
	SS[val[u]][ty].erase({-score[u][ty],u});
}

void relax(int u)
{
	if(u!=0) del(u);
	for(int v:adj[u]) add(v);
}

bool determine_verdict(string s) //how to determine if s is winnable?
{
	int n=s.length(); assert(n%3==0);
	//cerr<<"DETERMINE: "<<s<<'\n';
	for(int i=0;i<=n;i++) 
	{
		adj[i].clear(); par[i]=-1; val[i]=0;
	}
	good[0].clear(); good[1].clear();
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			SS[i][j].clear();
		}
	}
	int cur=0; //root node is 0
	int cntnodes=0;
	vector<pair<int,char> > v;
	for(int i=0;i<n;i++)
	{
		v.pb({i+1,s[i]});
		if(v.size()>=3&&v[int(v.size())-2].se==v[int(v.size())-1].se&&v[int(v.size())-2].se==v[int(v.size())-3].se) //XXX
		{
			v.pop_back();v.pop_back();v.pop_back();
			cur=par[cur];
		}
		else if(v.size()==1||v[int(v.size())-1].se!=v[int(v.size())-2].se) //?XO
		{
			par[i+1]=cur; cntnodes++;
			//cerr<<"ADD EDGE "<<cur<<' '<<i+1<<'\n';
			adj[cur].pb(i+1);
			val[i+1]=(s[i]-'0');
			cur=i+1;
		}
	}
	if(cntnodes!=n/3) return false;
	//check if the tree is winnable
	for(int i=0;i<=n;i++)
	{
		score[i]={0,0};
		for(int v:adj[i])
		{
			score[i][val[v]]++;
		}
		//cerr<<i<<' '<<score[i][0]<<' '<<score[i][1]<<'\n';
	}
	relax(0);
	for(int i=0;i<n/3;i++)
	{
		int id=(i+1)&1; //this is the type i want to delete
		if(!good[id].empty())
		{
			int u = (*good[id].begin());
			relax(u); continue;
		}
		ii sc[2] = {{-1,-1},{-1,-1}};
		for(int j=0;j<2;j++)
		{
			if(!SS[id][j].empty())
			{
				sc[j]=(*SS[id][j].begin());
				sc[j].fi*=-1;
			}
		}
		//cerr<<"IT: "<<i<<' '<<sc[0].fi<<' '<<sc[0].se<<' '<<sc[1].fi<<' '<<sc[1].se<<'\n';
		if(sc[0].fi<0&&sc[1].fi<0) return false; //no value to take
		if(sc[id^1].fi>0)
		{
			relax(sc[id^1].se);
		}
		else if(sc[id].fi>0)
		{
			relax(sc[id].se);
		}
		else if(sc[id^1].fi>=0)
		{
			relax(sc[id^1].se);
		}
		else
		{
			relax(sc[id].se);
		}
	}
	return true;
}

vector<vi> moves;

void solve(string s, vi pos)
{
	int n=s.length();
	if(n==0) return ;
	int turn = (n/3)%2;
	for(int i=0;i<=n-2;i++)
	{
		if(s[i]=='0'+turn&&s[i+1]=='0'+turn&&s[i+2]=='0'+turn)
		{
			string t = s.substr(0,i)+s.substr(i+3,n-3-i);
			if(determine_verdict(t))
			{
				moves.pb({pos[i],pos[i+1],pos[i+2]});
				vi res;
				for(int j=0;j<i;j++) res.pb(pos[j]);
				for(int j=i+3;j<n;j++) res.pb(pos[j]);
				solve(t,res);
				return ;
			}
		}
	}
	assert(0);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	/*
	S[0].insert("");
	for(int i=1;i<=n;i++)
	{
		brute(i);
		cerr<<"SIZE OF "<<i<<" = "<<S[i].size()<<'\n';
		cerr<<"STRINGS AT n = "<<i<<":\n";
		for(auto s:S[i])
		{
			if(!determine_verdict(s)) 
			{
				cerr<<"FAIL: "<<s<<'\n'; exit(0);
			}
		}
		int cnt=0;
		for(int j=0;j<(1<<(3*i));j++)
		{
			if(__builtin_popcount(j)==(3*((i+1)/2)))
			{
				string tmp = conv(j,i*3);
				if(tristackable(tmp)&&S[i].find(tmp)==S[i].end())
				{
					//cerr<<determine_verdict(tmp)<<endl;
					assert(!determine_verdict(tmp));
					//cerr<<tmp<<' '<<determine_verdict(tmp)<<'\n';
					cnt++;
				}
			}
		}
		cerr<<"SIZE OF MISSING TRISTACKABLE "<<i<<" = "<<cnt<<'\n';
	}
	*/
	string s;
	for(int i=0;i<6*n;i++) s+="1";
	vi pos;
	for(int i=0;i<6*n;i++) pos.pb(i);
	for(int i=0;i<3*n;i++)
	{
		int x; cin>>x; x--; s[x]='0';
	}
	solve(s,pos);
	for(auto X:moves)
	{
		for(auto v:X)
		{
			cout<<v+1<<' ';
		}
		cout<<'\n';
	}
}