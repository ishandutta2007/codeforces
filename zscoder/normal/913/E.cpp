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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

set<pair<string,ii> > E[3];

string vis[1111];
string V[1111][3];
struct cmp
{
    bool operator()(pair<string,ii> &a, pair<string,ii> &b)
    {
        if(a.fi.length()!=b.fi.length()) return a.fi.length()>b.fi.length();
        return a.fi>b.fi;
    }
};


void solve(string &s)
{
	int bit=0;
	for(int i=0;i<8;i++)
	{
		if(s[7-i]=='1') bit^=(1<<i);
	}
	cout<<vis[bit]<<'\n';
}

priority_queue<pair<string,ii>, vector<pair<string,ii> >, cmp> pq;
set<string> S;
const int C = 199;

void add(pair<string,ii> x)
{
	int type = x.se.se;
	for(int i=0;i<=type;i++)
	{
		if(V[x.se.fi][i].empty())
		{
			V[x.se.fi][i]=x.fi;
		}
		else if(V[x.se.fi][i].length()>x.fi.length()||((x.fi.length()==V[x.se.fi][i].length())&&(x.fi<V[x.se.fi][i])))
		{
			V[x.se.fi][i]=x.fi;
		}
	}
	if(vis[x.se.fi].length()==0)
	{
		//cerr<<"HERE "<<x.se.fi<<' '<<x.fi<<'\n';
		vis[x.se.fi]=x.fi;
	}
	else if(x.fi.length()<vis[x.se.fi].length()||(x.fi.length()==vis[x.se.fi].length()&&x.fi<vis[x.se.fi]))
	{
		vis[x.se.fi]=x.fi;
	}
	for(int i=0;i<=type;i++) E[i].insert(x);
	if(type>=2)
	{
		//if(x.fi[0]!='!')
		{
			string nw="!";
			for(int i=0;i<x.fi.length();i++) nw+=x.fi[i];
			string tmp=V[x.se.fi^255][2];
			if(nw.length()<=C&&S.find(nw)==S.end())
			{
				if(tmp.empty()||nw.length()<tmp.length()||(nw.length()==tmp.length()&&nw<tmp))
				{
					S.insert(nw);
					pq.push(mp(nw,mp(x.se.fi^255,2)));
				}
			}
		}
		for(auto it=E[1].begin();it!=E[1].end();it++)
		{
			string nw=it->fi;
			nw+="&";
			nw+=x.fi;
			string tmp=V[x.se.fi&it->se.fi][1];
			if(nw.length()<=C&&S.find(nw)==S.end())
			{
				if(tmp.empty()||nw.length()<tmp.length()||(nw.length()==tmp.length()&&nw<tmp))
				{
					S.insert(nw);
					pq.push(mp(nw,mp((x.se.fi&it->se.fi),1)));
				}
			}
		}
	}
	if(type>=1)
	{
		for(auto it=E[2].begin();it!=E[2].end();it++)
		{
			string nw=x.fi;
			nw+="&";
			nw+=it->fi;
			string tmp=V[x.se.fi&it->se.fi][1];
			if(nw.length()<=C&&S.find(nw)==S.end())
			{
				if(tmp.empty()||nw.length()<tmp.length()||(nw.length()==tmp.length()&&nw<tmp))
				{
					S.insert(nw);
					pq.push(mp(nw,mp((x.se.fi&it->se.fi),1)));
				}
			}
		}
		for(auto it=E[0].begin();it!=E[0].end();it++)
		{
			string nw=it->fi;
			nw+="|";
			nw+=x.fi;
			string tmp=V[x.se.fi|it->se.fi][0];
			if(nw.length()<=C&&S.find(nw)==S.end())
			{
				if(tmp.empty()||nw.length()<tmp.length()||(nw.length()==tmp.length()&&nw<tmp))
				{
					S.insert(nw);
					pq.push(mp(nw,mp((x.se.fi|it->se.fi),0)));
				}
			}
		}
	}
	if(type>=0)
	{
		{
			string nw="(";
			for(int i=0;i<x.fi.length();i++) nw+=x.fi[i];
			nw+=")";
			string tmp=V[x.se.fi][2];
			if(nw.length()<=C&&S.find(nw)==S.end())
			{
				if(tmp.empty()||nw.length()<tmp.length()||(nw.length()==tmp.length()&&nw<tmp))
				{
					S.insert(nw);
					pq.push(mp(nw,mp(x.se.fi,2)));
				}
			}
		}
		for(auto it=E[1].begin();it!=E[1].end();it++)
		{
			string nw=x.fi;
			nw+="|";
			nw+=it->fi;
			string tmp=V[x.se.fi|it->se.fi][0];
			if(nw.length()<=C&&S.find(nw)==S.end())
			{
				if(tmp.empty()||nw.length()<tmp.length()||(nw.length()==tmp.length()&&nw<tmp))
				{
					S.insert(nw); pq.push(mp(nw,mp((x.se.fi|it->se.fi),0)));
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	pq.push(mp("x",mp(15,2)));
	pq.push(mp("y",mp((1<<5)+(1<<4)+3,2)));
	pq.push(mp("z",mp((1<<6)+(1<<4)+(1<<2)+1,2)));
	int counter=1;
	while(!pq.empty())
	{
		int maxlength=-1;
		for(int i=0;i<256;i++)
		{
			if(vis[i].empty()) 
			{
				//if(counter%1000==0) cerr<<i<<'\n';
				maxlength=10000000;
			}
			else maxlength=max(int(vis[i].length()),maxlength);
		}
		if(pq.top().fi.length()>maxlength) break;
		pair<string,ii> u = pq.top(); pq.pop();
		string tmp = V[u.se.fi][u.se.se];
		if(tmp.length()>0&&(u.fi.length()>tmp.length()||((u.fi.length()==tmp.length())))) continue;
		counter++;
		//cerr<<u.fi<<' '<<u.se.fi<<' '<<u.fi.length()<<' '<<V[u.se.fi][u.se.se].length()<<' '<<u.se.se<<'\n';
		add(u);
		//if(counter%1000==0) cerr<<counter<<' '<<u.fi<<' '<<u.se.fi<<' '<<u.se.se<<'\n';
	}
	/*
	for(int i=0;i<256;i++)
	{
		cout<<i<<' '<<vis[i]<<endl;
	}
	*/
	int t; cin>>t;
	while(t--)
	{
		string s; cin>>s;
		solve(s);
	}
}