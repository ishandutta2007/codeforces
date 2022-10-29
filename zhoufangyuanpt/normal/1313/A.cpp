#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		int ss=0;
		if(a>0)ss++,a--;
		if(b>0)ss++,b--;
		if(c>0)ss++,c--;
		if(a<b)a^=b^=a^=b;
		if(a<c)a^=c^=a^=c;
		if(a>0&&b>0)ss++,a--,b--;
		if(a>0&&c>0)ss++,a--,c--;
		if(b>0&&c>0)ss++,b--,c--;
		if(a>0&&b>0&&c>0)ss++;
		printf("%d\n",ss);
	}
	return 0;
}