#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e5+2;
int f[N];
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
struct Q
{
	int u,v,w,f;
	Q(){}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while (t--)
	{
		int n,m,i,j,r=0;
		cin>>n>>m;
		vector<Q> a(m);
		for (auto &[u,v,w,_]:a) cin>>u>>v>>w,_=0;
		//iota(g+1,g+n+1,1);
		for (i=30;i>=0;i--)
		{
			iota(f+1,f+n+1,1);
			for (auto [u,v,w,_]:a) if (!_&&(1^w>>i&1)) f[getf(u)]=getf(v);
			int cnt=0;
			for (j=1;j<=n;j++) if (f[j]==j) ++cnt;
			if (cnt>1) r|=1<<i; else for (auto &[u,v,w,_]:a) if (w>>i&1) _=1;
		}
		cout<<r<<'\n';
	}
}