#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#define ll long long
#define ull unsigned long long
using namespace std;
inline long long getint()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?x:-x;
}
long long T,p1,p2,k;
int main()
{
//	freopen("color.in","r",stdin);
//  freopen("color.out","w",stdout);
	T=getint();
	while(T--)
	{
		p1=getint(),p2=getint(),k=getint();
		int gcd=__gcd(p1,p2);
		p1/=gcd,p2/=gcd;
		if(p1<p2)swap(p1,p2);
		if(p1==p2&&k!=1)printf("OBEY\n");
		else if(k==1)printf("REBEL\n");
		else if(p1%p2==0&&p1/p2>k)printf("REBEL\n");
		else if(p1%p2==0&&p1/p2<=k)printf("OBEY\n");
		else
		{
			int now=(p1-2)/p2+1;
			if(now>=k)printf("REBEL\n");
			else printf("OBEY\n");
		}
	}
	return 0;
}