#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
		long long a,b;scanf("%lld%lld",&a,&b);
		if(a%b!=0){printf("%lld\n",a);continue;}
		long long aa=a;
		long long ss=a;
		for(int i=2;i*i<=b;i++)
		{
			if(b%i==0)
			{
				b=b/i;
				long long s=1;
				int cnt=1,cnt2=0;
				while(b%i==0)b=b/i,cnt++;
				while(a%i==0)a=a/i,cnt2++;
				cnt=cnt2-cnt+1;
				while(cnt--)s=s*i;
				if(s<ss)ss=s;
			}
		}
		if(b>1)
		{
			long long s=1;
			while(a%b==0)a=a/b,s=s*b;
			if(s<ss)ss=s;
		}
		printf("%lld\n",aa/ss);
	}
	return 0;
}