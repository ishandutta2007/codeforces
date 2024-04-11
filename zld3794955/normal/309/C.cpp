#include<bits/stdc++.h>
using namespace std;
inline int getint()
{
	char ch;
	while(!isdigit(ch=getchar())) ;
	int x=ch-'0';
	while(isdigit(ch=getchar())) x=x*10+ch-'0';
	return x;
}
const int B=40,M=1000010;
int n,m,b=30,a[B]={},t[M]={},q[B]={},ans=0;
int main()
{
	n=getint(),m=getint();
	for(int i=1,x;i<=n;++i)
	{
		x=getint();
		for(int j=0;j<=b;++j)
			a[j]+=bool(x&(1<<j));
	}
	for(int i=1;i<=m;++i)
		t[i]=getint(),++q[t[i]];
	for(int i=0,p=0;i<=b;++i)
		for(int j=1;j<=q[i];++j)
			t[++p]=1<<i;
	int p=1;
	for(int i=0;i<=b;++i)
		for(int j=1;j<=a[i];++j)
			for(int s=1<<i; p<=m && t[p]<=s; ++p)
				++ans,s-=t[p];
	printf("%d\n",ans);
	return 0;
}