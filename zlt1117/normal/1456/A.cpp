//#pragma GCC optimize(4)
#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
const int maxn=1e5;
int pre[maxn+5];
int now1[maxn+5];
int T,n,p,k,x,y;
char s[maxn+5];
int main()
{
	cin>>T;
	while(T--)
	{
		for(int i=1;i<=n;++i)pre[i]=0,now1[i]=0;now1[0]=0;
		cin>>n>>p>>k;
		scanf("%s",s+1);
		cin>>x>>y;
		ll ans=2e9;
		for(int i=1;i<=n;++i)now1[i%k]=i;
		for(int i=p;i<=n;++i)
		{
			if(i>=k)pre[i]=pre[i-k];
			pre[i]+=(s[i]=='0');
		}
		for(int i=0;i<=n-p;++i)
		{
			int xx=p+i;
			ll sum=1LL*i*y;
			ll now=pre[now1[xx%k]]-pre[xx];
			if(s[xx]!='1')now++;
			sum+=now*x;
			ans=std::min(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}