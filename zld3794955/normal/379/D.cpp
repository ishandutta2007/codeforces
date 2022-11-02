#include<iostream>
#include<cstdio>
using namespace std;
const int L=110;
int k,x,n,m;
char c1[L]={},c2[L]={};
inline int calc(int l1,int l2,bool s1,bool e1,bool s2,bool e2)
{
	int l3=0;
	bool s3=false,e3=false;
	for(int i=3;i<=k;++i)
	{
		l3=l1+l2+(e1 && s2);
		if(l3>x)
			return 0;
		s3=s1,e3=e2;
		l1=l2,l2=l3;
		s1=s2,s2=s3;
		e1=e2,e2=e3;
	}
	return l2;
}
bool check(int l1,int l2,bool s1,bool e1,bool s2,bool e2)
{
	if(l1*2+s1+e1>n || l2*2+s2+e2>m || calc(l1,l2,s1,e1,s2,e2)!=x)
		return false;
	int pos=0;
	if(s1)
		c1[++pos]='C';
	for(int i=1;i<=l1;++i)
		c1[++pos]='A',c1[++pos]='C';
	while(pos!=n)
		c1[++pos]='M';
	if(e1)
		c1[n]='A';
	pos=0;
	if(s2)
		c2[++pos]='C';
	for(int i=1;i<=l2;++i)
		c2[++pos]='A',c2[++pos]='C';
	while(pos!=m)
		c2[++pos]='M';
	if(e2)
		c2[m]='A';
	return true;
}
int main()
{	
	cin>>k>>x>>n>>m;
	for(int s=0;s<16;++s)
		for(int i=0;i<=n/2;++i)
			for(int j=0;j<=m/2;++j)
				if(check(i,j,s&1,s&2,s&4,s&8))
				{
					puts(c1+1),puts(c2+1);
					return 0;
				}
	puts("Happy new year!");
	return 0;
}