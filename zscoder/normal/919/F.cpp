//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

//#define _CRT_SECURE_NO_WARNINGS
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
typedef unordered_set<ll>::iterator sit;
typedef unordered_map<ll,ll>::iterator mit;

ll Q[10000001];
bitset<10000001> bs;
map<ll,int> dp;
map<ll,set<ll> > adj;
map<ll,int> adj2;
ll hsh(vi &v)
{
	ll x=0;
	for(int i=0;i<v.size();i++)
	{
		x<<=4;
		x^=v[i];
	}
	return x;
}

vi unhsh(ll x)
{
	vi v;
	for(int i=0;i<11;i++)
	{
		v.pb((x&15));
		x>>=4;
	}
	reverse(v.begin(),v.end()); return v;
}

void add(ll &x, int bit)
{
    bit=10-bit;
    x += (1LL<<(bit<<2)); 
}

void subt(ll &x, int bit)
{
    bit=10-bit;
    x -= (1LL<<(bit<<2)); 
}

void swapper(ll &x)
{
	ll fl = (x>>4); int rem = (x&15);
	ll L = (fl>>20); ll R = (fl&((1LL<<20) - 1));
	x = (((R<<20)^L)<<4)^rem;
//	HSH = unhsh(x);
	//for(int v:HSH) cout<<v<<' ';
//	cout<<'\n';
//	cout<<x<<' '<<fl<<' '<<L<<' '<<R<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<vi> V; int s = 0; int e = 0;
	for(int a=0;a<=8;a++)
	{
		for(int b=0;b<=8;b++)
		{
			for(int c=0;c<=8;c++)
			{
				for(int d=0;d<=8;d++)
				{
					int ee=8-a-b-c-d;
					if(ee>=0&&ee<=8)
					{
						vi v = {a,b,c,d,ee};
						V.pb(v);
						if(a==8) continue;
						vi v1 = {8,0,0,0,0,a,b,c,d,ee,0};
						vi v2 = {a,b,c,d,ee,8,0,0,0,0,1};
						//vi v1 = {a,b,c,d,e,8,0,0,0,0,0};
						//vi v2 = {a,b,c,d,e,8,0,0,0,0,1};
						ll t1 = hsh(v1); ll t2= hsh(v2);
						dp[t1] = 1;
						dp[t2] = 0;
						bs.set(e,1); Q[e++] = t1; bs.set(e,0);  Q[e++] = t2; 
					}
				}
			}
		}
	}
	for(int i=0;i<V.size();i++)
	{
		for(int j=0;j<V.size();j++)
		{
			for(int k=0;k<2;k++)
			{
				vi cur;
				bool ft=0;
				ll id = 0; 
				for(int l=1;l<5;l++)
				{
					for(int m=1;m<5;m++)
					{
						if(V[i][l]>0&&V[j][m]>0)
						{
						    if(!ft)
						    {
						        ll x=0;
						        for(int a=0;a<5;a++) {x<<=4;x^=V[i][a];}
				                for(int a=0;a<5;a++) {x<<=4;x^=V[j][a];}
				                x<<=4; x^=k;
				                id=x; ft=1;
						    }
				            ll id2=id;
							if(k==1) {subt(id2,l);add(id2,(l+m)%5);}
							else {subt(id2,m+5);add(id2,(l+m)%5 + 5);}
							id2^=1;
							//swapper(id2);
							adj[id2].insert(id); adj2[id]++;
						}
					}
				}
			}
		}
	}
	while(s<=e)
	{
		int z = bs[s]; ll u=Q[s++]; 
		//cerr<<u<<endl;
		for(auto v:adj[u])
		{
			if(dp.find(v)!=dp.end()) continue;
			if((v&1)!=(u&1))
			{
				if(z==(v&1)) //the player wins like this
				{
					dp[v] = (v&1);bs.set(e,v&1); Q[e++] = v; 
				}
				else //the player avoids this move
				{
					adj2[v]--;
					if(adj2[v]==0)
					{
						dp[v] = (u&1);  bs.set(e,u&1);Q[e++] = v;
					}
				}
			}
			//if same it doesn't go like this
		}
	}
	
	int t; cin>>t;
	//t=100000;
	while(t--)
	{
		int player; 
		cin>>player; 
		//player=rand()&1;
		player^=1;
		vi a(5);
		for(int i=0;i<8;i++)
		{
			int x; cin>>x; a[x]++;
			//a[rand()%5]++;
		}
		vi b(5);
		for(int i=0;i<8;i++)
		{
			int x; cin>>x; b[x]++;
			//b[rand()%5]++;
		}
		vi nw;
		for(int i=0;i<5;i++) nw.pb(a[i]);
		for(int i=0;i<5;i++) nw.pb(b[i]);
		nw.pb(player); ll cur=hsh(nw);
		//if(player==0) swapper(cur);
		if(dp.find(cur)==dp.end())
		{
			cout<<"Deal\n";
		}
		else if(dp[cur]==1)
		{
			cout<<"Alice\n";
		}
		else
		{
			cout<<"Bob\n";
		}
	}
}