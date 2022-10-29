//luogu
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,xx,yy;scanf("%d%d%d",&n,&xx,&yy);
	int s=0,x=0,z=0,y=0;
	for(int i=1;i<=n;i++)
	{
		int xi,yi;scanf("%d%d",&xi,&yi);
		if(yi>yy)s++;
		if(yi<yy)x++;
		if(xi<xx)z++;
		if(xi>xx)y++;
	}
	if(s>=x&&s>=z&&s>=y&&yy!=1000000000)printf("%d\n%d %d\n",s,xx,yy+1);
	else if(x>=s&&x>=z&&x>=y&&yy!=0)printf("%d\n%d %d\n",x,xx,yy-1);
	else if(z>=s&&z>=x&&z>=y&&xx!=0)printf("%d\n%d %d\n",z,xx-1,yy);
	else printf("%d\n%d %d\n",y,xx+1,yy);
	return 0;
}