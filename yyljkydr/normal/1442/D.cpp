#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=3e3+1e2+7;

int n,k;

vector<int>a[N];

vector<int>f;

void ins(int x)
{
	for(int i=k;i>=a[x].size()-1;i--)
		f[i]=max(f[i],f[i-a[x].size()+1]+a[x].back());
}

int ans;

void solve(int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<=min(k,(int)a[l].size()-1);i++)
			ans=max(ans,f[k-i]+a[l][i]);
		return;
	}
	int mid=(l+r)>>1;
	vector<int>tmp=f;
	for(int i=mid+1;i<=r;i++)
		ins(i);
	solve(l,mid);
	f=tmp;
	for(int i=l;i<=mid;i++)
		ins(i);
	solve(mid+1,r);
}

signed main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
		int t;
		scanf("%lld",&t);
		a[i].resize(t+1);
		for(int j=1;j<=t;j++)
			scanf("%lld",&a[i][j]),a[i][j]+=a[i][j-1];
    }
	f.resize(k+1);
	solve(1,n);
	printf("%lld\n",ans);
}