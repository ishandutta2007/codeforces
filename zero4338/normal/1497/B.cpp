#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e5+5;	
int n,m,a[maxn],cnt[maxn];
int ans;
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		generate_n(a+1,n,[](){return read()%m;});
		for(int i=0;i<m;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		ans=0;
		if(cnt[0])ans++;
		for(int i=1;i<m;i++)
		{
			if(!cnt[i])continue;
			if(2*i==m)ans++;
			else if(cnt[m-i]==0||2*i<m)ans+=max(0,abs(cnt[i]-cnt[m-i])-1)+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}