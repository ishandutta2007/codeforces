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
int count(int x,int pos)
{
	if(x<(1<<pos))return 0;
	int del=x>>(pos+1);
	int ret=del<<pos;
	x=x&((1<<(pos+1))-1);
	return ret+max(0,x+1-(1<<pos));
}
int main()
{
	T=read();
	while(T--)
	{
		int l=read(),r=read();
		int ans=r-l+1;
		for(int i=0;i<28;i++)
			ans=min(ans,r-l+1-count(r,i)+count(l-1,i));
		printf("%d\n",ans);
	}
	return 0;
}