#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int n;
int query(int w){printf("? %d\n",w);fflush(stdout);return read();}
int main()
{
	n=read();
	int l=1,r=4e6+n,sum=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int now=query(mid);
		if(now!=1)l=mid+1;
		else r=mid-1,sum=mid;
	}
	if(!sum)sum=1;
	int ans=sum;
	for(int i=1;i<=n;i++)
	{
		int now=query(sum/i);
		if(now)ans=min(ans,sum/i*now);
	}
	printf("! %d\n",ans);fflush(stdout);
	return 0;
}