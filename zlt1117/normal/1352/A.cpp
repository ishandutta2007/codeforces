#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector> 
#define ll long long
#define ull unsigned long long
using namespace std;///
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
int T,n,pw[]={1,10,100,1000,10000};
int main()
{
	T=getint();
	while(T--)
	{
		n=getint();
		vector<int>v;
		v.clear();
		for(int i=4;i>=0;--i)
		{
			if((n/pw[i])%10)v.push_back((n/pw[i])%10*pw[i]);
		}
		printf("%d\n",v.size());
		for(int i=0;i<v.size();++i)printf("%d ",v[i]);
		printf("\n");
	}
	return 0;
}