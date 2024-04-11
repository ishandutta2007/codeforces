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
int n,k;
tuple<int,int,int>get(int x)
{
	if(x%4==0)return {x/2,x/4,x/4};
	if(x%2==1)return {1,(x-1)/2,(x-1)/2};
	return {2,(x-2)/2,(x-2)/2};
}
void print(tuple<int,int,int>x){printf("%d %d %d ",get<0>(x),get<1>(x),get<2>(x));}
int main()
{
	T=read();
	while(T--)
	{
		n=read();k=read();
		for(int i=1;i<=k-3;i++)printf("1 ");
		print(get(n-k+3));
		printf("\n");
	}
	return 0;
}