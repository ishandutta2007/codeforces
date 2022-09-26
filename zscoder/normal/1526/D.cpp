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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

map<char,int> ma;

ll calc(string a,string b)
{
	vi pa[4];
	vi pb[4];
	for(int i=0;i<a.length();i++)
	{
		pa[ma[a[i]]].pb(i);
	}
	for(int i=0;i<b.length();i++)
	{
		pb[ma[b[i]]].pb(i);
	}
	vi vec(int(a.length()),0);
	int cur[4]={};
	for(int i=0;i<b.length();i++)
	{
		int id=ma[b[i]];
		vec[pa[id][cur[id]++]]=i;
	}
	pbds T;
	ll ans=0;
	for(int i=int(b.length())-1;i>=0;i--)
	{
		ans+=T.order_of_key(vec[i]);
		T.insert(vec[i]);
	}
	return ans;
}

void solve()
{
	string s; cin>>s;
	int c[4] = {};
	for(auto &x:s) c[ma[x]]++;
	ll ans=-1;
	/*
	string t=s;
	sort(t.begin(),t.end());
	vector<string> poss;
	do
	{
		ll res=calc(s,t);
		if(res>ans)
		{
			ans=res; poss={t};
		}
		else if(res==ans)
		{
			poss.pb(t);
		}
	}while(next_permutation(t.begin(),t.end()));
	cerr<<"ANS = "<<ans<<'\n';
	for(auto x:poss)
	{
		cerr<<x<<'\n';
	}
	*/
	string lul="ANOT";
	string best="";
	do
	{
		string t = string(int(s.length()),'$');
		int ptr=0;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<c[ma[lul[i]]];j++)
			{
				t[ptr++]=lul[i];
			}
		}
		ll res=calc(s,t);
		if(res>ans)
		{
			ans=res; best=t;
		}
	}while(next_permutation(lul.begin(),lul.end()));
	cout<<best<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ma['A']=0; ma['N']=1; ma['O']=2; ma['T']=3;
	int t; cin>>t;
	while(t--) solve();
}