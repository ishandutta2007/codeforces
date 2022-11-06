#include<stdio.h>
int x,y,z,a,b,c;
main()
{
	scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
	printf("%s",(x>a||x+y>a+b||x+y+z>a+b+c)?"NO":"YES");
}