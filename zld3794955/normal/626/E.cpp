#include<bits/stdc++.h>
using namespace std;
const int N=200200;
int n,x[N]={};
long long s[N]={};
long long sum=0;
int mid=0,len=0;
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",x+i);
	sort(x+1,x+n+1);
	for(int i=1;i<=n;++i)
		s[i]=s[i-1]+x[i];
	mid=1;
	sum=x[1];
	len=0;
}
bool check(int mid,int len)
{
	long long s1=(x[mid-len]+x[n+1-len])*1ll*(len+len+1);
	long long s2=(s[n]-s[n-len]+s[mid]-s[mid-len-1])*2;
	return s1>=s2;
}
void update(int mid0,int len0)
{
	long long s1=(s[n]-s[n-len]+s[mid]-s[mid-len-1])*(len0+len0+1);
	s1-=x[mid]*1ll*(len0+len0+1)*(len+len+1);
	long long s2=(s[n]-s[n-len0]+s[mid0]-s[mid0-len0-1])*(len+len+1);
	s2-=x[mid0]*1ll*(len0+len0+1)*(len+len+1);
	if(s1<s2)
	{
		sum=(s[n]-s[n-len0]+s[mid0]-s[mid0-len0-1]);
		mid=mid0;
		len=len0;
	}
}
void work()
{
	for(int k=1;k<=n;++k)
	{
		int l=0,r=min(k-1,n-k);
		while(l!=r)
		{
			int mid=(l+r+1)>>1;
			if(check(k,mid))
				l=mid;
			else
				r=mid-1;
		}
		update(k,l);
	}
	printf("%d\n",len*2+1);
	//cout<<"sum="<<sum<<" medium="<<x[mid]<<endl;
	//cout<<"mid="<<mid<<" len="<<len<<endl;
	for(int i=mid-len;i<=mid;++i)
		printf("%d ",x[i]);
	for(int i=n-len+1;i<=n;++i)
		printf("%d ",x[i]);
	printf("\n");
}
int main()
{	
	init();
	work();
	return 0;
}