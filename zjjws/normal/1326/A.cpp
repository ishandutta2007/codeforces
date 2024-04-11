#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL rin()
{
    LL s=0;
    bool bj=0;
    char c=getchar();
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')bj=1,c=getchar();
    while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^'0'),c=getchar();
    if(bj)return -s;
    return s;
}
int main()
{
    int i,j;
    int t;
	for(t=rin();t>0;t--)
	{
		int n=rin();
		if(n==1)printf("-1\n");
		else
		{
			int a,b;
			b=1;a=n-1;
			while(((a<<1)+b*3)%3==0&&a>0)a--,b++;
			//if(a==0)printf("-1\n");
			//else
			//{
				for(i=1;i<=a;i++)printf("2");
				for(i=1;i<=b;i++)printf("3");
				printf("\n");
			//}
		}
	 } 
    return 0;
}