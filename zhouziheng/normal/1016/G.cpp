#include<cstdio>
#include<vector>

using namespace std;

long long my_sqrt(long long x)
{
	long long l=0,r=1e9;
	while(l<r)
	{
		long long mid=(l+r+1)>>1;if(mid*mid<=x)l=mid;else r=mid-1;
	}
	return l;
}

long long a[300000];

long long cnt[2][1<<16];

vector<long long> dv;

long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}

int main()
{
	int n=0;long long x=0,y=0;scanf("%d%lld%lld",&n,&x,&y);
	if(y%x){puts("0");return 0;}
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	long long A=y/x;for(int i=2;i<=1000000;i++)if(A%i==0){dv.push_back(i);while(A%i==0)A/=i;}
	if(A>1)
	{
		long long p=my_sqrt(A);
		if(p*p==A){dv.push_back(p);}
		else
		{
			bool fl=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]%x==0)
				{
					long long p=gcd(a[i],A);
					if(p!=1&&p!=A){dv.push_back(p),dv.push_back(A/p),fl=1;break;}
				}
				if(y%a[i]==0)
				{
					long long p=gcd(y/a[i],A);
					if(p!=1&&p!=A){dv.push_back(p),dv.push_back(A/p),fl=1;break;}
				}
			}
			if(!fl)dv.push_back(A);
		}
	}
	A=y/x;int c=dv.size();
	for(int i=1;i<=n;i++)
	{
		if(a[i]%x==0)
		{
			long long t=gcd(a[i]/x,A);int sta=0;
			for(int j=0;j<c;j++)if(t%dv[j]==0)sta|=(1<<j);
			cnt[0][sta]++;
		}
		if(y%a[i]==0)
		{
			long long t=gcd(y/a[i],A);
			int sta=0;
			for(int j=0;j<c;j++)if(t%dv[j]==0)sta|=(1<<j);
			cnt[1][sta]++;
		}
	}
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<(1<<c);j++)if((j&(1<<i))==0)cnt[0][j|(1<<i)]+=cnt[0][j];
	}
	long long ans=0;
	for(int i=0;i<(1<<c);i++)ans+=(long long)cnt[1][i]*cnt[0][((1<<c)-1)^i];
	printf("%lld\n",ans);
}