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
const int maxn=1e3+5;
int n;
int con[maxn];
bool judge(int x,int y)
{
	int o1=0,o2=0,bo=0;
	for(int i=1;i<=n;i++)
	{
		if((con[i]&(1<<x))&&(con[i]&(1<<y)))bo++;
		else if(con[i]&(1<<x))o1++;
		else if(con[i]&(1<<y))o2++;
	}
	if(o1+o2+bo<n)return 0;
	if(max(o1,o2)>n/2)return 0;
	return 1;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			con[i]=0;
			for(int j=0;j<5;j++)con[i]|=read()<<j;
		}
		bool flag=0;
		for(int i=0;i<5;i++)
			for(int j=i+1;j<5;j++)
				if(judge(i,j)){flag=1;break;}
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}