#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=3e3+5;
int n,k;
ll ans;
vector<ll>f,a[maxn];
void solve(int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<a[l].size();i++)ans=max(ans,a[l][i]+f[k-i-1]);
		ans=max(ans,f[k]);
		return;
	}
	int mid=(l+r)>>1;
	vector<ll>tmp=f;
	for(int i=mid+1;i<=r;i++)
		for(int j=k;j>=a[i].size();j--)f[j]=max(f[j],f[j-a[i].size()]+a[i].back());
	solve(l,mid);
	f=tmp;
	for(int i=l;i<=mid;i++)
		for(int j=k;j>=a[i].size();j--)f[j]=max(f[j],f[j-a[i].size()]+a[i].back());
	solve(mid+1,r);
}
int main()
{
	n=read();k=read();
	for(int i=1;i<=n;i++)
	{
		a[i].resize(read());generate(a[i].begin(),a[i].end(),read);if(a[i].size()>k)a[i].resize(k);
		for(int j=1;j<a[i].size();j++)a[i][j]+=a[i][j-1];
	}
	f.resize(k+1);
	solve(1,n);
	printf("%lld\n",ans);
	return 0;
}