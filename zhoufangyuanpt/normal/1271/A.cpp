#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	int ss=0;
	if(c<b)b=c;
	if(e>=f)
	{
		if(a<d)d=d-a,ss=ss+a*e;
		else ss=ss+d*e,d=0;
		a=0;
		e=0;
	}
	else
	{
		if(b<d)d=d-b,ss=ss+b*f;
		else ss=ss+d*f,d=0;
		b=0;
		f=0;
	}
	if(d>0)
	{
		if(a+b<d)ss=ss+(a+b)*(e+f);
		else ss=ss+d*(e+f);
	}
	printf("%d\n",ss);
	return 0;
}