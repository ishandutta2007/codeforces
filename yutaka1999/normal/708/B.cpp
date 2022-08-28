#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
typedef long long int ll;

int main()
{
	int A,B,C,D;
	scanf("%d %d %d %d",&A,&B,&C,&D);
	if(A==0&&B==0&&C==0)
	{
		ll z=1;
		while(z*(z-1)/2LL<D) z++;
		if(z*(z-1)/2LL==D)
		{
			for(int i=0;i<z;i++) printf("1");
			puts("");
		}
		else puts("Impossible");
		return 0;
	}
	if(D==0&&B==0&&C==0)
	{
		ll z=1;
		while(z*(z-1)/2LL<A) z++;
		if(z*(z-1)/2LL==A)
		{
			for(int i=0;i<z;i++) printf("0");
			puts("");
		}
		else puts("Impossible");
		return 0;
	}
	ll x=1,y=1;//x:0,y:1
	while(x*(x-1)/2LL<A) x++;
	while(y*(y-1)/2LL<D) y++;
	if(x*(x-1)/2LL!=A||y*(y-1)/2LL!=D||B+C!=x*y)
	{
		puts("Impossible");
		return 0;
	}
	string ret="";
	while(x>0||y>0)
	{
		if(x>0&&B>=y)
		{
			ret+="0";
			x--;
			B-=y;
		}
		else
		{
			ret+="1";
			y--;
			C-=x;
		}
	}
	printf("%s\n",ret.c_str());
	return 0;
}