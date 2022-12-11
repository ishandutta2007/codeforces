#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
typedef long long ll;
int main()
{
	int c,v0,v1,a,l;
	scanf("%d%d%d%d%d",&c,&v0,&v1,&a,&l);
	int s=0;
	while(c>0)
	{
		c-=v0;
		s++;
		v0+=a;
		v0=min(v0,v1);
		if(c>0)
			c+=l;
	}
	printf("%d\n",s);
	return 0;
}