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
int n,b;

bool ask(int id, string pre)
{
	cout<<id<<' '<<pre<<'\n';
	fflush(stdout);
	string s; cin>>s;
	return (s[0]=='y');
}

void solve(vi a, string pre)
{
	//cerr<<"SOLVE: "<<a.size()<<' '<<pre<<'\n';
	if(pre.length()>=b) {ask(0,pre); return ;}
	vector<pair<int,string> > vec;
	vec.pb({0,pre});
	//phase 1: 
	for(int v:a)
	{
		while(vec.size()>1)
		{
			string pref = vec.back().se;
			while(pref.length()<b) pref.pb('1');
			if(!ask(v,pref)) //if current value is <= this pref
			{
				break;
			}
			//current value is > this pref => this prefix is inaccurate
			vec.pop_back();
		}
		//do i rly need sth here
		string pref = vec.back().se;
		if(pref.length()==b) continue;
		//check next bit
		pref.pb('0');
		while(pref.length()<b) pref.pb('1');
		if(ask(v,pref))
		{
			pref = vec.back().se + "1";
			vec.pb({v,pref});
		}
		else
		{
			pref = vec.back().se + "0";
			vec.pb({v,pref});
		}
	}
	//recurse
	vi nw;
	string res = vec.back().se;
	while(vec.size()>1)
	{
		string tmp = res;
		while(tmp.length()<b) tmp+="1";
		if(ask(vec.back().fi,tmp))
		{
			nw.clear();
			res=vec.back().se; //new max
		}
		nw.pb(vec.back().fi);
		vec.pop_back();
	}
	solve(nw,res);
}

int main()
{
	cin>>n>>b;
	vi v;
	for(int i=1;i<=n;i++) v.pb(i);
	solve(v,"");
}