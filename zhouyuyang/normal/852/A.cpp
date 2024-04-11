#include<cstdio>
#define MN 200000
char s[MN+5];
int n,u[MN+5];
bool solve()
{
	int i,sm=0,ss=0,sss=0,x,y,a[10],an=0,b[10],bn=0;
	for(i=1;i<=n;++i)if(u[i])sm+=(s[i]-'0')*10+s[i+1]-'0',++i;else sm+=s[i]-'0';
	for(x=sm;sm;sm/=10)ss+=a[++an]=sm%10;
	for(y=ss;ss;ss/=10)sss+=b[++bn]=ss%10;
	if(sss<10)
	{
		for(i=1;i<=n;++i)
		{
			if(i>1)putchar('+');
			putchar(s[i]);
			if(u[i])putchar(s[++i]);
		}
		puts("");
		for(i=an;i>1;--i)printf("%d+",a[i]);printf("%d\n",a[1]);
		for(i=bn;i>1;--i)printf("%d+",b[i]);printf("%d\n",b[1]);
		return false;
	}
	return true;
}
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;solve();)
	{
		for(;s[i]=='0';++i);
		u[i]=1;i+=2;
	}
}