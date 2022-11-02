#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
struct Q
{
	int v,p;
	Q(int a,int b):v(a),p(b){}
};
const int N=6e6;
struct trie
{
	int c[N][2],p[N];
	int id;
	trie(){memset(c,0,sizeof c);id=1;}
	void clear()
	{
		for (int i=1;i<=id;i++) c[i][0]=c[i][1]=0;
		id=1;
	}
	void out()
	{
		//for (int i=1;i<=id;i++) cerr<<i<<' '<<c[i][0]<<' '<<c[i][1]<<' '<<p[i]<<endl;
	}
	void ins(int v,int pos)
	{
		int i;
		int x=1;
		for (i=29;i>=0;i--)
		{
			p[x]=pos;
			int o=v>>i&1;
			if (!c[x][o]) c[x][o]=++id;
			x=c[x][o];
		}
		p[x]=pos;
	}
	int ask(int v,int m)
	{
		int x=1,i;
		for (i=29;i>=0&&x;i--)
		{
			int om=m>>i&1,o=(m^v)>>i&1;
			if ((!om)&&c[x][o^1]) return p[c[x][o^1]];
			x=c[x][o];
		}
		return x?p[x]:0;
	}
};
trie s;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,b,i;
	cin>>n>>m;
	if (m==0) {cout<<n<<'\n';for (i=1;i<=n;i++) cout<<i<<" \n"[i==n];return 0;}
	map<int,vector<Q>> mp;
	b=29;while (!(m>>b)) --b;++b;
	for (i=1;i<=n;i++)
	{
		int x;cin>>x;
		mp[x>>b].emplace_back(x,i);
	}
	vector<int> r;--b;
	for (auto &[_,a]:mp)
	{
		//for (auto [v,p]:a) cout<<v<<' ';cout<<endl;
		//for (auto [v,p]:a) cout<<p<<' ';cout<<endl;
		s.clear();
		for (auto [v,p]:a) s.ins(v,p);//s.out();
		int x;
		for (auto [v,p]:a) if (x=s.ask(v,m))
		{
			r.push_back(p);r.push_back(x);goto aa;
		}
		r.push_back(a[0].p);
		aa:;
	}
	if (r.size()<=1) return cout<<"-1\n",0;
	n=r.size();
	cout<<n<<'\n';
	for (i=0;i<n;i++) cout<<r[i]<<" \n"[i==n-1];
}