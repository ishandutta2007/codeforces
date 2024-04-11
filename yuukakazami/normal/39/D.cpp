#include<cstdio>

int x,y,z,xx,yy,zz;

int main()
{
	scanf("%d%d%d%d%d%d",&x,&y,&z,&xx,&yy,&zz);
	if (x==xx || y==yy || z==zz) printf("YES\n");
	else printf("NO\n");
	return 0;
}