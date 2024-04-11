#include<cstdio>
#include<cstring>
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){c=='-'?f=-1:1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x=x*f;
}
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int main()
{
	int t;read(t);
	while(t--)
	{
		int x,y,k;read(x);read(y);read(k);
		int z=gcd(x,y);
		if(x>y)x^=y^=x^=y;
		if((y-z-1)/x+1>=k)puts("REBEL");
		else puts("OBEY");
	}
	return 0;
}