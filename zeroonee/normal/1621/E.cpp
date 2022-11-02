#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e5+2,M=4e5+2;
int l[M],r[M],s[M],lz[M];
ll sum[N],a[N];
vector<int> b[N];
int p,dt,n;
void build(int x)
{
	s[x]=n-r[x]+1;lz[x]=0;
	if (l[x]==r[x]) return;
	int c=x<<1;
	l[c]=l[x];r[c]=l[x]+r[x]>>1;
	l[c|1]=r[c]+1;r[c|1]=r[x];
	build(c);build(c|1);
}
void mdf(int x)
{
//	if (x==1) cout<<"mdf "<<p<<' '<<dt<<endl;
	if (r[x]<=p)
	{
		lz[x]+=dt;
		s[x]+=dt;
		return;
	}
	int c=x<<1;
	if (lz[x])
	{
		lz[c]+=lz[x];s[c]+=lz[x];c^=1;
		lz[c]+=lz[x];s[c]+=lz[x];c^=1;
		lz[x]=0;
	}
	mdf(c);
	if (p>r[c]) mdf(c|1);
	s[x]=min(s[c],s[c|1]);
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int m,i,j;
		cin>>n>>m;
		for (i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);reverse(a+1,a+n+1);
		n=m;reverse(a+1,a+n+1);
		for (i=1;i<=n;i++)
		{
			int k;cin>>k;
			vector<int> a(k);sum[i]=0;
			for (int &x:a) cin>>x,sum[i]+=x;
			b[i]=a;
		}
		r[l[1]=1]=n;build(1);
		for (i=1;i<=n;i++)
		{
			p=lower_bound(a+1,a+n+1,(sum[i]+b[i].size()-1)/b[i].size())-a-1;dt=-1;
			if (p) mdf(1);
		}
		string ans;
		for (i=1;i<=n;i++)
		{
			p=lower_bound(a+1,a+n+1,(sum[i]+b[i].size()-1)/b[i].size())-a-1;dt=1;
			if (p) mdf(1);
			for (j=0;j<b[i].size();j++)
			{
				p=lower_bound(a+1,a+n+1,(sum[i]-b[i][j]+b[i].size()-2)/(b[i].size()-1))-a-1;dt=-1;
				if (p) mdf(1);
				ans+=(s[1]>0)+'0';
				p=lower_bound(a+1,a+n+1,(sum[i]-b[i][j]+b[i].size()-2)/(b[i].size()-1))-a-1;dt=1;
				if (p) mdf(1);
			}
			p=lower_bound(a+1,a+n+1,(sum[i]+b[i].size()-1)/b[i].size())-a-1;dt=-1;
			if (p) mdf(1);
		}
		cout<<ans<<'\n';
	}
}