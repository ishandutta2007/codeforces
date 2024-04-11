#include<stdio.h>
#include<map>
using namespace std;
map<long long,long long>ha;
long long ca[100005],cc[100005];
long long a,b,c,w,x,i,j,k,s,ans,d,f;
int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d%",&a,&b,&w,&x,&c);
        d=1;f=1;
	while (a<c)
	{
		s=1;
		ca[1]=a;
		cc[1]=c;
		while (ha[b]==0&&a<c)
		{
			c-=d;
			ha[b]=s;
			s++;
			if (b>=x)
			b-=x;
			else
			{
				a-=f;
				b=b-x+w;
			}
			ca[s]=a;
			cc[s]=c;
		}
		int yy=s-ha[b];
		int q=ca[ha[b]]-ca[s];
		int qq=cc[ha[b]]-cc[s];
		ans=s-1;
		if (c<=a)
		break;
		long long l=0,r=100000000000ll;
		while (l<=r)
		{
			long long mid=(l+r)>>1;
			if ((a-q*mid)>=((c-qq*mid)))
			r=mid-1;
			else
			l=mid+1;
		}
		a=a-q*r;
		c=c-qq*r;
		ans=ans+yy*r;
		a=a+q;
		c=c+qq;
		ans=ans-yy;
		while (a<c)
		{
			ans++;
			c-=d;
			if (b>=x)
			b-=x;
			else
			{
				a-=f;
				b=b+w-x;
			}
		}
	}
	printf("%I64d\n",ans);
}