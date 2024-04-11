#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#define ll long long
#define ull unsigned long long
using namespace std;
inline int getint()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
const int maxn=1e6;
int minv[maxn+5];
bool ok[maxn+5];
int n,T,k;
inline int min(int a,int b){return a<b?a:b;}
inline void get_table()
{
	minv[1]=1;
	for(int i=2;i<=maxn;++i)
	{
		if(!ok[i])
		{
			for(int j=2;i*j<=maxn;++j)
			{
				ok[i*j]=true;
				minv[i*j]=min(minv[i*j],i);
			}
			minv[i]=i;
		}
	}
}
int main()
{
	memset(minv,0x3f,sizeof(minv));
	T=getint();
	get_table();
	while(T--)
	{
		n=getint(),k=getint();
		if(n%2)
		{
			k--;
			n+=minv[n];
		}
		printf("%d\n",n+2*k);
	}
	return 0;
}