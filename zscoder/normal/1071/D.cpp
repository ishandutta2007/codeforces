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

const int N = int(1e6);

int lp[N+11];
bool isprime[N+11];

void sieve (int n) {
	for(int i=2;i<=n;i++) isprime[i]=1,lp[i]=i;
	for(int i=2;i<=n;i++)
	{
		if(isprime[i])
		{
			for(int j=i*2;j<=n;j+=i)
			{
				lp[j]=i; isprime[j]=0;
			}
		}
	}
}

vi get(int x)
{
	map<int,int> ma;
	int cur=x;
	while(cur!=1)
	{
		ma[lp[cur]]++;
		cur/=lp[cur];
	}
	vi V;
	for(ii x:ma)
	{
		V.pb(x.se+1);
	}
	sort(V.begin(),V.end());
	return V;
}

int prod(vi V)
{
	int p=1;
	for(int v:V) p*=v;
	return p;
}

vi V[555];
map<vi,int> ma;
set<int> Pbig;
map<int,int> D[555];
int MX;
int F[555] = {10,9,8,7,6,6,6,7,6,6,7,6,7,6,6,6,7,6,6,6,6,6,6,7,6,6,7,6,6,6,7,6,7,6,6,7,6,7,6,8,7,6,6,6,6,6,6,6,6,7,6,6,6,6,7,7,6,6,7,6,6,6,6,6,7,7,6,6,6,6,6,6,6,6,7,7,6,7,6,7,7,7,6,6,7,6,6,6,6,6,6,6,6,6,6,6,7,6,6,7,7,6,6,6,7,6,7,8,6,6,6,6,7,6,6,7,7,8,6,6,6,6,6,6,6,6,7,6,7,6,6,7,6,6,6,6,6,6,6,6,6,6,7,6,6,6,6,6,7,7,6,6,6,6,6,6,7,6,7,6,7,6,6,6,6,6,6,6,6,6,6,6,6,8,7,6,6,6,7,7,8,6,6,7,6,6,6,6,6,7,7,6,7,6,6,6,6,6,6,6,7,7,6,6,6,7,6,7,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6};

void web(int pos)
{
	queue<vi> Q;
	map<vi,int> dist;
	set<int> S;
	for(int i=0;i<ma.size();i++) S.insert(i);
	//if(prod(V[pos])==3) cerr<<pos<<' '<<prod(V[pos])<<'\n';
	dist[V[pos]]=0; Q.push(V[pos]);
	set<int> PP = Pbig;
	//const int C = 1000;
	//const int C2 = 60;
	const int C = F[pos];
	while(!Q.empty())
	{
		vi v = Q.front(); int d = dist[v]; 
		//int pp=prod(v);
		//PP.erase(pp);
		//if(PP.empty()) break;
		Q.pop();
		if(d>=C) break;
		for(int j=-1;j<=1;j+=2)
		{
			for(int i=0;i<v.size();i++)
			{
				vi nw = v;
				nw[i]+=j;
				sort(nw.rbegin(),nw.rend());
				while(!nw.empty()&&nw.back()==1) nw.pop_back();
				reverse(nw.begin(),nw.end());
				if(dist.find(nw)==dist.end())
				{
					dist[nw]=d+1; Q.push(nw);
				}
			}
		}
		//multiply by 2
		reverse(v.begin(),v.end());
		v.pb(2);
		reverse(v.begin(),v.end());
		if(dist.find(v)==dist.end())
		{
			dist[v]=d+1; Q.push(v);
		}
	}
	for(auto x:dist)
	{
		int pd = prod(x.fi); int d = x.se;
		if(D[pos].find(pd)==D[pos].end())
		{
			D[pos][pd]=d;
		}
		else
		{
			D[pos][pd]=min(D[pos][pd],d);
		}
	}
	//cerr<<"DIST "<<pos<<' '<<(*prev(D[pos].end())).fi<<'\n';
	/*
	cerr<<"DIST "<<pos<<'\n';
	for(ii x:D[pos])
	{
		if(prod(V[pos])==3) cerr<<prod(V[pos])<<' '<<x.fi<<' '<<x.se<<'\n';
	}
	*/
	//cerr<<"DIST "<<pos<<' '<<D[pos].size()<<'\n';
}

int cache[555][555];
void gen(int n)
{
	sieve(n);
	set<vi> S; //set<int> products;
	for(int i=1;i<=n;i++)
	{
		vi V = get(i);
		S.insert(V); //products.insert(prod(V));
	}
	int cnt=0;
	for(auto x:S) 
	{
		V[cnt]=x; ma[x]=cnt++; //Pbig.insert(prod(x));
	}
	/*
	cerr<<"PRODUCTS : "<<products.size()<<'\n';
	cerr<<(*prev(products.end()))<<'\n';
	cerr<<S.size()<<'\n';
	*/
}


const int DEBUG = 0;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	gen(N);
	//for(int i=0;i<ma.size();i++) F[i]=6;
	memset(cache,-1,sizeof(cache));
	for(int i=0;i<ma.size();i++) 
	{
		web(i); 
		if(DEBUG) cerr<<"END "<<i<<'\n';
	}
	int t; 
	if(!DEBUG) cin>>t;
	else t=ma.size()*ma.size()-1;
	while(t--)
	{
		int a, b; 
		int m1,m2;
		if(!DEBUG)
		{
			cin>>a>>b;
			vi A1 = get(a);
			vi B1 = get(b);
			m1 = ma[A1]; m2 = ma[B1];
		}
		else
		{
			m1=t/ma.size();
			m2=t%ma.size();
		}
		if(m1>m2) swap(m1,m2);
		if(cache[m1][m2]!=-1) {cout<<cache[m1][m2]<<'\n'; continue;}
		int ans=int(1e9);
		for(ii v:D[m1])
		{
			if(D[m2].find(v.fi)!=D[m2].end())
			{
				ans=min(ans,v.se+D[m2][v.fi]);
			}
		}
		cache[m1][m2]=ans;
		//cerr<<"M : "<<m1<<' '<<m2<<'\n';
		//int ans = D[m1][prod(V[m2])];
		//if(D[m2].find(prod(V[m1]))) ans=min(ans,D[m2][prod(V[m1]))
		/*
		if(ans>6&&m1<m2)
		{
			//cerr<<m1<<' '<<m2<<' '<<ans<<'\n';
			V.pb(mp(m1,ans));
		}
		*/
		if(!DEBUG) cout<<ans<<'\n';
	}
	/*
	sort(V.begin(),V.end()); V.erase(unique(V.begin(),V.end()),V.end());
	for(ii x:V)
	{
		F[x.fi]=x.se;
	}
	freopen("familiar.out","w",stdout);
	cout<<"{";
	for(int i=0;i<ma.size();i++)
	{
		cout<<F[i]<<",";
	}
	cout<<"}";
	*/
}