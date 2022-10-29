#include<cstdio>
#include<cstring>
using namespace std;
inline int mymax(int x,int y){return x>y?x:y;}
int main()
{
	int n;scanf("%d",&n);
	while(n--)
	{
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",mymax(a+b,c+d));
	}
	return 0;
}