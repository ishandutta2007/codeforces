#include <cstdio>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
int gcd(int x,int y)
{
	int z;
	while (y) z=x%y,x=y,y=z;
	return x;
}
int mu(int x)
{
	int s=1;
	for (int i=2;i*i<=x;++i)
		if (x%i==0)
		{
			if (x%(i*i)==0) return 0;
			s*=-1;
			x/=i;
		}
	if (x>1) s*=-1;
	return s;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("8809.in","r",stdin);
	freopen("8809.out","w",stdout);
#endif
	int a,b,c;
	unsigned ans=0;
	scanf("%d%d%d",&a,&b,&c);
	for (int i=1;i<=a;++i)
		for (int d=1;d<=b&&d<=c;++d)
			if (gcd(i,d)==1)
			{
				int f=mu(d);
				if (f==0) continue;
				int s1=0,s2=0;
				for (int j=1;j<=b/d;++j)
					if (gcd(i,j)==1)
						s1+=b/(d*j);
				for (int j=1;j<=c/d;++j)
					if (gcd(i,j)==1)
						s2+=c/(d*j);
				ans+=(a/i)*f*s1*s2;
			}
	printf("%u\n",ans&((1<<30)-1));
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}