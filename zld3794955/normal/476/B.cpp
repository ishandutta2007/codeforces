#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int L=50;
char c1[L]={},c2[L]={};
int n,d=0,q=0;
double p=1,ans=0;
void tryy(int t,int s)
{
	if(t>q)
		ans+=(s==d)*p;
	else
	{
		tryy(t+1,s+1);
		tryy(t+1,s-1);
	}
}
int main()
{
	gets(c1+1);
	gets(c2+1);
	n=strlen(c1+1);
	for(int i=1;i<=n;++i)
		d+=(c1[i]=='+' ? 1 : -1);
	for(int i=1;i<=n;++i)
		c2[i]=='?' ? ++q : (d-=(c2[i]=='+') ? 1 : -1);
	for(int i=1;i<=q;++i)
		p/=2;
	tryy(1,0);
	printf("%.12f\n",ans);
}