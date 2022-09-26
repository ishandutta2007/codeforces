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

const ll MOD = 99999999977;
const int C = 6;

ll hsh(string &s)
{
	ll x=0;
	for(int i=0;i<s.length();i++)
	{
		x*=C;
		x+=s[i]-'a'+1;
		while(x>=MOD) x-=MOD;
		if(x<0) x+=MOD;
	}
	return x;
}

map<ll,int> S;
string cur;
set<ll> s;

void dfs(int pos, ll h)
{
	//cerr<<pos<<' '<<h[0]<<' '<<h[1]<<' '<<h[2]<<'\n';
	if(pos>=int(cur.length()))
	{
		s.insert(h);
		return ;
	} 
	if(cur[pos]=='?')
	{
		dfs(pos+1,h);
		for(int i=0;i<5;i++)
		{
			ll h2 = h;
			h2*=C;
			h2+=(i+1);
			while(h2>=MOD) h2-=MOD;
			if(h2<0) h2+=MOD;
			dfs(pos+1,h2);
		}
		
	}
	else
	{
		h*=C;
		h+=cur[pos]-'a'+1;
		while(h>=MOD) h-=MOD;
		if(h<0) h+=MOD;
		dfs(pos+1,h);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin>>n>>m;
	//n=100000;m=5000;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		//for(int j=0;j<50;j++) s+='a';
		ll V = hsh(s);
		//cerr<<V[0]<<' '<<V[1]<<' '<<V[2]<<'\n';
		S[V]++;
	}
	for(int i=0;i<m;i++)
	{
		cur="";
		cin>>cur;
		//for(int j=0;j<47;j++) cur+='a';
		//cur+="???";
		dfs(0,0);
		int ans=0;
		for(auto it = s.begin(); it != s.end(); it++)
		{
			if(S.find((*it))!=S.end())
			{
				ans+=S[(*it)];
			}
		}
		s.clear();
		cout<<ans<<'\n';
	}
}