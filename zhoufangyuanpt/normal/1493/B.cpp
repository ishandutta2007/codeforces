#include<cstdio>
#include<cstring>
using namespace std;
inline int ref(int x){return x==0?0:x==1?1:x==2?5:x==5?2:x==8?8:114514;}
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int h,m,A,B;scanf("%d%d",&h,&m);
		scanf("%d:%d",&A,&B);
		while(1)
		{
			int a=A/10,b=A%10,c=B/10,d=B%10;
			if(a!=3&&b!=3&&c!=3&&d!=3&&a!=4&&b!=4&&c!=4&&d!=4&&a!=6&&b!=6&&c!=6&&d!=6&&a!=7&&b!=7&&c!=7&&d!=7&&a!=9&&b!=9&&c!=9&&d!=9)
			{
				int aa=ref(d),bb=ref(c),cc=ref(b),dd=ref(a);
				int AA=aa*10+bb,BB=cc*10+dd;
				if(0<=AA&&AA<h&&0<=BB&&BB<m)
				{
					printf("%d%d:%d%d\n",a,b,c,d);
					break;
				}
			}
			B++;
			if(B==m)A++,B=0;
			if(A==h)A=0;
		}
	}
	return 0;
}