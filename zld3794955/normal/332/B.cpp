#include<bits/stdc++.h>
using namespace std;
const int N=200020;
int n,k,a[N]={},l[N]={},r[N]={};
long long s[N]={};
int main()
{	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		s[i]=s[i-1]+a[i];
	l[k]=1;
	for(int i=k+1;i<=n;++i)
		if(s[i]-s[i-k]>s[l[i-1]+k-1]-s[l[i-1]-1])
			l[i]=i-k+1;
		else
			l[i]=l[i-1];
	r[n-k+1]=n-k+1;
	for(int i=n-k;i>=1;--i)
		if(s[i+k-1]-s[i-1]>=s[r[i+1]+k-1]-s[r[i+1]-1])
			r[i]=i;
		else
			r[i]=r[i+1];
	long long ans=0;
	int pos=0;
	for(int i=k;i<=n-k;++i)
		if(s[l[i]+k-1]-s[l[i]-1]+s[r[i+1]+k-1]-s[r[i+1]-1]>ans)
		{
			ans=s[l[i]+k-1]-s[l[i]-1]+s[r[i+1]+k-1]-s[r[i+1]-1];
			pos=i;
		}
	printf("%d %d\n",l[pos],r[pos+1]);
	return 0;
}