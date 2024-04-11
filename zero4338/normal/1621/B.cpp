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
int n;
int l[maxn],r[maxn],c[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)l[i]=read(),r[i]=read(),c[i]=read();
		int nl=1e9+1,nr=0,cl=1e9,cr=1e9,id=0;c[0]=2e9;
		for(int i=1;i<=n;i++)
		{
			if(l[i]==nl)cl=min(cl,c[i]);
			else if(l[i]<nl){nl=l[i];cl=c[i];}
			if(r[i]==nr)cr=min(cr,c[i]);
			else if(r[i]>nr){nr=r[i];cr=c[i];}
			if(l[id]!=nl||r[id]!=nr)id=0;
			if(l[i]==nl&&r[i]==nr&&c[i]<c[id])id=i;
			printf("%d\n",min(c[id],cl+cr));
		}
	}
	return 0;
}