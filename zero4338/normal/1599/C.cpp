#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e3+5;
int n;double p;
double C(int n,int m)
{
	double ret=1;
	for(int i=n;i>=n-m+1;i--)ret*=i;
	for(int i=1;i<=m;i++)ret/=i;
	return ret;
}
double calc(int x){return C(x,3)/C(n,3)+(n-x)*C(x,2)/C(n,3)+C(n-x,2)*x/C(n,3)/2;}
int main()
{
	n=read();scanf("%lf",&p);
	int l=0,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		double v=calc(mid);
		if(v>=p)ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}