#include<iostream>
#include<cstdio>
#include<cassert>
using namespace std;
const int N=200020,Missing=-1;
long long n,a[N]={},ans=0;
int f[N]={};
void init()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
}
void work()
{
	int pos=1,flag=0,s1=0,s2=0;
	long long now=0,d=0;
	for(int i=1;i<=n;++i)
	{
		if(flag==2)
		{
			if(a[i]==Missing)
			{
				if(now>0)
					now+=d;
				else
				{
					pos=s1+1;
					s1=s2;
					flag=1;
				}
			}
			else
			{
				if(a[i]==now)
				{
					now+=d;
					s1=s2;
					s2=i;
				}
				else
				{
					pos=s1+1;
					s1=s2;
					flag=1;
				}
			}
		}
		if(flag==1 && a[i]!=Missing)
		{
			if((a[s1]-a[i])%(s1-i))
			{
				flag=1;
				pos=s1+1;
				s1=i;
			}
			else
			{
				flag=2;
				d=(a[s1]-a[i])/(s1-i);
				s2=i;
				now=a[i]+d;
				if(d>0)
					pos=max<long long>(pos,s1-(a[s1]-1)/d);
			}
		}
		if(flag==0)
		{
			if(a[i]!=Missing)
			{
				++flag;
				s1=i;
			}
		}
		f[i]=f[pos-1]+1;
		/*
		cout<<"i="<<i<<" flag="<<flag<<" pos="<<pos<<endl;
		if(flag==1)
			cout<<"s1="<<s1<<endl;
		if(flag==2)
			cout<<"s1="<<s1<<" s2="<<s2<<" now="<<now<<" d="<<d<<endl;
		*/
	}
	printf("%d\n",f[n]);
}
int main()
{	
	init();
	work();
	return 0;
}