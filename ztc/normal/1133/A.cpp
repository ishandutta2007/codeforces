#include<stdio.h>
int a,b,c,d,e;
main()
{
	a=b=c=d=0;
	while((e=getchar())>='0'&&e<='9')a=a*10+e-'0';
	while((e=getchar())<'0'||e>'9');b+=e-'0';
	while((e=getchar())>='0'&&e<='9')b=b*10+e-'0';
	while((e=getchar())<'0'||e>'9');c+=e-'0';
	while((e=getchar())>='0'&&e<='9')c=c*10+e-'0';
	while((e=getchar())<'0'||e>'9');d+=e-'0';
	while((e=getchar())>='0'&&e<='9')d=d*10+e-'0';
	a=(c*60+d+a*60+b)>>1;c=a/60;a%=60;
	if(c<10)putchar('0');printf("%d:",c);
	if(a<10)putchar('0');printf("%d",a);
}