#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[110000],b[110000];
inline bool cmp(int x,int y){return x>y;}
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		for(int i=2;i<=n;i++)a[i]+=a[i-1];
		for(int i=2;i<=n;i++)b[i]+=b[i-1];
		int l=0,r=n*3;
		while(l<r)
		{
			int mid=(l+r)/2;
			int k=n+mid;
			int s=k-k/4;
			int sa,sb;
			if(s<=mid)sa=100*s;
			else sa=100*mid+a[s-mid];
			if(s<=n)sb=b[s];
			else sb=b[n];
			if(sa<sb)l=mid+1;
			else r=mid;
		}
		printf("%d\n",r);
	}
	return 0;
}