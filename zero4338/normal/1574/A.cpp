#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
int n;
void print(int x)
{
	for(int i=1;i<=x;i++)printf("(");
	for(int i=1;i<=x;i++)printf(")");	
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=0;i<n;i++){print(i);print(n-i);printf("\n");}
	}
	return 0;
}