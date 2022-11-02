#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e5+2;
int a[N][3],c[N*2];
int minn(int x,int y){return x==0?y:min(x,y);}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while (t--)
	{
		int n,i;cin>>n;vector<int> b;
		int mn=1.1e9,mx=-1;
		map<pair<int,int>,int> mp;
		for (i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2],b.push_back(a[i][0]),b.push_back(a[i][1]);
		sort(all(b));b.resize(unique(all(b))-b.begin());
		for (i=1;i<=n;i++) a[i][0]=lower_bound(all(b),a[i][0])-b.begin()+1;
		for (i=1;i<=n;i++) a[i][1]=lower_bound(all(b),a[i][1])-b.begin()+1;
		for (i=1;i<=b.size();i++) c[i]=1.1e9;
		for (i=1;i<=n;i++)
		{
			mn=min(mn,a[i][0]);mx=max(mx,a[i][1]);
			c[a[i][0]]=min(c[a[i][0]],a[i][2]);
			c[a[i][1]]=min(c[a[i][1]],a[i][2]);
			mp[make_pair(a[i][0],a[i][1])]=minn(mp[make_pair(a[i][0],a[i][1])],a[i][2]);
			cout<<minn(mp[make_pair(mn,mx)],c[mn]+c[mx])<<'\n';
		}
	}
}