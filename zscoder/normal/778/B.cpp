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
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

map<string,int> ma;
vector<pair<ii,int> > operations;
//0 = AND
//1 = XOR
//2 = OR
string constant[5001];
int operation[5001];
int n, m; 
string X(string &a, string &b)
{
	string res;
	for(int i=0;i<m;i++)
	{
		res+=char(((char(a[i]-'0'))^(char(b[i]-'0')))+'0');
	}
	return res;
}

string O(string &a, string &b)
{
	string res;
	for(int i=0;i<m;i++)
	{
		res+=char(((char(a[i]-'0'))|(char(b[i]-'0')))+'0');
	}
	return res;
}

string A(string &a, string &b)
{
	string res;
	for(int i=0;i<m;i++)
	{
		res+=char(((char(a[i]-'0'))&(char(b[i]-'0')))+'0');
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	ma["?"]=-1;
	ma["$"]=0;
	for(int i=0;i<m;i++) constant[0]+="0";
	for(int i=0;i<n;i++)
	{
		string var; cin>>var;
		ma[var]=i+1;
		string define; cin>>define;
		string z; cin>>z;
		if(z[0]=='1'||z[0]=='0')
		{
			constant[i+1]=z;
			continue;
		}
		else
		{
			string op; cin>>op;
			string z2; cin>>z2;
			if(z=="?"&&z2=="?")
			{
				if(op[0]=='X')
				{
					constant[i+1] = constant[0];
				}
				else
				{
					operation[operations.size()]=i+1;
					operations.pb(mp(mp(-1,0),1));
				}
			}
			else
			{
				operation[operations.size()]=i+1;
				if(op[0]=='A')
				{
					operations.pb(mp(mp(ma[z],ma[z2]),0));
				}
				else if(op[0]=='O')
				{
					operations.pb(mp(mp(ma[z],ma[z2]),2));
				}
				else
				{
					operations.pb(mp(mp(ma[z],ma[z2]),1));
				}
			}
		}
	}
	string mini;
	string maxi;
	for(int i = 0; i < m; i++)
	{
		int v[2];
		v[0]=v[1]=0;
		for(int j = 0; j < 2; j++)
		{
			vi val;
			val.assign(n+1,-1);
			for(int k = 0; k <= n; k++)
			{
				if(!constant[k].empty())
				{
					val[k]=constant[k][i]-'0';
				}
			}
			for(int k = 0; k < operations.size(); k++)
			{
				int l = operations[k].fi.fi; int r = operations[k].fi.se; int op = operations[k].se;
				if(l==-1) swap(l,r);
				int bit=val[l];
				if(r==-1)
				{
					if(op==0) bit&=j;
					else if(op==1) bit^=j;
					else bit|=j;
				}
				else
				{
					if(op==0) bit&=val[r];
					else if(op==1) bit^=val[r];
					else bit|=val[r];
				}
				val[operation[k]]=bit;
				v[j]+=bit;
			}
		}
		if(v[0]<=v[1]) mini+="0";
		else mini+="1";
		if(v[0]>=v[1]) maxi+="0";
		else maxi+="1";
	}
	cout<<mini<<'\n';
	cout<<maxi<<'\n';
}