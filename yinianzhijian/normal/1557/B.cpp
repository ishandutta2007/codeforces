#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
int T,a[xx],lsh[xx],f[xx],n,m,mx[xx<<2];
signed main(){
	T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;i++)a[i]=lsh[i]=read();
		sort(lsh+1,lsh+n+1);
		int s=unique(lsh+1,lsh+n+1)-lsh-1;
		for(int i=1;i<=n;i++)a[i]=lower_bound(lsh+1,lsh+s+1,a[i])-lsh;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i!=n&&a[i+1]==a[i]+1)continue;
			ans++;
		}
		if(ans<=m)puts("Yes");
		else puts("No");
	}
	return 0;
}